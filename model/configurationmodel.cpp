#include "configurationmodel.h"

#include <QDir>
#include <QPluginLoader>
#include <QDebug>

ConfigurationModel::ConfigurationModel(QObject* parent) : QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[ConfigurationModel::Id]    = QString("identifier").toLocal8Bit();
    roles[ConfigurationModel::Type]  = QString("type")      .toLocal8Bit();
    roles[ConfigurationModel::Label] = QString("label")   .toLocal8Bit();
    roles[ConfigurationModel::Item]  = QString("configurationItem")      .toLocal8Bit();

    setRoleNames(roles);

    QDir pluginDir("plugins");

    foreach(QString pluginFile, pluginDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(pluginFile));
        QObject* instance = pluginLoader.instance();
        if(instance)
        {
            ConfigurationPlugin* plugin = qobject_cast<ConfigurationPlugin*>(instance);
            plugin->initialize(this);
            plugins.append(plugin);
        }
        else
        {
            qWarning() << "Could not load plugin: " << pluginDir.absoluteFilePath(pluginFile);
            qWarning() << pluginLoader.errorString();
        }
    }
}

int ConfigurationModel::rowCount(const QModelIndex &parent) const
{
    return items.size();
}


QVariant ConfigurationModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && index.row() < items.size())
    {
        ConfigurationItem* item = items[index.row()];
        switch(role)
        {
        case ConfigurationModel::Id:
            return item->getId();
        case ConfigurationModel::Label:
            return item->getLabel();
        case ConfigurationModel::Type:
            return item->getType();
        case ConfigurationModel::Item:
            return QVariant::fromValue(item);
        default:
            return QVariant();
        }
    }
    else
    {
        return QVariant();
    }
}


QVariant ConfigurationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(role)
    {
    case ConfigurationModel::Id:
        return QString("Id");
    case ConfigurationModel::Label:
        return QString("Label");
    case ConfigurationModel::Type:
        return QString("Type");
    case ConfigurationModel::Item:
        return QString("ConfigurationItem");
    default:
        return QVariant();
    }
}

void ConfigurationModel::addConfigurationItem(ConfigurationItem* item)
{
    items.append(item);
}
