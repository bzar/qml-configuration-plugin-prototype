TEMPLATE = subdirs
SUBDIRS = ui \
    plugins \
    model

ui.subdir = ui
ui.depends = model

plugins.subdir = plugins
plugins.depends = model

model.subdir = model

OTHER_FILES = target/widgets/boolean.qml target/widgets/integer.qml target/widgets/string.qml
