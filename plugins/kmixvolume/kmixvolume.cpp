#include "kmixvolume.h"

#include <QtPlugin>
#include <QDebug>
#include <QDBusError>
#include <QDBusMessage>

#include <QTimer>

KMixVolumeConfigurationPlugin::KMixVolumeConfigurationPlugin() :
        masterVolume(0, "Master volume", this, 0, 0, 100),
        dbus(QDBusConnection::sessionBus())
{
    // The signal needed to monitor volume changes is not yet integrated https://svn.reviewboard.kde.org/r/6587/
    // so a temporary solution is required
    /*if(!dbus.connect("org.kde.kmix", "/Mixer0", "org.kde.KMix", "masterVolume", &masterVolume, SLOT(setValue(int))))
    {
        qWarning() << "Error connecting to kmix dbus interface: " << dbus.lastError().name() << ": " << dbus.lastError().message();
    }
    else
    {
        qDebug() << "Connected to kmix dbus interface";
    }*/

    QTimer* refreshTimer = new QTimer(this);
    refreshTimer->setInterval(1000);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refreshMasterVolume()));
    refreshTimer->start();
}

void KMixVolumeConfigurationPlugin::initialize(ConfigurationModel* model)
{
    model->addConfigurationItem(&masterVolume);
}

void KMixVolumeConfigurationPlugin::finalize(ConfigurationModel* model)
{
    dbus.disconnectFromBus("session");
}

void KMixVolumeConfigurationPlugin::set(int settingId, QVariant value)
{
    if(settingId == MasterVolume)
    {
        setMasterVolume(value.toInt());
    }
}

void KMixVolumeConfigurationPlugin::setMasterVolume(int value)
{
    qDebug() << "Master volume set to " << value;
    QDBusMessage message = QDBusMessage::createMethodCall("org.kde.kmix", "/Mixer0", "org.kde.KMix", "setMasterVolume");
    QList<QVariant> arguments;
    arguments << value + 1;
    message.setArguments(arguments);
    dbus.call(message, QDBus::NoBlock);
}

void KMixVolumeConfigurationPlugin::refreshMasterVolume()
{
    QDBusMessage message = QDBusMessage::createMethodCall("org.kde.kmix", "/Mixer0", "org.kde.KMix", "masterVolume");
    QDBusMessage reply = dbus.call(message, QDBus::Block);
    int newVolume = reply.arguments().at(0).toInt();
    if(newVolume != masterVolume.getValue().toInt())
    {
        masterVolume.setValue(newVolume);
    }
}

Q_EXPORT_PLUGIN2(kmixvolumeplugin, KMixVolumeConfigurationPlugin)

