#ifndef CREATE_SALARY_H
#define CREATE_SALARY_H

#include <QWidget>

namespace Ui {
class create_salary;
}

class create_salary : public QWidget
{
    Q_OBJECT

public:
    explicit create_salary(QWidget *parent = 0);
    ~create_salary();

private:
    Ui::create_salary *ui;
};

#endif // CREATE_SALARY_H
