/*******************************************************************************

    Project Lightrus
    
    Класс контроллера
    
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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

// Предварительное объявление классов вида и модели
class Model;
class MainDialog;

class Controller : public QObject
{
    Q_OBJECT

private slots:
    // Начало перевода
    void Translate();

    // Задает директорию установки Lightroom по умолчанию
    void SetDefaultLightroomPath();

    // Изменена директория Lightroom
    void ChangeLightroomDirPath(const QString& path);

    // Открыть readme-файл
    void OpenReadmeFile();

    // Измененить язык Lightroom на выбранный
    void ToggleLanguageToSelected();

    // Запустить Lightroom
    void ExecLightroom();

    // Формирование текста письма с неизвестными фразами
    void CollectUnknownPhrases();

    // Начало перевода нового файла
    void StartNewFileTranslate(const QString&);

    // Изменение прогресса перевода текущего файла
    void CurrentFileProgressChanged(int);

    // Копирует text в буфер обмена
    void CopyToClipboard(const QString& text);

    // Определяет необходимость отображения страницы с неизвестными фразами
    void IsPageNotTranslatedNeeded(bool& is_need);

    // Обработчик события логирования
    void OnLogMessage(const QString& text);

    // Обработчик информационных сообщений
    void OnInfoMessage(const QString& text);

    // Обработчик сообщений об ошибке
    void OnErrorMessage(const QString& text);


public:
    Controller(MainDialog* _view, Model* _model);

    // Запускает выполнение контроллера
    void Start();

private:
    MainDialog* view; // Вид
    Model* model;     // Модель

    // Возвращает заданный пользователем директорию установки Lightroom
    QString GetLightroomPath();

    // Возвращает аббревиатуру выбранного пользователем языка
    QString GetLanguageAbb();

    // Возвращает признак создания резервных копии заменяемых файлов
    bool IsNeedBackup();

    // Возвращает признак копирования английских файлов помощи
    bool IsNeedCopyEnglishHelpFiles();
};

#endif // CONTROLLER_H
