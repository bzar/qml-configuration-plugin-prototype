#ifndef TESTCONFIGURATIONPLUGIN_H
#define TESTCONFIGURATIONPLUGIN_H

#include "configurationplugin.h"
#include "configurationitem.h"
#include "configurationmodel.h"

#include <QObject>

class TestConfigurationPlugin : public QObject, public ConfigurationPlugin
{
    Q_OBJECT
    Q_INTERFACES(ConfigurationPlugin)
public:
    TestConfigurationPlugin();
    void initialize(ConfigurationModel* model);
    void finalize(ConfigurationModel* model);
    void set(int settingId, QVariant value);

private:
    ConfigurationItem booleanItem;
    ConfigurationItem integerItem;
    ConfigurationItem stringItem;
};

#endif
