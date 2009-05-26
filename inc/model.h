/*******************************************************************************

    Project Lightrus
    
    Класс модели данных
    
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

#ifndef MODEL_H
#define MODEL_H

#include "logobject.h"
#include <QMap>

class Translator;
class ModelHelper;

class Model : public LogObject
{
    Q_OBJECT

signals:
    void StartNewFileTranslate(const QString&); // Сигнал начала перевода нового файла. Параметром является имя данного файла
    void CurrentFileProgressChanged(int);       // Сигнал изменения прогресса перевода текущего файла. Параметром является процент прогресса

public:
    Model();
    ~Model();

    // Выполняет перевод словарных файлов выбранного языка
    void Translate(const QString& lightroom_path,
                   const QString& language_abb,
                   bool is_need_backup);

    // Копирирует английские файлы помощи поверх соответствующих файлов выбранного языка
    void CopyEnglishHelpFiles(const QString& lightroom_path,
                              const QString& language_abb,
                              bool is_need_backup);

    // Возвращает директорию установки Lightroom по умолчанию
    QString GetDefaultLightroomPath();

    // Возвращает признак корректности заданной директории установки Lightroom
    bool IsValidLightroomPath(const QString& path);

    // Копирует readme-файл в директорию установки Lightroom
    void CopyReadmeFile(const QString& lightroom_path);

    // Открывает readme-файл
    void OpenReadmeFile(const QString& lightroom_path);

#ifdef Q_WS_WIN
    // Переключает язык в Lightroom на выбранный
    void ToggleLanguageToSelected(const QString& language_abb);
#endif

#ifdef Q_WS_MAC
    // Переключает язык в Lightroom на русский
    void ToggleLanguageToRussian(const QString& lightroom_path);
#endif

    // Запускает Lightroom
    void ExecLightroom(const QString& lightroom_path);

    // Обновить список доступных языков
    void RefreshLanguagesList(const QString& lightroom_path);

    // Возвращает аббревиатуру языка по его имени
    QString GetLanguageAbb(const QString& language_name);

    // Возвращает имя языка по его аббревиатуре
    QString GetLanguageName(const QString& language_abb);

    // Возвращает список с именами доступных языков
    QStringList GetLanguagesNames();

    // Составляет текст письма
    void BuildMailText(QStringList& text);

    // Посылает статистику перевода
    void SendTranslatingStats();

    // Копирует текст в буфер обмена
    void CopyToClipboard(const QString& text);

    // Возвращает признак обнаружения неизвестных фраз во время перевода
    bool IsUnknownPhrasesAvailable();

private:
    typedef QMap<QString, QString> Dictionary;

    Translator* translator;
    ModelHelper* model_helper;
    Dictionary languages;
};

#endif // MODEL_H
