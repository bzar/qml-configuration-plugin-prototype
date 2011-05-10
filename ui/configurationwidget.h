#ifndef CONFIGURATIONWIDGET_H
#define CONFIGURATIONWIDGET_H

#include <QDeclarativeItem>
#include <QDeclarativeComponent>
#include <QMap>
#include "configurationitem.h"

class ConfigurationWidget : public QDeclarativeItem
{
    Q_OBJECT
public:
    Q_PROPERTY(ConfigurationItem* item READ getItem WRITE setItem NOTIFY itemChanged)

    ConfigurationWidget(QDeclarativeItem* parent = 0);

    ConfigurationItem* getItem() const;
    void setItem(ConfigurationItem* newItem);

    static void loadWidgets(QDeclarativeEngine* engine);

signals:
    void itemChanged();

private slots:
    void reloadContent();

private:
    ConfigurationItem* item;

    static QMap<ConfigurationItem::Type, QDeclarativeComponent*> widgets;
};

#endif // CONFIGURATIONWIDGET_H
