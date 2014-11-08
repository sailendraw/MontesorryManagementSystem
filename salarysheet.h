#ifndef SALARYSHEET_H
#define SALARYSHEET_H

#include <QWidget>
#include "qtrpt.h"
namespace Ui {
class salarysheet;
}

class salarysheet : public QWidget
{
    Q_OBJECT

public:
    explicit salarysheet(QWidget *parent = 0);
    void display();
    ~salarysheet();

private slots:
    void on_month_currentTextChanged(const QString &arg1);

    void on_month_currentIndexChanged(const QString &arg1);

    void on_stafflist_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();
void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

private:
    Ui::salarysheet *ui;
    QtRPT *report;
};

#endif // SALARYSHEET_H
