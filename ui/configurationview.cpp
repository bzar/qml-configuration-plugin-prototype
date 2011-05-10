#include "configurationview.h"
#include "configurationwidget.h"
#include <QDeclarativeContext>


ConfigurationView::ConfigurationView(QWidget* parent) :
        QDeclarativeView(parent), model()
{
    qmlRegisterType<ConfigurationWidget>("Configuration", 1, 0, "ConfigurationWidget");
    qmlRegisterType<ConfigurationModel>("Configuration", 1, 0, "ConfigurationModel");
    qmlRegisterType<ConfigurationItem>("Configuration", 1, 0, "ConfigurationItem");

    ConfigurationWidget::loadWidgets(engine());
    rootContext()->setContextProperty("configurationModel", &model);
}
