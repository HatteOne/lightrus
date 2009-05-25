#ifndef MODELHELPER_H
#define MODELHELPER_H

#include <QString>
#include "logobject.h"

class ModelHelper : public LogObject
{
public:
    // Копирирует английские файлы помощи поверх соответствующих файлов выбранного языка
    void CopyEnglishHelpFiles(const QString& lightroom_path,
                              const QString& language_abb,
                              bool is_need_backup);

    // Удаляет папку со всем содержимым.
    // Возвращает true в случае успешного завершения операции.
    bool RemoveDir(const QString& dir_path);

    // Копирует папку со всем содержимым
    // Возвращает true в случае успешного завершения операции.
    bool CopyDir(const QString& from_dir_path, const QString& to_dir_path);

    // Перемещает папку со всем содержимым
    // Возвращает true в случае успешного завершения операции.
    bool MoveDir(const QString& from_dir_path, const QString& to_dir_path);

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
};

#endif // MODELHELPER_H
