/*******************************************************************************

    Project Lightrus
    
    Класс, предоставляющий специализированные файловые операции
    
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
