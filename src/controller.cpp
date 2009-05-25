#include "controller.h"
#include "maindialog.h"
#include "model.h"
#include "constants.h"
#include <QDir>

Controller::Controller(MainDialog* _view, Model* _model)
    : view(_view), model(_model)
{
    // Связи с видом
    connect(view, SIGNAL(Translate()),                            SLOT(Translate()));
    connect(view, SIGNAL(SetDefaultLightroomPath()),              SLOT(SetDefaultLightroomPath()));
    connect(view, SIGNAL(CollectUnknownPhrases()),                SLOT(CollectUnknownPhrases()));
    connect(view, SIGNAL(ChangeLightroomDirPath(const QString&)), SLOT(ChangeLightroomDirPath(const QString&)));
    connect(view, SIGNAL(OpenReadmeFile()),                       SLOT(OpenReadmeFile()));
    connect(view, SIGNAL(ToggleLanguageToSelected()),             SLOT(ToggleLanguageToSelected()));
    connect(view, SIGNAL(ExecLightroom()),                        SLOT(ExecLightroom()));
    connect(view, SIGNAL(CopyToClipboard(const QString&)),        SLOT(CopyToClipboard(const QString&)));
    connect(view, SIGNAL(IsPageNotTranslatedNeeded(bool&)),       SLOT(IsPageNotTranslatedNeeded(bool&)));

    // Связи с моделью
    connect(model, SIGNAL(SendLogMessage(const QString&)),        SLOT(OnLogMessage(const QString&)));
    connect(model, SIGNAL(SendInfoMessage(const QString&)),       SLOT(OnInfoMessage(const QString&)));
    connect(model, SIGNAL(SendErrorMessage(const QString&)),      SLOT(OnErrorMessage(const QString&)));
    connect(model, SIGNAL(StartNewFileTranslate(const QString&)), SLOT(StartNewFileTranslate(const QString&)));
    connect(model, SIGNAL(CurrentFileProgressChanged(int)),       SLOT(CurrentFileProgressChanged(int)));
}

void Controller::Start()
{
    view->show();
}

void Controller::Translate()
{
    // Перевод файлов
    model->Translate( GetLightroomPath(), GetLanguageAbb(), IsNeedBackup() );

#ifdef Q_WS_WIN
    // В версии для Windows английские файлы помощи копируются вместо файлов помощи заданного языка
    // Копирование файлов помощи
    if (IsNeedCopyEnglishHelpFiles())
        model->CopyEnglishHelpFiles( GetLightroomPath(), GetLanguageAbb(), IsNeedBackup() );
#endif

#ifdef Q_WS_MAC
    // В версии для Mac OS английские файлы помощи копируются вместо файлов помощи русского языка
    // Копирование файлов помощи
    if (IsNeedCopyEnglishHelpFiles())
        model->CopyEnglishHelpFiles( GetLightroomPath(), consts::str_russian_abb, IsNeedBackup() );
#endif

    // Копирование readme-файла
    model->CopyReadmeFile( GetLightroomPath() );

    // Вывод результатов перевода
    model->SendTranslatingStats();
}

void Controller::SetDefaultLightroomPath()
{
    QString path = model->GetDefaultLightroomPath();
    view->SetLightroomPath(path);
}

void Controller::ChangeLightroomDirPath(const QString& path)
{
    model->RefreshLanguagesList(path);
    view->SetIsValidLightroomPath( model->IsValidLightroomPath(path) );

    QStringList languages = model->GetLanguagesNames();
    view->SetLanguagesNames(languages);
}

void Controller::OpenReadmeFile()
{
    model->OpenReadmeFile(GetLightroomPath());
}

void Controller::ToggleLanguageToSelected()
{
#ifdef Q_WS_WIN
    // В Windows-версии переключение на русский язык производится переключением на выбранный язык
    model->ToggleLanguageToSelected(GetLanguageAbb());
#endif

#ifdef Q_WS_MAC
    // В Mac-версии переключение на русский язык производится принудительным переключением на русский
    QString lightroom_path = view->GetLightroomPath();
    model->ToggleLanguageToRussian(lightroom_path);
#endif
}

void Controller::ExecLightroom()
{
    model->ExecLightroom(GetLightroomPath());
}

QString Controller::GetLightroomPath()
{
    return view->GetLightroomPath();
}

QString Controller::GetLanguageAbb()
{
    QString language_name = view->GetSelectedLanguageName();
    return model->GetLanguageAbb(language_name);
}

bool Controller::IsNeedBackup()
{
    return view->IsNeedBackup();
}

bool Controller::IsNeedCopyEnglishHelpFiles()
{
    return view->IsNeedCopyEnglishHelpFiles();
}

void Controller::OnLogMessage(const QString& text)
{
    view->OnLogMessage(text);
}

void Controller::OnInfoMessage(const QString& text)
{
    view->OnInfoMessage(text);
}

void Controller::OnErrorMessage(const QString& text)
{
    view->OnErrorMessage(text);
}

void Controller::CollectUnknownPhrases()
{
    QStringList text;
    model->BuildMailText(text);
    view->SetMailText(text);
}

void Controller::StartNewFileTranslate(const QString& file_name)
{
    view->SetTranslatingFilename(QDir::toNativeSeparators(file_name));
}

void Controller::CurrentFileProgressChanged(int value)
{
    view->SetProgress(value);
}

void Controller::CopyToClipboard(const QString& text)
{
    model->CopyToClipboard(text);
}

void Controller::IsPageNotTranslatedNeeded(bool& is_need)
{
    is_need = model->IsUnknownPhrasesAvailable();
}
