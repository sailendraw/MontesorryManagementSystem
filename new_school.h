#ifndef NEW_SCHOOL_H
#define NEW_SCHOOL_H

#include <QWidget>

namespace Ui {
class New_school;
}

class New_school : public QWidget
{
    Q_OBJECT

public:
    explicit New_school(QWidget *parent = 0);
    ~New_school();

private:
    Ui::New_school *ui;
};

#endif // NEW_SCHOOL_H
