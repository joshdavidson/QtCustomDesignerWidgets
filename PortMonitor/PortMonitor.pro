QT          += network
CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(portmonitorplugin)
TEMPLATE    = lib

INCLUDEPATH += $$PWD/include

HEADERS     = $$PWD/include/portmonitorplugin.h
SOURCES     = $$PWD/src/portmonitorplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(portmonitor.pri)

FILE=$$OUT_PWD/release/portmonitorplugin.dll
FILE ~= s,/,\\,g
DEST=$$[QT_INSTALL_PLUGINS]/designer
DEST ~= s,/,\\,g
system(mkdir $$DEST)

QMAKE_POST_LINK += \
        $$quote(cmd /c copy /Y $${FILE} $${DEST}$$escape_expand(\n\t))
