#include "csvviewer.h"
#include "csvviewerplugin.h"

#include <QtPlugin>

CsvViewerPlugin::CsvViewerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CsvViewerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CsvViewerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CsvViewerPlugin::createWidget(QWidget *parent)
{
    return new CsvViewer(parent);
}

QString CsvViewerPlugin::name() const
{
    return QLatin1String("CSV Viewer");
}

QString CsvViewerPlugin::group() const
{
    return QLatin1String("Utilities");
}

QIcon CsvViewerPlugin::icon() const
{
    return QIcon(QLatin1String(":/csv-file.png"));
}

QString CsvViewerPlugin::toolTip() const
{
    return QLatin1String("This widget displays a CSV file in a table");
}

QString CsvViewerPlugin::whatsThis() const
{
    return QLatin1String("CsvViewer allows you to display CSV data on your UI");
}

bool CsvViewerPlugin::isContainer() const
{
    return false;
}

QString CsvViewerPlugin::domXml() const
{
    return QLatin1String("<widget class=\"CsvViewer\" name=\"csvViewer\">\n</widget>\n");
}

QString CsvViewerPlugin::includeFile() const
{
    return QLatin1String("csvviewer.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(csvviewerplugin, CsvViewerPlugin)
#endif // QT_VERSION < 0x050000
