#ifndef STAFF_ATTENDANCE_REPORT_H
#define STAFF_ATTENDANCE_REPORT_H

#include <QWidget>
#include "qtrpt.h"
namespace Ui {
class staff_attendance_report;
}

class staff_attendance_report : public QWidget
{
    Q_OBJECT

public:
    explicit staff_attendance_report(QWidget *parent = 0);
    void display();
    ~staff_attendance_report();

private slots:
    void on_pushButton_clicked();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::staff_attendance_report *ui;
    QtRPT *report;
};

#endif // STAFF_ATTENDANCE_REPORT_H
