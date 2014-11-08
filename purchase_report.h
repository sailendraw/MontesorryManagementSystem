#ifndef PURCHASE_REPORT_H
#define PURCHASE_REPORT_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class purchase_report;
}

class purchase_report : public QWidget
{
    Q_OBJECT

public:
    explicit purchase_report(QWidget *parent = 0);
    ~purchase_report();

private slots:
    void on_pushButton_3_clicked();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::purchase_report *ui;
    QtRPT *report;
};

#endif // PURCHASE_REPORT_H
