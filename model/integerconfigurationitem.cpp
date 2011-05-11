#include "integerconfigurationitem.h"

IntegerConfigurationItem::IntegerConfigurationItem(QObject *parent) :
        ConfigurationItem(parent), minValue(0), maxValue(100)
{
}

IntegerConfigurationItem::IntegerConfigurationItem(IntegerConfigurationItem const& other) :
        ConfigurationItem(other), minValue(other.minValue), maxValue(other.maxValue)
{
}

IntegerConfigurationItem::IntegerConfigurationItem(int const id, QString const& label, ConfigurationPlugin* plugin, int initialValue, int const minValue, int const maxValue, QObject *parent) :
        ConfigurationItem(id, ConfigurationItem::Integer, label, plugin, initialValue, parent), minValue(minValue), maxValue(maxValue)
{
}

int IntegerConfigurationItem::getMinValue()
{
    return minValue;
}

int IntegerConfigurationItem::getMaxValue()
{
    return maxValue;
}

