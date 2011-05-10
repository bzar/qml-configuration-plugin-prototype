#ifndef CONFIGURATIONPLUGIN_H
#define CONFIGURATIONPLUGIN_H

#include <QVariant>

class ConfigurationModel;

class ConfigurationPlugin
{
public:
    virtual ~ConfigurationPlugin() {}
    virtual void initialize(ConfigurationModel* model) = 0;
    virtual void finalize(ConfigurationModel* model) = 0;

    virtual void set(int settingId, QVariant value) = 0;
};

Q_DECLARE_INTERFACE(ConfigurationPlugin, "fi.iki.bzar.Panorama.ConfigurationPlugin/1.0")
#endif // CONFIGURATIONPLUGIN_H
