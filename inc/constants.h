/*******************************************************************************

    Project Lightrus
    
    Набор констант, используемых приложением
    
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

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QtCore/QString>
#include <QColor>


#ifdef Q_WS_WIN

#include <windows.h>

#endif

namespace consts
{

// Нумераторы версий ***********************************************************

// Версия приложения
const QString application_version = QString::fromUtf8("1.0.0");

// Версия словаря
const QString dictionary_version = QString::fromUtf8("1.0.0");


// Пути к ресурсным файлам *****************************************************

// Полное имя ресурсного словарного файла с русским переводом
const QString res_path_russian_dictionary = QString::fromUtf8(":/res/text/russian_dictionary.txt");

// Полное имя ресурсного файла с фразами, переводимыми на английский язык
const QString res_path_english_exclusions = QString::fromUtf8(":/res/text/english_exclusions.txt");

// Полное имя ресурсного файла readme
const QString res_path_readme = QString::fromUtf8(":/res/text/readme_rus.txt");


// Текстовые фразы интерфейса пользователя
const QString text_prev                    = QString::fromUtf8("< Назад");
const QString text_next                    = QString::fromUtf8("Далее >");
const QString text_exec                    = QString::fromUtf8("Перевести");
const QString text_finish                  = QString::fromUtf8("Завершить");
const QString text_browse_dialog_title     = QString::fromUtf8("Выберите директорию с установленным\nAdobe Photoshop Lightroom");
const QString text_translating_finished    = QString::fromUtf8("<br>Перевод завершен.");
const QString text_unknown_phrases_found_d = QString::fromUtf8("<br>Обнаружено неизвестных фраз: %1.<br>Данные фразы не были переведены.<br>Перейдите на следующую страницу для получения<br>более подробной информации.");
const QString text_os_version_s            = QString::fromUtf8("Версия ОС: %1");
const QString text_os_word_size_d          = QString::fromUtf8("Битность ОС: %1");
const QString text_application_version_s   = QString::fromUtf8("Версия приложения: %1");
const QString text_dictionary_version_s    = QString::fromUtf8("Версия словаря: %1");
const QString text_lightroom_path_s        = QString::fromUtf8("Папка установки: %1");
const QString text_language_abb_ss         = QString::fromUtf8("Язык замены: %1 (%2)");
const QString text_unknown_phrases_count_d = QString::fromUtf8("Количество неизвестных фраз: %1\n");
const QString text_mail_subject            = QString::fromUtf8("Unknown phrases");
const QString text_close_warning_text      = QString::fromUtf8("Вы действительно хотите отменить процесс\nрусификации Adobe Photoshop Lightroom?");
const QString text_yes                     = QString::fromUtf8("Да");
const QString text_no                      = QString::fromUtf8("Нет");
const QString text_close_warning_title     = QString::fromUtf8("Русификатор Adobe Lightroom");
const QString text_translating_file_s      = QString::fromUtf8("Перевод...%1");
const QString text_prepare_dictionaries    = QString::fromUtf8("Подготовка словарей к переводу...<br>");
const QString text_copying_help_files      = QString::fromUtf8("Копирование файлов помощи...");
const QString text_convert_to_html_ss      = QString::fromUtf8("<span style=\"color:%1;\">%2</span><br>");
const QString text_mailto_url_sss          = QString::fromUtf8("mailto:%1?subject=%2&body=%3");
const QString text_author_mail_address     = QString::fromUtf8("lightroom@list.ru");


// Тексты ошибок
const QString err_text_fail_to_open_file_s              = QString::fromUtf8("Не удалось открыть файл %1");
const QString err_text_fail_to_create_temporary_file    = QString::fromUtf8("Не удалось создать временный файл для перевода. Возможно недостаточно места на диске.");
const QString err_text_fail_to_remove_file_sds          = QString::fromUtf8("Не удалось удалить файл %1. Код ошибки %2 (%3)");
const QString err_text_fail_to_copy_file_sds            = QString::fromUtf8("Не удалось сохранить файл %1. Код ошибки %2 (%3)");
const QString err_text_fail_to_copy_file_from_to_ss     = QString::fromUtf8("Не удалось скопировать файл %1 в %2");
const QString err_text_fail_to_rename_file_from_to_ssds = QString::fromUtf8("Не удалось переименовать файл %1 в %2. Код ошибки &3 (%4)");
const QString err_text_fail_to_remove_dir_s             = QString::fromUtf8("Не удалось удалить директорию %1");
const QString err_text_fail_to_create_dir_s             = QString::fromUtf8("Не удалось создать директорию %1");
const QString err_text_fail_to_rename_dir_ss            = QString::fromUtf8("Не удалось переименовать директорию %1 в %2");


// Цветовые константы
const QColor color_black = QColor::fromRgb(0x000000);
const QColor color_red   = QColor::fromRgb(0xaa0000);
const QColor color_blue  = QColor::fromRgb(0x0000aa);

// Символы, используемые в алгоритмах
const char char_quote      = '\"';
const char char_assign     = '=';
const char char_zero       = '\0';
const char char_back_slash = '\\';

// Строки, используемые в алгоритмах
const QString str_quote                  = QString::fromUtf8("\"");
const QString str_assign                 = QString::fromUtf8("=");
const QString str_return                 = QString::fromUtf8("\n");
const QString str_return_replace         = QString::fromUtf8("\\n");
const QString str_translating_file_name  = QString::fromUtf8("TranslatedStrings.txt"); // Имена файлов для перевода
const QString str_backup_postfix         = QString::fromUtf8(".bak");                  // Окончание резервных файлов или папок
const QString str_english_abb            = QString::fromUtf8("en");                    // Аббревиатура английского языка
const QString str_russian_abb            = QString::fromUtf8("ru");                    // Аббревиатура русского языка
const QString str_resources_sub_dir_name = QString::fromUtf8("Resources");             // Поддиректория ресурсов
const QString str_help_sub_dir_name      = QString::fromUtf8("help");                  // Поддиректория файлов помощи
const QString str_readme_file_name       = QString::fromUtf8("readme_rus.txt");        // Имя readme-файла
const QString str_all_files_filter       = QString::fromUtf8("*.*");                   // Фильтр для поиска всех файлов

// Начало наименования переменной, хранящей полное имя языка
const QString lang_key_prefix = QString::fromUtf8("$$$/AgPreferences/Interface/");

// Префикс идентификатора фразы
const QString str_phrase_prefix = QString::fromUtf8("$$$/");

// Символы, разрешенные в идентификаторе фразы
const QString str_phrase_id_chars =
    QString::fromUtf8("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_/");


// Платформенно-зависимые константы ********************************************

#ifdef Q_WS_WIN

// Тексты элементов интерфейса
const QString text_ui_label_path                  = QString::fromUtf8("Папка Lightroom");
const QString text_ui_label_title_parameters      = QString::fromUtf8("Выберите папку установки Adobe Photoshop Lightroom и определите остальные необходимые параметры");
const QString text_ui_label_choose_languages      = QString::fromUtf8("Выберите язык для замены на русский:");
const QString text_ui_check_box_toggle_to_russian = QString::fromUtf8("Переключить язык в Lightroom на русский");
const QString text_ui_label_welcome_ss            = QString::fromUtf8("<H2>Добро пожаловать в программу русификации Adobe Photoshop Lightroom 2.x</H2>Данная программа позволит заменить один из дополнительных языков приложения Adobe Photoshop Lightroom на русский.<br><br>Версия русификатора: %1<br>Версия словаря: %2");


// Имя запускаемого файла
const QString str_lightroom_exec_file_name = QString::fromUtf8("lightroom.exe");

// Ветвь реестра, где содержится информация о полном имени lightroom.exe
const HKEY        reg_root_lightroom_dir       = HKEY_CLASSES_ROOT;
const char* const reg_key_name_lightroom_dir   = "Adobe.AdobeLightroom";
const char* const reg_value_name_lightroom_dir = "DefaultIcon";

// Ветвь реестра для изменения текущего выбранного языка Lightroom
const HKEY        reg_root_language  = HKEY_LOCAL_MACHINE;
const char* const reg_key_language   = "SOFTWARE\\Adobe\\Lightroom";
const char* const reg_value_language = "language";

// Дополнительная ветвь реестра для изменения текущего выбранного языка Lightroom
const HKEY        reg_root_language_2  = HKEY_CURRENT_USER;
const char* const reg_key_language_2   = "Software\\Adobe\\Lightroom";
const char* const reg_value_language_2 = "language";

// Текстовые названия версий операционных систем Windows
const QString text_os_wv_32s       = QString::fromUtf8("Windows 3.1 with Win 32s");
const QString text_os_wv_95        = QString::fromUtf8("Windows 95");
const QString text_os_wv_98        = QString::fromUtf8("Windows 98");
const QString text_os_wv_me        = QString::fromUtf8("Windows Me");
const QString text_os_wv_nt        = QString::fromUtf8("Windows NT (operating system version 4.0)");
const QString text_os_wv_2000      = QString::fromUtf8("Windows 2000 (operating system version 5.0)");
const QString text_os_wv_xp        = QString::fromUtf8("Windows XP (operating system version 5.1)");
const QString text_os_wv_2003      = QString::fromUtf8("Windows Server 2003, Windows Server 2003 R2, Windows Home Server, Windows XP Professional x64 Edition (operating system version 5.2)");
const QString text_os_wv_vista     = QString::fromUtf8("Windows Vista, Windows Server 2008 (operating system version 6.0)");
const QString text_os_wv_windows7  = QString::fromUtf8("Windows 7 (operating system version 6.1)");
const QString text_os_wv_dos_based = QString::fromUtf8("MS-DOS-based version of Windows");
const QString text_os_wv_nt_based  = QString::fromUtf8("NT-based version of Windows");
const QString text_os_wv_ce_based  = QString::fromUtf8("CE-based version of Windows");
const QString text_os_wv_unknown   = QString::fromUtf8("Unknown Windows version");
  
#endif

#ifdef Q_WS_MAC

// Тексты элементов интерфейса
const QString text_ui_label_path                  = QString::fromUtf8("Полный путь приложения Adobe Lightroom");
const QString text_ui_label_title_parameters      = QString::fromUtf8("Перетащите приложение Аdobe Photoshop Lightroom в это окно или выберите его при помощи кнопки \"Обзор...\"");
const QString text_ui_label_choose_languages      = QString::fromUtf8("Выберите язык в качестве исходника перевода:");
const QString text_ui_check_box_toggle_to_russian = QString::fromUtf8("Отключить все языки кроме русского");
const QString text_ui_label_welcome_ss            = QString::fromUtf8("<H2>Добро пожаловать в программу русификации Adobe Photoshop Lightroom 2.x</H2>Данная программа позволит добавить русский язык в Lightroom в качестве дополнительного.<br><br>Версия русификатора: %1<br>Версия словаря: %2");

const QString str_applications_dir_path  = QString::fromUtf8("/Applications");           // Абсолютная папка программ в Mac OS
const QString str_contents_subdir_name   = QString::fromUtf8("Contents");                // Поддиректория содержимого пакета
const QString str_info_file_name         = QString::fromUtf8("Info.plist");              // Имя файла с информацией пакета
const QString str_lightroom_info_name    = QString::fromUtf8("Adobe Lightroom 2");       // Название приложения в информационном файле Info.plist
const QString str_lightroom_dir_filter   = QString::fromUtf8("*Adobe*Lightroom*.app");   // Шаблон имени пакета Lightroom
const QString str_lproj_extension        = QString::fromUtf8(".lproj");                  // Расширение поддиректории папок с ресурсами локализации
const QString str_lang_subdir_filter     = QString::fromUtf8("*") + str_lproj_extension; // Шаблон поддиректории папок с ресурсами локализации
const QString str_prefs_window_file_name = QString::fromUtf8("PrefsWindow.lua");         // Файл со списком доступных языков
const QString str_lua_files_filter       = QString::fromUtf8("*.lua");                   // Шаблон имен lua-файлов
const QString str_app_files_filter       = QString::fromUtf8("*.app");                   // Фильтр файлов аппликации

// Имя поддиректории с отключенными ресурсами
const QString str_resources_disabled_sub_dir_name = QString::fromUtf8("Resources Disabled");

// Текстовые названия версий операционных систем Mac OS
const QString text_os_mv_9       = QString::fromUtf8("Mac OS 9 (unsupported)");
const QString text_os_mv_10_0    = QString::fromUtf8("Mac OS X 10.0 (unsupported)");
const QString text_os_mv_10_1    = QString::fromUtf8("Mac OS X 10.1 (unsupported)");
const QString text_os_mv_10_2    = QString::fromUtf8("Mac OS X 10.2 (unsupported)");
const QString text_os_mv_10_3    = QString::fromUtf8("Mac OS X 10.3");
const QString text_os_mv_10_4    = QString::fromUtf8("Mac OS X 10.4");
const QString text_os_mv_10_5    = QString::fromUtf8("Mac OS X 10.5");
const QString text_os_mv_10_6    = QString::fromUtf8("Mac OS X 10.6");
const QString text_os_mv_unknown = QString::fromUtf8("An unknown and currently unsupported Mac OS platform");

#endif

}

#endif // CONSTANTS_H
