# -------------------------------------------------
# Project created by QtCreator 2009-04-21T10:13:34
# -------------------------------------------------
TARGET = Lightrus

CONFIG+=release
CONFIG-=debug

TEMPLATE = app

DEPENDPATH += src \
    inc

INCLUDEPATH += inc

SOURCES += main.cpp \
    maindialog.cpp \
    infocollector.cpp \
    translator.cpp \
    controller.cpp \
    model.cpp \
    modelhelper.cpp

HEADERS += maindialog.h \
    infocollector.h \
    translator.h \
    constants.h \
    controller.h \
    model.h \
    modelhelper.h \
    logobject.h

FORMS += maindialog.ui

RESOURCES += res.qrc

MOC_DIR = generated

RCC_DIR = generated

UI_DIR = generated

SUBDIR_DEBUG   = debug
SUBDIR_RELEASE = release
SUBDIR_WIN     = platform_win
SUBDIR_MAC     = platform_mac
SUBDIR_OBJ     = obj

# Компиляция под Mac OS
macx {
    ICON = $$SUBDIR_MAC/app.icns
    CONFIG(debug, debug|release) {
        message("Building debug version for Mac OS.")
        DESTDIR     = $$SUBDIR_MAC/$$SUBDIR_DEBUG
        OBJECTS_DIR = $$SUBDIR_MAC/$$SUBDIR_DEBUG/$$SUBDIR_OBJ
    }
    else {
        CONFIG(release, debug|release) {
            message("Building release version for Mac OS.")
            DESTDIR     = $$SUBDIR_MAC/$$SUBDIR_RELEASE
            OBJECTS_DIR = $$SUBDIR_MAC/$$SUBDIR_RELEASE/$$SUBDIR_OBJ
        }
    }
}

# Компиляция под Windows
win32 {
    RC_FILE = $$SUBDIR_WIN/winicon.rc
    CONFIG(debug, debug|release) {
        message("Building debug version for Windows.")
        DESTDIR     = $$SUBDIR_WIN/$$SUBDIR_DEBUG
        OBJECTS_DIR = $$SUBDIR_WIN/$$SUBDIR_DEBUG/$$SUBDIR_OBJ
    }
    else {
        CONFIG(release, debug|release) {
            message("Building release version for Windows.")
            DESTDIR     = $$SUBDIR_WIN/$$SUBDIR_RELEASE
            OBJECTS_DIR = $$SUBDIR_WIN/$$SUBDIR_RELEASE/$$SUBDIR_OBJ
        }
    }
}

