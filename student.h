#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

namespace Ui {
class student;
}

class student : public QWidget
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);

      void disp(QString);
    ~student();

public:
    Ui::student *ui;
};

#endif // STUDENT_H
