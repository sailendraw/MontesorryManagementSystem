#ifndef SALES_REPORT_H
#define SALES_REPORT_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class sales_report;
}

class sales_report : public QWidget
{
    Q_OBJECT

public:
    explicit sales_report(QWidget *parent = 0);
    void display();
    ~sales_report();

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_3_clicked();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

private:
    Ui::sales_report *ui;
    QtRPT *report;
};

#endif // SALES_REPORT_H
