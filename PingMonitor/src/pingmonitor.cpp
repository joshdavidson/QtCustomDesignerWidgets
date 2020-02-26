#include "pingmonitor.h"
#include "ui_pingmonitor.h"
#include <QTimer>
#include <QProcess>

PingMonitor::PingMonitor(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::PingMonitor)
{
    m_ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    if(_interval > 0)
    {
        timer->setInterval(_interval);
    } else {
        timer->setInterval(15000);
    }

    QObject::connect(timer, SIGNAL(timeout()),
                     this, SLOT(performCheck()));
    timer->start();
}

QString PingMonitor::host() const
{
    return _host;
}


void PingMonitor::setHost(const QString &host)
{
    _host = host;
}

int PingMonitor::interval() const
{
    return _interval;
}

void PingMonitor::setInterval(const int &interval)
{
    _interval = interval;
}

void PingMonitor::performCheck()
{
    if (!_host.isEmpty())
    {
        QString nParameter = "-n";
        QString pingCount = "1"; //(int)
        QString wParameter = "-w";
        QString pingWaitTime = "10"; //(ms)

        QStringList argList = (QStringList() << _host << nParameter << pingCount << wParameter << pingWaitTime);
        QProcess *pingProcess = new QProcess;
        pingProcess->start("ping", argList);
        pingProcess->closeReadChannel(QProcess::StandardOutput);
        pingProcess->closeReadChannel(QProcess::StandardError);
        int exitCode = pingProcess->exitCode();

        if (exitCode!=0)
        {
            QPixmap pix(":/status-triangle-red-48x48.png");
            m_ui->label->setPixmap(pix);
        } else {
            QPixmap pix(":/status-circle-green-64x64.png");
            m_ui->label->setPixmap(pix);
        }
    }
}

