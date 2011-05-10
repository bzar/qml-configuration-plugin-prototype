#include "configurationwidget.h"


QMap<ConfigurationItem::Type, QDeclarativeComponent*> ConfigurationWidget::widgets;

ConfigurationWidget::ConfigurationWidget(QDeclarativeItem* parent) : QDeclarativeItem(parent), item(0)
{
}

ConfigurationItem* ConfigurationWidget::getItem() const
{
    return item;
}

void ConfigurationWidget::setItem(ConfigurationItem* newItem)
{
    item = newItem;

    if(item && widgets.contains(item->getType()))
    {
        QDeclarativeComponent* widget = widgets.value(item->getType());
        if(widget->isLoading())
        {
            connect(widget, SIGNAL(statusChanged(QDeclarativeComponent::Status)), this, SLOT(reloadContent()));
        }
        else
        {
            reloadContent();
        }
    }
}

void ConfigurationWidget::reloadContent()
{
    if(item && widgets.contains(item->getType()))
    {
        QDeclarativeComponent* widget = widgets.value(item->getType());

        childItems().clear();

        if(widget->isError())
        {
            qWarning() << widget->errors();
            return;
        }
        else
        {
            QDeclarativeItem* content = qobject_cast<QDeclarativeItem*>(widgets.value(item->getType())->create());
            content->setProperty("configurationItem", QVariant::fromValue<ConfigurationItem*>(item));
            content->setParentItem(this);
        }
    }
}

void ConfigurationWidget::loadWidgets(QDeclarativeEngine* engine)
{
    widgets[ConfigurationItem::Boolean] = new QDeclarativeComponent(engine, QUrl::fromLocalFile("widgets/boolean.qml"));
    widgets[ConfigurationItem::Integer] = new QDeclarativeComponent(engine, QUrl::fromLocalFile("widgets/integer.qml"));
    widgets[ConfigurationItem::String] = new QDeclarativeComponent(engine, QUrl::fromLocalFile("widgets/string.qml"));
}
