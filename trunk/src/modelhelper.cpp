#include "modelhelper.h"
#include "constants.h"
#include <QDir>
#include <QStringList>
#include <QUrl>
#include <QDesktopServices>

#ifdef Q_WS_WIN

#include <windows.h>

#endif


#ifdef Q_WS_WIN
void ModelHelper::CopyEnglishHelpFiles(const QString& lightroom_path,
                                       const QString& language_abb,
                                       bool is_need_backup)
{
    // Имя папки с файлами помощи на выбранном языке
    QString lang_help_dir_name = lightroom_path + QDir::separator() +
        consts::str_resources_sub_dir_name + QDir::separator() +
        language_abb + QDir::separator() + consts::str_help_sub_dir_name;
    // Имя папки с файлами помощи на английском языке
    QString eng_help_dir_name  = lightroom_path + QDir::separator() +
        consts::str_resources_sub_dir_name + QDir::separator() +
        consts::str_english_abb + QDir::separator() + consts::str_help_sub_dir_name;
#endif

#ifdef Q_WS_MAC
void ModelHelper::CopyEnglishHelpFiles(const QString& lightroom_path,
                                       const QString&,
                                       bool is_need_backup)
{
    // Имя папки с файлами помощи на русском языке
    QString lang_help_dir_name = lightroom_path + QDir::separator() +
        consts::str_contents_subdir_name + QDir::separator() +
        consts::str_resources_sub_dir_name + QDir::separator() +
        consts::str_russian_abb + consts::str_lproj_extension + QDir::separator() +
        consts::str_help_sub_dir_name;
    // Имя папки с файлами помощи на английском языке
    QString eng_help_dir_name = lightroom_path + QDir::separator() +
        consts::str_contents_subdir_name + QDir::separator() +
        consts::str_resources_sub_dir_name + QDir::separator() +
        consts::str_english_abb + consts::str_lproj_extension + QDir::separator() +
        consts::str_help_sub_dir_name;
#endif

    if (is_need_backup)
    {
        QString backup_dir_name = lang_help_dir_name + consts::str_backup_postfix;
        QDir dir;
        if (dir.exists(backup_dir_name))
            RemoveDir(backup_dir_name);
        if (!dir.rename(lang_help_dir_name, backup_dir_name))
            DoError(consts::err_text_fail_to_rename_dir_ss.arg(QDir::toNativeSeparators(lang_help_dir_name), QDir::toNativeSeparators(backup_dir_name)));
    }
    else
    {
        RemoveDir(lang_help_dir_name);
    }

    CopyDir(eng_help_dir_name, lang_help_dir_name);
}

bool ModelHelper::RemoveDir(const QString& dir_path)
{
    bool result = true;

    QDir dir(dir_path);
    QStringList files_list = dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
    QStringList dirs_list = dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs);

    foreach (QString file_name, files_list)
    {
        QString full_file_name = dir.absoluteFilePath(file_name);
        QFile file(full_file_name);
        file.setPermissions(QFile::WriteOther);
        if (!file.remove())
        {
            result = false;
            DoError(consts::err_text_fail_to_remove_file_sds.arg(QDir::toNativeSeparators(full_file_name)).arg(file.error()).arg(file.errorString()));
        }
    }
    ProcessEvents();

    foreach (QString dir_name, dirs_list)
        result = RemoveDir(dir.absolutePath() + QDir::separator() + dir_name) && result;

    QFile::setPermissions(dir.absoluteFilePath(dir_path), QFile::WriteOther);
    if (!dir.rmdir(dir_path))
    {
        result = false;
        DoError(consts::err_text_fail_to_remove_dir_s.arg(QDir::toNativeSeparators(dir_path)));
    }

    return result;
}

bool ModelHelper::CopyDir(const QString& from_dir_path, const QString& to_dir_path)
{
    bool result = true;

    QDir from_dir(from_dir_path);
    QStringList files_list = from_dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
    QStringList dirs_list = from_dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs);

    if (!from_dir.mkpath(to_dir_path))
    {
        DoError(consts::err_text_fail_to_create_dir_s.arg(QDir::toNativeSeparators(to_dir_path)));
        return false;
    }

    // Копируем файлы в текущей директории
    foreach (QString file_name, files_list)
    {
        QString file_from = from_dir_path + QDir::separator() + file_name;
        QString file_to = to_dir_path + QDir::separator() + file_name;
        if (!QFile::copy(file_from, file_to))
        {
            result = false;
            DoError(consts::err_text_fail_to_copy_file_from_to_ss.arg(QDir::toNativeSeparators(file_from), QDir::toNativeSeparators(file_to)));
        }
    }

    // Идем в подкаталоги
    foreach (QString dir_name, dirs_list)
    {
        QString dir_from = from_dir_path + QDir::separator() + dir_name;
        QString dir_to = to_dir_path + QDir::separator() + dir_name;
        result = CopyDir(dir_from, dir_to) && result;
    }

    return result;
}

bool ModelHelper::MoveDir(const QString& from_dir_path, const QString& to_dir_path)
{
    if (QDir().exists(to_dir_path) && !RemoveDir(to_dir_path))
        return false;

    if (!CopyDir(from_dir_path, to_dir_path))
        return false;

    return RemoveDir(from_dir_path);
}

void ModelHelper::OpenReadmeFile(const QString& lightroom_path)
{
    QString readme_file_path = lightroom_path + QDir::separator() + consts::str_readme_file_name;
    QUrl url = QUrl::fromLocalFile(readme_file_path);
    QDesktopServices::openUrl(url);
}

void ModelHelper::CopyReadmeFile(const QString& lightroom_path)
{
#ifdef Q_WS_WIN
    QString dest_path = lightroom_path;
#endif
#ifdef Q_WS_MAC
    QString dest_path = lightroom_path + QDir::separator() + consts::str_contents_subdir_name;
#endif

    QDir dir(dest_path);
    QString full_name = dir.absoluteFilePath(consts::str_readme_file_name);

    if (dir.exists(consts::str_readme_file_name))
    {
        QFile file(full_name);
        file.setPermissions(QFile::WriteOther);
        file.remove();
    }

    QFile from_file(consts::res_path_readme);
    QFile to_file(full_name);
    if (!to_file.open(QIODevice::Truncate | QIODevice::WriteOnly))
        return;

    if (!from_file.open(QIODevice::ReadOnly))
        return;

    QByteArray buf;
    buf = from_file.readAll();
    to_file.write(buf);
}

#ifdef Q_WS_WIN
void ModelHelper::ToggleLanguageToSelected(const QString& language_abb)
{
    HKEY key;

    if (RegOpenKeyA(consts::reg_root_language, consts::reg_key_language, &key) == ERROR_SUCCESS)
    {
        // Получаем длину записи в реестре
        RegSetValueExA(key,
            consts::reg_value_language,
            0,
            REG_SZ,
            static_cast<BYTE*>(static_cast<void*>(language_abb.toLatin1().data())),
            language_abb.toLatin1().size());

        RegCloseKey(key);
    }

    if (RegOpenKeyA(consts::reg_root_language_2, consts::reg_key_language_2, &key) == ERROR_SUCCESS)
    {
        // Получаем длину записи в реестре
        RegSetValueExA(key,
            consts::reg_value_language_2,
            0,
            REG_SZ,
            static_cast<BYTE*>(static_cast<void*>(language_abb.toLatin1().data())),
            language_abb.toLatin1().size());

        RegCloseKey(key);
    }
}
#endif

#ifdef Q_WS_MAC
void ModelHelper::ToggleLanguageToRussian(const QString& lightroom_path)
{
    // Определяем путь к папке ресурсов
    QString resources_path = lightroom_path + QDir::separator() +
        consts::str_contents_subdir_name + QDir::separator() +
        consts::str_resources_sub_dir_name;

    QDir from_dir(resources_path);
    QStringList lang_list = from_dir.entryList(QStringList(consts::str_lang_subdir_filter),
                                               QDir::Dirs | QDir::NoDotAndDotDot);

    // Определяем путь к папке отключенных ресурсов
    QString to_path = lightroom_path + QDir::separator() +
        consts::str_contents_subdir_name + QDir::separator() +
        consts::str_resources_disabled_sub_dir_name;
    QDir to_dir (to_path);

    lang_list.removeOne(consts::str_russian_abb + consts::str_lproj_extension);

    // Перемещаем все каталоги ресурсов кроме русского в отключенные,
    // тем самым оставляя в приложении Lightroom только русский язык
    foreach (QString lang, lang_list)
        MoveDir(from_dir.absoluteFilePath(lang), to_dir.absoluteFilePath(lang));
}
#endif


void ModelHelper::ExecLightroom(const QString& lightroom_path)
{
#ifdef Q_WS_WIN
    QString app_path = lightroom_path + QDir::separator() + consts::str_lightroom_exec_file_name;
#endif

#ifdef Q_WS_MAC
    QString app_path = lightroom_path;
#endif

    QUrl url = QUrl::fromLocalFile(app_path);
    QDesktopServices::openUrl(url);
}
