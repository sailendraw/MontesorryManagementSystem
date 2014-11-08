#ifndef STUDENT_ATTENDANCE_H
#define STUDENT_ATTENDANCE_H

#include <QWidget>

namespace Ui {
class student_attendance;
}

class student_attendance : public QWidget
{
    Q_OBJECT

public:
    explicit student_attendance(QWidget *parent = 0);
    void studentattendance();
    ~student_attendance();

private slots:
    void on_selectclass_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::student_attendance *ui;
};

#endif // STUDENT_ATTENDANCE_H
