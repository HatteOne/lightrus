#include "infocollector.h"
#include <QFileInfo>
#include <QDir>
#include <QMap>
#include <QSysInfo>
#include <QByteArray>
#include "constants.h"


#ifdef Q_WS_WIN

#include <windows.h>

#endif

// Вспомогательная функция для определения названия языка в заданном блоке данных
QString GetLanguageFullName(const QByteArray& data, const QString& lang_abb)
{
    int abb_from = 0;
    int key_from = 0;
    int value_from = 0;
    int value_to = 0;
    int temp_buffer_size = 200;

    QByteArray lang_key( consts::lang_key_prefix.toLatin1() );
    QString search_abb = consts::char_zero + lang_abb + consts::char_zero;

    QByteArray temp_buffer;

    for(;;)
    {
        abb_from = data.indexOf(search_abb, abb_from); // Ищем аббревиатуру языка
        if (-1 == abb_from)
            break;

        abb_from += lang_abb.size();

        // Ограничиваем область поиска размером временного буфера
        temp_buffer.clear();
        temp_buffer.append( data.mid(abb_from - temp_buffer_size, temp_buffer_size) );

        key_from = temp_buffer.lastIndexOf(lang_key, temp_buffer_size - 1); // Ищем предшествующий аббревиатуре ключ, содержащий полное название языка
        if (-1 == key_from)
            continue;

        value_from = temp_buffer.indexOf(consts::char_assign, key_from + lang_key.size() + 1); // Ищем начало названия языка
        if (-1 == value_from)
            continue;

        value_to = temp_buffer.indexOf(consts::char_zero, value_from + 1); // Ищем окончание названия языка
        if (-1 == value_to)
            continue;

        return QString( temp_buffer.mid(value_from + 1, value_to - 1) );
    }

    return QString();
}

// Определяет список аббревиатур языков, доступных в Lightroom
// lightroom_dir - директория установки Lightroom
// result_list - список, куда помещаются найденные аббревиатуры языков
void GetAvailableLanguagesAbbs( const QString& lightroom_dir, QStringList& result_list )
{
#ifdef Q_WS_WIN
    // Определяем путь к папке ресурсов
    QString resources_path = QDir::fromNativeSeparators(lightroom_dir) + QDir::separator() + consts::str_resources_sub_dir_name;
    QDir dir (resources_path);
    result_list = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    // Убираем из рассмотрения директорию с английскими ресурсами локализации
    result_list.removeOne(consts::str_english_abb);
#endif

#ifdef Q_WS_MAC
    // Определяем путь к папке ресурсов
    QString resources_path = lightroom_dir + QDir::separator() + consts::str_contents_subdir_name + QDir::separator() + consts::str_resources_sub_dir_name;
    QDir dir(resources_path);
    result_list = dir.entryList(QStringList(consts::str_lang_subdir_filter), QDir::Dirs | QDir::NoDotAndDotDot);

    // Определяем путь к папке отключенных ресурсов
    QString resources_disabled_path = lightroom_dir + QDir::separator() + consts::str_contents_subdir_name + QDir::separator() + consts::str_resources_disabled_sub_dir_name;
    dir.setPath(resources_disabled_path);
    result_list.append(dir.entryList(QStringList(consts::str_lang_subdir_filter), QDir::Dirs | QDir::NoDotAndDotDot));

    // Убираем расширения с директорий ресурсов локализации
    for (QStringList::iterator iter = result_list.begin(); iter != result_list.end(); ++iter)
        iter->replace(consts::str_lproj_extension,"");

    // Убираем из рассмотрения директорию с английскими и русскими ресурсами локализации
    result_list.removeOne(consts::str_english_abb);
    result_list.removeOne(consts::str_russian_abb);
#endif
}

// Определяет названия языков для переданного списка аббревиатур
// lightroom_dir - директория установки Lightroom
// abbs_list - список аббревиатур
// result_list - список, куда помещаются определенные названия языков
void GetLanguagesFullNames( const QString& lightroom_dir, const QStringList& abbs_list, QStringList& result_list )
{
    // Определяем имя файла с названиями языков
#ifdef Q_WS_WIN
    QString lang_file_name = lightroom_dir + QDir::separator() +
                             consts::str_lightroom_exec_file_name;
#endif
#ifdef Q_WS_MAC
    QString lang_file_name = lightroom_dir + QDir::separator() +
                             consts::str_contents_subdir_name + QDir::separator() +
                             consts::str_resources_sub_dir_name + QDir::separator() +
                             consts::str_prefs_window_file_name;
#endif

    result_list.clear();

    QFile file ( lang_file_name );

    if (!file.exists())
        return;

    if (!file.open(QIODevice::ReadOnly))
        return;

    // Читаем запускаемый файл целиком в файл
    QByteArray data = file.readAll();
    if (data.isEmpty())
        return;

    QString name;
    foreach (QString lang, abbs_list)
    {
        name = GetLanguageFullName(data, lang);
        result_list.append( name );
    }
}

QString InfoCollector::GetLightroomInstallDir()
{
#ifdef Q_WS_WIN
    // Получаем имя папки Lightroom из данных реестра
    HKEY key;
    if (RegOpenKeyA(consts::reg_root_lightroom_dir, consts::reg_key_name_lightroom_dir, &key) == ERROR_SUCCESS)
    {
        DWORD full_name_size = 0;
        // Получаем длину записи в реестре
        if (RegQueryValueExA(key, consts::reg_value_name_lightroom_dir, 0, 0, 0, &full_name_size) == ERROR_SUCCESS)
        {
            QByteArray full_name (full_name_size, 0);
            // Получаем полный путь файла lightroom.exe
            if (RegQueryValueExA(key, consts::reg_value_name_lightroom_dir, 0, 0,
                                 static_cast<BYTE*>(static_cast<void*>(full_name.data())),
                                 &full_name_size) == ERROR_SUCCESS)
            {
                QFileInfo file_info( (QString(full_name)) );
                if (file_info.exists())
                    return file_info.absolutePath();;
            }
        }
    }
#endif

#ifdef Q_WS_MAC
    // Ищем имя пакета Adobe Lightroom
    QDir dir (consts::str_applications_dir_path);
    QStringList dir_list = dir.entryList(QStringList(consts::str_lightroom_dir_filter), QDir::Dirs | QDir::NoDotAndDotDot);

    // Берем первую найденную директорию похожую на директорию Lightroom
    if (!dir_list.isEmpty())
        return dir.absoluteFilePath(dir_list.at(0));
#endif
    return QString();
}

bool InfoCollector::IsValidLightroomDir(const QString& dir)
{
#ifdef Q_WS_WIN
    return QFile::exists(dir + QDir::separator() + consts::str_lightroom_exec_file_name);
#endif

#ifdef Q_WS_MAC
    // Пытаемся открыть файл с информацией пакета
    QString file_name = dir + QDir::separator() + consts::str_contents_subdir_name + QDir::separator() + consts::str_info_file_name;
    QFile info_file(file_name);
    if (!info_file.exists())
        return false;

    if (!info_file.open(QIODevice::ReadOnly))
        return false;

    // Ищем строку Adobe Lightroom 2
    QByteArray data = info_file.readAll();
    return data.indexOf(consts::str_lightroom_info_name) != -1;
#endif
}

void InfoCollector::GetLanguagesList( const QString& lightroom_dir, QMap<QString, QString>& result_map )
{
    QStringList abbs_list;
    QStringList names_list;

    GetAvailableLanguagesAbbs(lightroom_dir, abbs_list);
    GetLanguagesFullNames(lightroom_dir, abbs_list, names_list);

    if (abbs_list.size() != names_list.size())
        qFatal("Error defining languages' names");

    result_map.clear();

    for (QStringList::size_type index = 0; index < abbs_list.size(); ++index)
        result_map.insert(abbs_list[index], names_list[index]);
}

QString InfoCollector::GetOSVersion()
{
    QSysInfo sys_info;

#ifdef Q_WS_WIN
    switch (sys_info.WindowsVersion)
    {
        case QSysInfo::WV_32s       : return consts::text_os_wv_32s;      
        case QSysInfo::WV_95        : return consts::text_os_wv_95;       
        case QSysInfo::WV_98        : return consts::text_os_wv_98;       
        case QSysInfo::WV_Me        : return consts::text_os_wv_me;       
        case QSysInfo::WV_NT        : return consts::text_os_wv_nt;       
        case QSysInfo::WV_2000      : return consts::text_os_wv_2000;     
        case QSysInfo::WV_XP        : return consts::text_os_wv_xp;       
        case QSysInfo::WV_2003      : return consts::text_os_wv_2003;     
        case QSysInfo::WV_VISTA     : return consts::text_os_wv_vista;    
        case QSysInfo::WV_WINDOWS7  : return consts::text_os_wv_windows7; 
        case QSysInfo::WV_DOS_based : return consts::text_os_wv_dos_based;
        case QSysInfo::WV_NT_based  : return consts::text_os_wv_nt_based; 
        case QSysInfo::WV_CE_based  : return consts::text_os_wv_ce_based; 
        default                     : return consts::text_os_wv_unknown;  
    }                                        
#endif

#ifdef Q_WS_MAC
    switch (sys_info.MacintoshVersion)
    {
        case QSysInfo::MV_9    : return consts::text_os_mv_9;
        case QSysInfo::MV_10_0 : return consts::text_os_mv_10_0;   
        case QSysInfo::MV_10_1 : return consts::text_os_mv_10_1;   
        case QSysInfo::MV_10_2 : return consts::text_os_mv_10_2;   
        case QSysInfo::MV_10_3 : return consts::text_os_mv_10_3;   
        case QSysInfo::MV_10_4 : return consts::text_os_mv_10_4;   
        case QSysInfo::MV_10_5 : return consts::text_os_mv_10_5;   
        case QSysInfo::MV_10_6 : return consts::text_os_mv_10_6;   
        default                : return consts::text_os_mv_unknown;
    }
#endif
}

int InfoCollector::GetWordSize()
{
    return QSysInfo::WordSize;
}

void InfoCollector::FindTranslatedStringsFiles(const QString& lightroom_dir, const QString& lang_abb, QStringList& result_list)
{
    QDir dir(lightroom_dir);
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfo entry;
    QString file_name;
    // Пробегаем по всем директориям
    foreach (entry, entries)
    {
        file_name = QDir::fromNativeSeparators( entry.absoluteFilePath() + QDir::separator() + consts::str_translating_file_name );

#ifdef Q_WS_WIN
        if (QString::compare(entry.fileName(), lang_abb, Qt::CaseInsensitive) == 0 && // У директории подходящее имя
#endif
#ifdef Q_WS_MAC
        if ( (QString::compare(entry.fileName(), lang_abb, Qt::CaseInsensitive) == 0 || // У директории подходящее имя
            QString::compare(entry.fileName(), lang_abb + consts::str_lproj_extension, Qt::CaseInsensitive) == 0) &&
#endif
            QFile::exists(file_name) ) // Директория содержит файл для перевода
            result_list.append(file_name);
        else
            FindTranslatedStringsFiles(entry.absoluteFilePath(), lang_abb, result_list); // Рекурсивно ищем дальше
    }
}

void InfoCollector::FindFiles( const QString& start_dir, const QStringList& name_filters, bool enclosed_dirs, QStringList& result_list )
{
    QDir dir(start_dir);
    QStringList dirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList files = dir.entryList(name_filters, QDir::Files | QDir::NoDotAndDotDot);

    // Пробегаем по всем файлам
    foreach (QString file, files)
        result_list.append(dir.absoluteFilePath(file));

    // Пробегаем по всем директориям
    if (enclosed_dirs)
        foreach (QString dir, dirs)
            FindFiles(start_dir + QDir::separator() + dir, name_filters, enclosed_dirs, result_list); // Рекурсивно ищем дальше
}

#ifdef Q_WS_MAC
void InfoCollector::SpecifyRusTranslatedStringsFiles(const QString& lang_abb, const QStringList& in_list, QStringList& result_list)
{
    result_list.clear();

    QString replace_from_1 = QDir::separator() + lang_abb + QDir::separator();
    QString replace_from_2 = QDir::separator() + lang_abb +  consts::str_lproj_extension + QDir::separator();
    QString replace_to_1   = QDir::separator() + consts::str_russian_abb + QDir::separator();
    QString replace_to_2   = QDir::separator() + consts::str_russian_abb +  consts::str_lproj_extension + QDir::separator();

    foreach (QString file_name, in_list)
    {
        file_name.replace(replace_from_1, replace_to_1, Qt::CaseInsensitive);
        file_name.replace(replace_from_2, replace_to_2, Qt::CaseInsensitive);
        result_list.append(file_name);
    }
}
#endif
