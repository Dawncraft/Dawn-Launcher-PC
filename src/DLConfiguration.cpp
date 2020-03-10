#include "DLConfiguration.h"

DLConfig::DLConfig(const QString name) : m_fileName(name), m_settings(name)
{
    m_settings.setIniCodec("UTF8");
    loadConfig();
    saveConfig();
}

void DLConfig::loadConfig()
{

}

void DLConfig::reloadConfig()
{

}

void DLConfig::saveConfig()
{
    m_settings.sync();
}

void DLConfig::set(const QString &category, const QString &key, const QVariant &value)
{
    m_settings.setValue(category + "/" + key, value);
}

QVariant DLConfig::get(const QString &category, const QString &key)
{
    return m_settings.value(category + "/" + key);
}

QVariant DLConfig::get(const QString &category, const QString &key, const QVariant &defaultValue)
{
    return m_settings.value(category + "/" + key, defaultValue);
}
