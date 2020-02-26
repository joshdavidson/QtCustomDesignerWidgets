#ifndef PINGMONITOR_H
#define PINGMONITOR_H

#include <QWidget>

namespace Ui {
class PingMonitor;
}

class PingMonitor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost)
    Q_PROPERTY(int interval READ interval WRITE setInterval)

public:
    PingMonitor(QWidget *parent = nullptr);

    QString host() const;
    void setHost(const QString &host);

    int interval() const;
    void setInterval(const int &interval);


public slots:
    void performCheck();

private:
    Ui::PingMonitor *m_ui;

protected:
    QString _host;
    int _interval;
};

#endif // PINGMONITOR_H
