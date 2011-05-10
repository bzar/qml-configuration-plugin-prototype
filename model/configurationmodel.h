#ifndef CONFIGURATIONMODEL_H
#define CONFIGURATIONMODEL_H

#include <QAbstractListModel>

#include "configurationitem.h"
#include "configurationplugin.h"

class ConfigurationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ConfigurationModel(QObject* parent = 0);

    enum Roles
    {
        Id = Qt::UserRole,
        Label = Qt::UserRole + 1,
        Type = Qt::UserRole + 2,
        Item = Qt::UserRole + 3,
    };

    /** Returns the number of items in this model */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    /** Returns the data at the specified index. */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /** Returns the header for each role */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    void addConfigurationItem(ConfigurationItem* item);

private:
    QList<ConfigurationItem*> items;
    QList<ConfigurationPlugin*> plugins;
};


#endif // CONFIGURATIONMODEL_H
