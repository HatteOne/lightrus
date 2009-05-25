/*******************************************************************************
  Класс контроллера

  Автор: Балякин С.В.
  Дата: 05.05.2009 г.
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
