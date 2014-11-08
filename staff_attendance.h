#ifndef STAFF_ATTENDANCE_H
#define STAFF_ATTENDANCE_H

#include <QWidget>

namespace Ui {
class staff_attendance;
}

class staff_attendance : public QWidget
{
    Q_OBJECT

public:
    explicit staff_attendance(QWidget *parent = 0);
    ~staff_attendance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::staff_attendance *ui;
};

#endif // STAFF_ATTENDANCE_H
