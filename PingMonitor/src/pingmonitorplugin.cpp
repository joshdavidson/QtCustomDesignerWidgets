#include "pingmonitor.h"
#include "pingmonitorplugin.h"

#include <QtPlugin>

PingMonitorPlugin::PingMonitorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void PingMonitorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool PingMonitorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *PingMonitorPlugin::createWidget(QWidget *parent)
{
    return new PingMonitor(parent);
}

QString PingMonitorPlugin::name() const
{
    return QLatin1String("PingMonitor");
}

QString PingMonitorPlugin::group() const
{
    return QLatin1String("System Monitoring");
}

QIcon PingMonitorPlugin::icon() const
{
    return QIcon(QLatin1String(":/ping-pong.png"));
}

QString PingMonitorPlugin::toolTip() const
{
    return QLatin1String("");
}

QString PingMonitorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool PingMonitorPlugin::isContainer() const
{
    return false;
}

QString PingMonitorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"PingMonitor\" name=\"pingMonitor\">\n</widget>\n");
}

QString PingMonitorPlugin::includeFile() const
{
    return QLatin1String("pingmonitor.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(pingmonitorplugin, PingMonitorPlugin)
#endif // QT_VERSION < 0x050000
