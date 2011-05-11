#ifndef INTEGERCONFIGURATIONITEM_H
#define INTEGERCONFIGURATIONITEM_H

#include "configurationitem.h"

class IntegerConfigurationItem : public ConfigurationItem
{
    Q_OBJECT
public:
    Q_PROPERTY(int      minValue    READ getMinValue NOTIFY minValueChanged)
    Q_PROPERTY(int      maxValue    READ getMaxValue NOTIFY maxValueChanged)

    IntegerConfigurationItem(QObject *parent = 0);
    IntegerConfigurationItem(IntegerConfigurationItem const& other);
    IntegerConfigurationItem(int const id, QString const& label, ConfigurationPlugin* plugin, int initialValue = 0, int const minValue = 0, int const maxValue = 100, QObject *parent = 0);

    int getMinValue();
    int getMaxValue();

signals:
    void minValueChanged(int newValue);
    void maxValueChanged(int newValue);
public slots:
    void setValue(int newValue);

private:
    int minValue;
    int maxValue;
};

#endif // INTEGERCONFIGURATIONITEM_H
