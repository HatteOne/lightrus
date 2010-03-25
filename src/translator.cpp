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

#include "translator.h"
#include <QFile>
#include <QTemporaryFile>
#include <QDir>
#include <QByteArray>
#include <QStringList>
#include <QApplication>
#include <QLocale>
#include <QtGlobal>
#include "constants.h"
#include "infocollector.h"

using namespace consts;

Translator::Translator()
{
    make_backup = false;
}

void Translator::ParseTranslatedStringsFile(const QString& file_name, Dictionary& dic)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        DoError(err_text_fail_to_open_file_s.arg(QDir::toNativeSeparators(file_name)));
        return;
    }

    QByteArray line_data;
    QString key, value;

    for (;;)
    {
        line_data = file.readLine();
        if (line_data.isEmpty())
            break;

        if (ParseKeyValueString(QString::fromUtf8(line_data), key, value))
            dic.insert(key, value);
    }
}

void Translator::PrepareRusDictionary(const QString& dic_file_name)
{
    rus_dic.clear();
    ParseTranslatedStringsFile(dic_file_name, rus_dic);
}

void Translator::PrepareEngDictionary()
{
    FillLangDictionary(lightroom_path, str_english_abb, eng_dic);
}

void Translator::PrepareExclusions(const QString& exclusions_file_name)
{
    exclusions.clear();
    ParseTranslatedStringsFile(exclusions_file_name, exclusions);
}

void Translator::PrepareEngExclusions(const QString& eng_exclusions_file_name)
{
    eng_exclusions.clear();
    ParseTranslatedStringsFile(eng_exclusions_file_name, eng_exclusions);
}


bool Translator::ParseKeyValueString(const QString& str, QString& key, QString& value, QString& before, QString& after)
{
    // Парсит строку словаря вида:
    // "ключ=значение"

    int first_quotes_index = str.indexOf(char_quote);
    int last_quotes_index = str.lastIndexOf(char_quote);
    int assign_index = str.indexOf(char_assign);

    if (first_quotes_index == -1 || last_quotes_index <= first_quotes_index || assign_index == -1 ||
       !(assign_index > first_quotes_index && assign_index < last_quotes_index))
        return false;

    key    = str.mid(first_quotes_index + 1, assign_index - first_quotes_index - 1);
    value  = str.mid(assign_index + 1, last_quotes_index - assign_index - 1);
    before = str.left(first_quotes_index);
    after  = str.right(str.size() - last_quotes_index - 1);
    return true;
}

bool Translator::ParseKeyValueString(const QString& str, QString& key, QString& value)
{
    QString before, after;
    return ParseKeyValueString(str, key, value, before, after);
}

QString Translator::FindRusDicEntryValue(const QString& key)
{
    Dictionary::const_iterator iter = rus_dic.find(key);
    return (iter == rus_dic.end()) ? QString() : iter.value();
}

QString Translator::FindEngDicEntryValue(const QString& key)
{
    Dictionary::const_iterator iter = eng_dic.find(key);
    return (iter == eng_dic.end()) ? QString() : iter.value();
}

void Translator::TranslateFile(const QString& in_file_name, const QString& out_file_name)
{
    QString native_in_file_name = QDir::toNativeSeparators(in_file_name);
    // Сигнализируем о начале перевода файла
    DoLog(text_translating_file_s.arg(native_in_file_name));
    emit StartNewFileTranslate(in_file_name);


    QFile file(in_file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        DoError(err_text_fail_to_open_file_s.arg(native_in_file_name));
        return;
    }

    // Переводим все во временный файл, т.к. выходной файл out_file_name
    // может быть тем же самым файлом, что и in_file_name
    QTemporaryFile tmp_file;
    if (!tmp_file.open())
    {
        DoError(err_text_fail_to_create_temporary_file);
        return;
    }

    // Подсчитываем количество строк в файле
    int file_size = file.size();
    int curr_progress;

    QByteArray str_data;
    QString key, value, before, after, translated_value;

    do
    {
        // Подсчитываем прогресс перевода в процентах и сигнализируем об этом
        str_data = file.readLine();
        curr_progress = CalcProgressPercent(file.pos(), file_size);
        emit CurrentFileProgressChanged(curr_progress);
        ProcessEvents();

        if ( ParseKeyValueString(QString::fromUtf8(str_data), key, value, before, after) )
        {
            // Для ключа требуется обязательное английское значение
            if (eng_exclusions.contains(key))
            {
                translated_value = FindEngDicEntryValue(key);
                if (translated_value.isEmpty()) // английского варианта не нашли
                    tmp_file.write(str_data);
                else
                    tmp_file.write( FormatStringToWrite(key, translated_value, before, after) );
                continue;
            }

            // Ищем русский перевод ключа
            translated_value = FindRusDicEntryValue(key);
            if (translated_value.isEmpty()) // В словаре такой фразы нет
            {
                // Пытаемся найти данную фразу в английском варианте
                translated_value = FindEngDicEntryValue(key);
                if (translated_value.isEmpty()) // английского варианта также не нашли
                    tmp_file.write(str_data);
                else // нашли
                    tmp_file.write( FormatStringToWrite(key, translated_value, before, after) );

                if (translated_value.isEmpty())
                    AddUnknownKey(key, value);
                else
                    AddUnknownKey(key, translated_value);
            }
            else
                tmp_file.write( FormatStringToWrite(key, translated_value, before, after) );
        }
        else
            tmp_file.write(str_data);
    } while ( !file.atEnd() );

    file.close();

    QFile out_file(out_file_name);

    // Создаем резевную копию если необходимо
    if (QFile::exists(out_file_name)) // Есть, что заменять
    {
        if (make_backup) // Задана опция резервного копирования
        {
            QString backup_file_name = out_file_name + str_backup_postfix;
            QFile backup_file(backup_file_name);

            if (backup_file.exists())
                if (!backup_file.remove())
                    DoError(err_text_fail_to_remove_file_sds.arg(QDir::toNativeSeparators(backup_file_name)).arg(backup_file.error()).arg(backup_file.errorString()));

            if (!out_file.rename(backup_file_name))
                DoError(err_text_fail_to_rename_file_from_to_ssds.arg(QDir::toNativeSeparators(out_file_name), QDir::toNativeSeparators(backup_file_name)).arg(out_file.error()).arg(out_file.errorString()));
        }
        else // Или просто удаляем оригинал
        {
            if (!out_file.remove())
                DoError(err_text_fail_to_remove_file_sds.arg(QDir::toNativeSeparators(out_file_name)).arg(out_file.error()).arg(out_file.errorString()));
        }
    }

    // Создаем директорию целевого файла, если это необходимо
    QString out_path = QFileInfo(out_file_name).absolutePath();
    QDir out_dir;
    if (!out_dir.exists(out_path))
        out_dir.mkpath(out_path);

    // Копируем из временного файла в конечный
    if (!tmp_file.copy(out_file_name))
        DoError(err_text_fail_to_copy_file_sds.arg(QDir::toNativeSeparators(out_file_name)).arg(tmp_file.error()).arg(tmp_file.errorString()));
}

void Translator::TranslateAll(const QString& rus_dic_file_name,
                              const QString& eng_exclusions_file_name,
                              const QString& _lightroom_path,
                              const QString& lang_abb,
                              bool _make_backup)
{
    emit StartTranslating();

    lightroom_path = _lightroom_path;
    language_abb = lang_abb;
    make_backup = _make_backup;

    if (!QFile::exists(rus_dic_file_name))
        qFatal("Заданный словарный файл не найден");

    DoLog(text_prepare_dictionaries);


    // Подготовка словарей и исключений
    PrepareRusDictionary(rus_dic_file_name);
    PrepareEngDictionary();
    PrepareEngExclusions(eng_exclusions_file_name);

    // Находим файлы для перевода
    QStringList files;
    QString file;
    InfoCollector::FindTranslatedStringsFiles(lightroom_path, lang_abb, files);

#ifdef Q_WS_WIN
    // Переводим каждый файл
    foreach (file, files)
        TranslateFile(file, file);
#endif

#ifdef Q_WS_MAC
    // Опредляем соотвествующие имена файлов для русских лексических файлов
    QStringList out_files;
    InfoCollector::SpecifyRusTranslatedStringsFiles(lang_abb, files, out_files);

    Q_ASSERT_X(files.size() == out_files.size(), "Translator::TranslateAll", "In and out lists' sizes is not equal.");

    // Переводим каждый файл
    for (int i = 0; i < files.size(); ++i)
        TranslateFile(files[i], out_files[i]);
#endif

    emit FinishTranslating();
}

void Translator::AddUnknownKey(const QString& key, const QString& value)
{
    unknown_phrases.insert(key, value);
}

void Translator::ClearUnknownKeys()
{
    unknown_phrases.clear();
}

void Translator::UpdateUnknownKey(const QString& key, const QString& value)
{
    unknown_phrases[key] = value;
}

QByteArray Translator::FormatStringToWrite(const QString& key, const QString& value, const QString& before, const QString& after)
{
    return (before + str_quote + key + str_assign + value + str_quote + after).toUtf8();
}

inline int Translator::CalcProgressPercent(int current, int overall)
{
    if (overall <= 1) return 0;
    return static_cast<int>(current * 100.0 / (overall - 1));
}

void Translator::ProcessEvents()
{
    qApp->processEvents();
}

QStringList Translator::GetUnknownKeys()
{
    QStringList result;

    Dictionary::iterator iter = unknown_phrases.begin();
    for (;iter != unknown_phrases.end(); ++iter)
        result.append( FormatStringToWrite(iter.key(), iter.value()) );

    return result;
}

void Translator::SendTranslatingStats()
{
    if (GetUnknownKeysCount() != 0)
        DoInfo( text_unknown_phrases_found_d.arg(GetUnknownKeysCount()) );
    DoInfo(text_translating_finished);
}

void Translator::FillLangDictionary(const QString& lightroom_dir, const QString& lang_abb, Dictionary& dictionary)
{
    dictionary.clear();

    // Сначала ищем фразы в файлах TranslatedStrings.txt
    QStringList tr_files;
    InfoCollector::FindTranslatedStringsFiles(lightroom_dir, lang_abb, tr_files);

    // Добавляем из каждого файла фразы в словарь
    foreach (QString tr_file, tr_files)
        ParseTranslatedStringsFile(tr_file, dictionary);


    // Ищем английские фразы в бинарных файлах
    QStringList files;

#ifdef Q_WS_WIN
    InfoCollector::FindFiles(lightroom_dir, QStringList(str_all_files_filter), false, files);
#endif

#ifdef Q_WS_MAC
    InfoCollector::FindFiles(lightroom_dir, QStringList(str_lua_files_filter), true, files);
#endif

    foreach (QString file, files)
        ParseBinaryLangFile(file, dictionary);
}

void Translator::ParseBinaryLangFile(const QString& file_name, Dictionary& dic)
{
    QFile file(file_name);

    if (!file.open(QIODevice::ReadOnly))
    {
        DoError(err_text_fail_to_open_file_s.arg(QDir::toNativeSeparators(file_name)));
        return;
    }

    QByteArray data = file.readAll();

    QString key;
    QString value;
    int key_start_index = 0;
    bool is_special_char = false;
    char ch;

    for(;;)
    {
        // Определяем идентификатор (ключ) фразы словаря -----------------------

        // Ищем подходящее начало для названия ключа ($$$/)
        key_start_index = data.indexOf(str_phrase_prefix, key_start_index);
        if (key_start_index == -1)
            break;

        key = str_phrase_prefix;
        key_start_index += str_phrase_prefix.size();
        int cur_index = key_start_index;

        for (; cur_index < data.size(); ++cur_index)
        {
            ch = data[cur_index];
            if (str_phrase_id_chars.contains(ch)) // Если символ подходит , то добавляем его в идентификатор ключа
            {
                key += ch;
                continue;
            }

            if (ch == char_assign) // Знак равенства означает конец названия ключа
            {
                ++cur_index; // Пропускаем знак равенства
                break;
            }

            // Если мы наткнулись на неподходящий символ, то значит, что это был не ключ
            cur_index = key_start_index;
            break;
        }

        if (cur_index == key_start_index) // Это значит, что название ключа определить не удалось
            continue;

        // Определяем значение фразы -------------------------------------------

        value.clear();
        is_special_char = false;

        for (;cur_index < data.size(); ++cur_index)
        {
            ch = data[cur_index];

            if (is_special_char) // Специальный символ
            {
                value += ch;
            }
            else
            {
                if (ch == char_zero || ch == char_quote) // Знаки окончания строки
                    break;

                is_special_char = ch == char_back_slash;
                value += ch;
            }
        }

        // Смещаем начало поиска следющей фразы за пределы текущей фразы
        key_start_index = cur_index + 1;

        // Заменяем фактические знаки переноса строки на их обозначение (\n)
        value.replace(str_return, str_return_replace);

        // Добавляем все полученное добро в словарь
        dic.insert(key, value);
    }
}
