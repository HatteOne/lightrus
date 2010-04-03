/*******************************************************************************

    Project Lightrus
    
    Copyright (C) 2009 Sergey Balyakin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
*******************************************************************************/

#include "model.h"
#include "translator.h"
#include "infocollector.h"
#include "modelhelper.h"
#include "constants.h"
#include <QApplication>
#include <QClipboard>

using namespace consts;

Model::Model()
    : translator(new Translator),
    model_helper(new ModelHelper)
{
    connect(translator, SIGNAL(SendLogMessage(const QString&)),        SIGNAL(SendLogMessage(const QString&)));
    connect(translator, SIGNAL(SendInfoMessage(const QString&)),       SIGNAL(SendInfoMessage(const QString&)));
    connect(translator, SIGNAL(SendErrorMessage(const QString&)),      SIGNAL(SendErrorMessage(const QString&)));
    connect(translator, SIGNAL(StartNewFileTranslate(const QString&)), SIGNAL(StartNewFileTranslate(const QString&)));
    connect(translator, SIGNAL(CurrentFileProgressChanged(int)),       SIGNAL(CurrentFileProgressChanged(int)));

    connect(model_helper, SIGNAL(SendLogMessage(const QString&)),   SIGNAL(SendLogMessage(const QString&)));
    connect(model_helper, SIGNAL(SendInfoMessage(const QString&)),  SIGNAL(SendInfoMessage(const QString&)));
    connect(model_helper, SIGNAL(SendErrorMessage(const QString&)), SIGNAL(SendErrorMessage(const QString&)));
}

Model::~Model()
{
    delete translator;
    delete model_helper;
}

void Model::Translate(const QString& lightroom_path,
               const QString& language_abb,
               bool is_need_backup)
{
    translator->TranslateAll( res_path_russian_dictionary, res_path_english_exclusions, lightroom_path, language_abb, is_need_backup );
}

void Model::CopyEnglishHelpFiles(const QString& lightroom_path,
                                 const QString& language_abb,
                                 bool is_need_backup)
{
    emit SendLogMessage(text_copying_help_files);
    model_helper->CopyEnglishHelpFiles(lightroom_path, language_abb, is_need_backup);
}

QString Model::GetDefaultLightroomPath()
{
    return InfoCollector::GetLightroomInstallDir();
}

bool Model::IsValidLightroomPath(const QString& path)
{
    return InfoCollector::IsValidLightroomDir(path);
}

void Model::OpenReadmeFile(const QString& lightroom_path)
{
    model_helper->OpenReadmeFile(lightroom_path);
}

#ifdef Q_WS_WIN
void Model::ToggleLanguageToSelected(const QString& language_abb)
{
    model_helper->ToggleLanguageToSelected(language_abb);
}
#endif

#ifdef Q_WS_MAC
void Model::ToggleLanguageToRussian(const QString& lightroom_path)
{
    model_helper->ToggleLanguageToRussian(lightroom_path);
}
#endif

void Model::ExecLightroom(const QString& lightroom_path)
{
    model_helper->ExecLightroom(lightroom_path);
}

void Model::RefreshLanguagesList(const QString& lightroom_path)
{
    InfoCollector::GetLanguagesList(lightroom_path, languages);
}

QString Model::GetLanguageAbb(const QString& language_name)
{
    return languages.key(language_name, QString());
}

QString Model::GetLanguageName(const QString& language_abb)
{
    return languages.value(language_abb, QString());
}

QStringList Model::GetLanguagesNames()
{
    QStringList result;

    for (Dictionary::iterator iter = languages.begin(); iter != languages.end(); ++iter)
        result.append(iter.value());

    return result;
}

void Model::BuildMailText(QStringList& text)
{
    text.clear();
    text.append(text_os_version_s.arg(InfoCollector::GetOSVersion()));
    text.append(text_os_word_size_d.arg(InfoCollector::GetWordSize()));
    text.append(text_application_version_s.arg(application_version));
    text.append(text_lightroom_path_s.arg(translator->GetLightroomPath()));
    text.append(text_language_abb_ss.arg(translator->GetLanguageAbb(), GetLanguageName(translator->GetLanguageAbb())));
    text.append(text_unknown_phrases_count_d.arg(translator->GetUnknownKeysCount()));

    QStringList keys = translator->GetUnknownKeys();
    foreach (QString key, keys)
        text.append(key);
}

void Model::SendTranslatingStats()
{
    translator->SendTranslatingStats();
}

void Model::CopyToClipboard(const QString& text)
{
    qApp->clipboard()->setText(text);
}

void Model::CopyReadmeFile(const QString& lightroom_path)
{
    model_helper->CopyReadmeFile(lightroom_path);
}

bool Model::IsUnknownPhrasesAvailable()
{
    return translator->GetUnknownKeysCount() != 0;
}
