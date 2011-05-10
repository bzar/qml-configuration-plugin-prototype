QT += declarative

TARGET = configuration-test
DESTDIR = ../target

SOURCES += \
    main.cpp \
    configurationwidget.cpp \
    configurationview.cpp

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    main.qml

HEADERS += \
    configurationplugin.h \
    configurationmodel.h \
    configurationitem.h \
    configurationwidget.h \
    configurationview.h

INCLUDEPATH += ../model
LIBS += -L ../model -lconfigurationmodel
