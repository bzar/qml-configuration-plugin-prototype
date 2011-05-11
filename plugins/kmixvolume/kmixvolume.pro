TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(kmixvolumeplugin)

QT = core dbus

SOURCES = kmixvolume.cpp
HEADERS = kmixvolume.h

LIBS += -L../../model -lconfigurationmodel
INCLUDEPATH += ../../model

DESTDIR = ../../target/plugins
