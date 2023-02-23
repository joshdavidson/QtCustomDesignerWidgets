#ifndef CSVVIEWER_H
#define CSVVIEWER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class CsvViewer;
}
class CsvViewer : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString csvPath READ csvPath WRITE setCsvPath)

public:
    CsvViewer(QWidget *parent = 0);
    QString csvPath() const;
    void setCsvPath(const QString &csvPath);

private:
    Ui::CsvViewer *m_ui;
    QStandardItemModel *m_model;
    void loadCsv(QString csvPath);

protected:
    QString _csvPath;

};

#endif
