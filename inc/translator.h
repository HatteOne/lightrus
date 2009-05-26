/*******************************************************************************

    Project Lightrus
    
    Класс переводчика
    
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

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "logobject.h"
#include <QString>
#include <QStringList>
#include <QHash>
#include <QMap>
#include <QSet>
#include <QByteArray>

class Translator : public LogObject
{
    Q_OBJECT

signals:
    void StartTranslating();                    // Сигнал начала перевода
    void FinishTranslating();                   // Сигнал окончания перевода
    void StartNewFileTranslate(const QString&); // Сигнал начала перевода нового файла. Параметром является имя данного файла
    void CurrentFileProgressChanged(int);       // Сигнал изменения прогресса перевода текущего файла. Параметром является процент прогресса

public:
    Translator();

    // Переводит все строковые ресурсы заданного языка (при помощи
    // аббревиатуры lang_abb) и возвращает количество не переведенных фраз.
    void TranslateAll(const QString& rus_dict_file_name,
                      const QString& eng_exclusions_file_name,
                      const QString& _lightroom_path,
                      const QString& lang_abb,
                      bool make_backup);

    int GetUnknownKeysCount() { return unknown_phrases.size(); }
    QString GetLightroomPath() { return lightroom_path; }
    QString GetLanguageAbb() { return language_abb; }
    QStringList GetUnknownKeys();
    void SendTranslatingStats();

private:
    typedef QMap<QString, QString> Dictionary;
    QString lightroom_path;
    QString language_abb;
    bool make_backup;
    Dictionary exclusions; // Список фраз, не требующих перевода
    Dictionary eng_exclusions; // Список фраз, требующих поиска их английского значения
    Dictionary rus_dic; // Русский словарь фраз
    Dictionary eng_dic; // Английский словарь фраз
    Dictionary unknown_phrases; // Неизвестные фразы

    // Переводит заданный лексический файл и сохраняет результат перевода
    // in_file_name - имя исходного файла для перевода
    // out_file_name - имя переведенного файла, для сохранения результата
    void TranslateFile(const QString& in_file_name, const QString& out_file_name);

    // Добавляет новый ключ к списку неизвестных ключей
    void AddUnknownKey(const QString& key, const QString& value);
    void UpdateUnknownKey(const QString& key, const QString& value);
    void ClearUnknownKeys();

    // Производит поиск английского значения ключа
    QString FindEngDicEntryValue(const QString& key);

    // Находит значение ключа key в словаре. Возвращает true в случае успешного поиска.
    QString FindRusDicEntryValue(const QString& key);

    // Парсит файл с фразами и помещает их в словарь dic
    void ParseTranslatedStringsFile(const QString& file_name, Dictionary& dic);

    // Парсит бинарный файл локализации и добавляет полученные фразы в словарь dic
    void ParseBinaryLangFile(const QString& file_name, Dictionary& dic);

    // Заполняет словарь лингвистическими данными, исходя из аббревиатуры языка
    void FillLangDictionary(const QString& lightroom_dir, const QString& lang_abb, Dictionary& dictionary);

    // Подготавливает русский словарь фраз
    void PrepareRusDictionary(const QString& dic_file_name);
    // Подготавливает английский словарь фраз
    void PrepareEngDictionary();
    // Подготавливает список исключений
    void PrepareExclusions(const QString& exclusions_file_name);
    // Подготавливает список обязательных английских фраз
    void PrepareEngExclusions(const QString& eng_exclusions_file_name);

    bool ParseKeyValueString(const QString& str, QString& key, QString& value, QString& before, QString& after);
    bool ParseKeyValueString(const QString& str, QString& key, QString& value);

    QByteArray FormatStringToWrite(const QString& key, const QString& value, const QString& before = "", const QString& after = "");

    int CalcProgressPercent(int current, int overall);

    // Обновление системных событий
    void ProcessEvents();
};

#endif // TRANSLATOR_H
