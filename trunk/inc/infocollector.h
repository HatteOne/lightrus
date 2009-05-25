/*******************************************************************************
  Функции для получения различной информации

  Автор: Балякин С.В.
  Дата: 28.04.2009
*******************************************************************************/

#ifndef INFOCOLLECTOR_H
#define INFOCOLLECTOR_H

#include <QString>
#include <QStringList>
#include <QMap>

namespace InfoCollector
{

    // Пытается определить директорию инсталляции Lightroom
    QString GetLightroomInstallDir();

    // Возвращает true если переданная директория установки Lightroom выглядит верной
    // dir - предполагаемая директория установки Lightroom
    bool IsValidLightroomDir(const QString& dir);

    // Находит имена файлов локализации для заданной аббревиатуры языка.
    // lightroom_dir - директория установки Lightroom
    // lang_abb - аббревиатура языка для перевода
    // result_list - список, куда помещается результат поиска
    void FindTranslatedStringsFiles(const QString& lightroom_dir, const QString& lang_abb, QStringList& result_list);

#ifdef Q_WS_MAC
    // Находит имена файлов русской локализации, соответствующие файлам заданной аббревиатуры языка.
    // lang_abb - аббревиатура языка для перевода
    // in_list - список лексических файлов для заданной аббревиатуры языка
    // result_list - список, куда помещается результат поиска
    void SpecifyRusTranslatedStringsFiles(const QString& lang_abb, const QStringList& in_list, QStringList& result_list);
#endif

    // Осуществляет поиск файлов начиная с заданной папки, с заданными фильтрами и вложенностью
    // start_dir - директория, с которой начинается поиск
    // name_filters - список фильтров имен файлов
    // enclosed_dirs - признак поиска во вложенных папках
    // result_list - список, куда помещается результат поиска
    void FindFiles(const QString& start_dir, const QStringList& name_filters, bool enclosed_dirs, QStringList& result_list);

    // Возвращает контейнер со списком языков, доступных в Lightroom.
    // Первое значение пары элемента контейнера аббревиатура, второе - название
    // lightroom_dir - директория установки Lightroom
    // result - результирующий ассоциированный контейнер с доступными языками
    void GetLanguagesList(const QString& lightroom_dir, QMap<QString, QString>& result_map);

    // Возвращает версию операционной системы в текстовом виде
    QString GetOSVersion();

    // Возвращает количество бит в слове, т.е. возвращает т.н. битность ОС
    int GetWordSize();

}

#endif // INFOCOLLECTOR_H
