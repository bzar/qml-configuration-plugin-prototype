#include "configurationitem.h"
#include "configurationplugin.h"

ConfigurationItem::ConfigurationItem() :
        QObject(), plugin(0), id(0), type(ConfigurationItem::String), label(""), value()
{
}

ConfigurationItem::ConfigurationItem(ConfigurationItem const& other) :
        plugin(other.plugin), id(other.id), type(other.type), label(other.label), value(other.value)
{
}

ConfigurationItem::ConfigurationItem(int const id, Type const type, QString const& label,
                                     ConfigurationPlugin* plugin, QVariant initialValue) :
        plugin(plugin), id(id), type(type), label(label), value(initialValue)
{
}

int ConfigurationItem::getId() const
{
    return id;
}

ConfigurationItem::Type ConfigurationItem::getType() const
{
    return type;
}

QString ConfigurationItem::getLabel() const
{
    return label;
}

QVariant ConfigurationItem::getValue() const
{
    return value;
}

void ConfigurationItem::setValue(QVariant const& newValue)
{
    value = newValue;

    if(plugin)
    {
        plugin->set(id, newValue);
    }
}
