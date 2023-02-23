#include "csvviewer.h"
#include "ui_csvviewer.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

CsvViewer::CsvViewer(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::CsvViewer), m_model(new QStandardItemModel)
{
    m_ui->setupUi(this);
    m_ui->tableView->setModel(m_model);
}
QString CsvViewer::csvPath() const
{
    return _csvPath;
}
void CsvViewer::setCsvPath(const QString &csvPath)
{
    _csvPath = csvPath;
    this->loadCsv(_csvPath);
}
void CsvViewer::loadCsv(QString csvPath)
{
    QFile file(csvPath);
    if (file.open(QIODevice::ReadOnly)) {
        int lineindex = 0;      // file line counter
        QTextStream in(&file);  // read to text stream

        while (!in.atEnd()) {
            // read one line from textstream(separated by "\n")
            QString fileLine = in.readLine();

            // parse the read line into separate pieces(tokens) with "," as the delimiter
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++) {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);
                if (lineindex == 0){
                    m_model->setHorizontalHeaderItem(j, item);
                } else {
                    m_model->setItem(lineindex-1, j, item);
                }
            }

            lineindex++;
        }

        file.close();
    }
}
