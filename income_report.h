#ifndef INCOME_REPORT_H
#define INCOME_REPORT_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class Income_Report;
}

class Income_Report : public QWidget
{
    Q_OBJECT

public:
    explicit Income_Report(QWidget *parent = 0);
    void display();
    ~Income_Report();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

    void on_Print_clicked();

private:
    Ui::Income_Report *ui;
    QtRPT *report;
};

#endif // INCOME_REPORT_H
