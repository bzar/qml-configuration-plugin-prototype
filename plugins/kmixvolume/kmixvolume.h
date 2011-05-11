#ifndef KMIXVOLUMECONFIGURATIONPLUGIN_H
#define KMIXVOLUMECONFIGURATIONPLUGIN_H

#include "configurationplugin.h"
#include "configurationitem.h"
#include "integerconfigurationitem.h"
#include "configurationmodel.h"

#include <QObject>
#include <QDBusConnection>

class KMixVolumeConfigurationPlugin : public QObject, public ConfigurationPlugin
{
    Q_OBJECT
    Q_INTERFACES(ConfigurationPlugin)
public:
    KMixVolumeConfigurationPlugin();
    void initialize(ConfigurationModel* model);
    void finalize(ConfigurationModel* model);
    void set(int settingId, QVariant value);

public slots:
    void setMasterVolume(int value);

private slots:
    void refreshMasterVolume();

private:
    enum Settings { MasterVolume };

    IntegerConfigurationItem masterVolume;
    QDBusConnection dbus;
};

#endif
