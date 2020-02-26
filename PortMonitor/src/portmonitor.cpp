#include "portmonitor.h"
#include "ui_portmonitor.h"
#include <QTcpSocket>
#include <QTimer>

PortMonitor::PortMonitor(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::PortMonitor)
{
    m_ui->setupUi(this);
    m_isUp = false;

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

QString PortMonitor::host() const
{
    return _host;
}

void PortMonitor::setHost(const QString &host)
{
    _host = host;
}

int PortMonitor::interval() const
{
    return _interval;
}

void PortMonitor::setInterval(const int &interval)
{
    _interval = interval;
}

int PortMonitor::port() const
{
    return _port;
}

void PortMonitor::setPort(const int &port)
{
    _port = port;
}

void PortMonitor::performCheck()
{
    if ((!_host.isEmpty()) && (_port >= 0) && (_port <= 65535)) {
        QTcpSocket *socket = new QTcpSocket();
        socket->connectToHost(_host,  static_cast<quint16>(_port));
        QObject::connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));

        QPixmap pix(":/status-triangle-red-48x48.png");
        if(!socket->waitForConnected(500)){
            qDebug() << "Unable to connect to:" << _host << "on port:" << _port;
            m_ui->label->setPixmap(pix);
        }
        connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                [=](QAbstractSocket::SocketError socketError){
            qDebug() << "Error connecting to:" << _host << "on port:" << _port;
            qDebug() << socketError;
            m_ui->label->setPixmap(pix);
        });
        socket->disconnect();
    } else {
        m_isUp = false;
    }
}

void PortMonitor::onConnected()
{
    m_isUp = true;
    QPixmap pix(":/status-circle-green-64x64.png");
    m_ui->label->setPixmap(pix);
}
