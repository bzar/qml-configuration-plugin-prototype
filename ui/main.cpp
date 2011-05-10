#include <QApplication>
#include "configurationview.h"
#include "configurationmodel.h"
#include "configurationwidget.h"
#include "configurationitem.h"

int main(int argc, char** argv)
{
    QApplication::setGraphicsSystem("raster");
    const QApplication a(argc, argv);

    ConfigurationView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return a.exec();
}
