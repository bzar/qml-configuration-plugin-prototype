#ifndef CONFIGURATIONVIEW_H
#define CONFIGURATIONVIEW_H

#include <QDeclarativeView>
#include "configurationmodel.h"

class ConfigurationView : public QDeclarativeView
{
    Q_OBJECT
public:
    ConfigurationView(QWidget* parent = 0);

private:
    ConfigurationModel model;
};

#endif // CONFIGURATIONVIEW_H
