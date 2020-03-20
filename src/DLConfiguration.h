#ifndef DLCONFIGURATION_H
#define DLCONFIGURATION_H

#include <QSettings>
#include <QString>

class DLConfig
{
public:
    DLConfig(const QString name);
    void loadConfig();
    void reloadConfig();
    void saveConfig();
    void set(const QString &category, const QString &key, const QVariant &value);
    QVariant get(const QString &category, const QString &key);
    QVariant get(const QString &category, const QString &key, const QVariant &defaultValue);
    QVector<QString> m_games;

private:
    QString m_fileName;
    QSettings m_settings;

};

#endif // DLCONFIGURATION_H
