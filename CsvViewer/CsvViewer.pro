CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(csvviewerplugin)
TEMPLATE    = lib

HEADERS     = csvviewerplugin.h
SOURCES     = csvviewerplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(csvviewer.pri)

unix {
  FILE=$$OUT_PWD/libcsvviewerplugin.so
  DEST=$$[QT_INSTALL_PLUGINS]/designer/
  QMAKE_POST_LINK += $$quote(cp $${FILE} $${DEST})
}

win32 {
  FILE=$$OUT_PWD/release/csvviewerplugin.dll
  FILE ~= s,/,\\,g
  DEST=$$[QT_INSTALL_PLUGINS]/designer
  DEST ~= s,/,\\,g
  system(mkdir $$DEST)

  QMAKE_POST_LINK += \
        $$quote(cmd /c copy /Y $${FILE} $${DEST}$$escape_expand(\n\t))
}

