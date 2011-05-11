#include "test.h"

#include <QtPlugin>

TestConfigurationPlugin::TestConfigurationPlugin() :
    booleanItem(0, ConfigurationItem::Boolean, "Boolean item", this, false),
    integerItem(1, "Integer item", this, 50, -200, 200),
    stringItem(2, ConfigurationItem::String, "String item", this, "Hello World!")
{

}

void TestConfigurationPlugin::initialize(ConfigurationModel* model)
{
    model->addConfigurationItem(&booleanItem);
    model->addConfigurationItem(&integerItem);
    model->addConfigurationItem(&stringItem);
}

void TestConfigurationPlugin::finalize(ConfigurationModel* model)
{

}

void TestConfigurationPlugin::set(int settingId, QVariant value)
{
    switch(settingId)
    {
    case 0: qDebug(QString("Boolean setting set to value %1").arg(value.toBool() ? "true" : "false").toAscii()); break;
    case 1: qDebug(QString("Integer setting set to value %1").arg(value.toInt()).toAscii()); break;
    case 2: qDebug(QString("String setting set to value %1").arg(value.toString()).toAscii()); break;
    default: break;
    }
}

Q_EXPORT_PLUGIN2(testplugin, TestConfigurationPlugin)
