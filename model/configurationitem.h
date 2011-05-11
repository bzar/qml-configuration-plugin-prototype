#ifndef CONFIGURATIONITEM_H
#define CONFIGURATIONITEM_H

#include <QObject>
#include <QVariant>

class ConfigurationPlugin;

class ConfigurationItem : public QObject
{
    Q_OBJECT
public:
    enum Type {Boolean, Integer, String};

    Q_PROPERTY(int      id    READ getId)
    Q_PROPERTY(int      type  READ getType)
    Q_PROPERTY(QString  label READ getLabel)
    Q_PROPERTY(QVariant value READ getValue WRITE setValue NOTIFY valueChanged)

    ConfigurationItem(QObject *parent = 0);
    ConfigurationItem(ConfigurationItem const& other);
    ConfigurationItem(int const id, Type const type, QString const& label, ConfigurationPlugin* plugin, QVariant initialValue = QVariant(), QObject *parent = 0);

    int getId() const;
    Type getType() const;
    QString getLabel() const;
    QVariant getValue() const;

public slots:
    void setValue(QVariant const& newValue);

signals:
    void valueChanged(QVariant value);

protected:
    ConfigurationPlugin* const plugin;

private:
    int id;
    Type type;
    QString label;
    QVariant value;
};

Q_DECLARE_METATYPE(ConfigurationItem*);

#endif // CONFIGURATIONITEM_H
