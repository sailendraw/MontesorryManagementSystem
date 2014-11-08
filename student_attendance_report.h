#ifndef STUDENT_ATTENDANCE_REPORT_H
#define STUDENT_ATTENDANCE_REPORT_H

#include <QWidget>

namespace Ui {
class student_attendance_report;
}

class student_attendance_report : public QWidget
{
    Q_OBJECT

public:
    explicit student_attendance_report(QWidget *parent = 0);
    ~student_attendance_report();

private slots:
    void on_printbtn_clicked();

private:
    Ui::student_attendance_report *ui;
};

#endif // STUDENT_ATTENDANCE_REPORT_H
