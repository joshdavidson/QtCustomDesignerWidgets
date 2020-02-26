#ifndef PORTMONITOR_H
#define PORTMONITOR_H

#include <QWidget>
#include <QAbstractSocket>

namespace Ui {
class PortMonitor;
}

class PortMonitor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost)
    Q_PROPERTY(int port READ port WRITE setPort)
    Q_PROPERTY(int interval READ interval WRITE setInterval)

public:
    PortMonitor(QWidget *parent = nullptr);

    QString host() const;
    void setHost(const QString &host);

    int port() const;
    void setPort(const int &port);

    int interval() const;
    void setInterval(const int &interval);

public slots:
  void onConnected();
  void performCheck();

protected:
    QString _host;
    int _port;
    int _interval;

private:
    Ui::PortMonitor *m_ui;
    bool m_isUp;
};

#endif // PORTMONITOR_H
