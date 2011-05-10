TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(testplugin)

SOURCES = test.cpp
HEADERS = test.h

LIBS += -L../../model -lconfigurationmodel
INCLUDEPATH += ../../model

DESTDIR = ../../target/plugins
