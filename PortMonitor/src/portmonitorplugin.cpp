#include "portmonitor.h"
#include "portmonitorplugin.h"

#include <QtPlugin>

PortMonitorPlugin::PortMonitorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void PortMonitorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool PortMonitorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *PortMonitorPlugin::createWidget(QWidget *parent)
{
    return new PortMonitor(parent);
}

QString PortMonitorPlugin::name() const
{
    return QLatin1String("PortMonitor");
}

QString PortMonitorPlugin::group() const
{
    return QLatin1String("System Monitoring");
}

QIcon PortMonitorPlugin::icon() const
{
    return QIcon(QLatin1String(":/monitoring.png"));
}

QString PortMonitorPlugin::toolTip() const
{
    return QLatin1String("Monitors if port on host is open and available");
}

QString PortMonitorPlugin::whatsThis() const
{
    return QLatin1String("PortMonitor can be used to monitor various applications by verifying a given host's port is open and available.");
}

bool PortMonitorPlugin::isContainer() const
{
    return false;
}

QString PortMonitorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"PortMonitor\" name=\"portMonitor\">\n</widget>\n");
}

QString PortMonitorPlugin::includeFile() const
{
    return QLatin1String("portmonitor.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(portmonitorplugin, PortMonitorPlugin)
#endif // QT_VERSION < 0x050000
