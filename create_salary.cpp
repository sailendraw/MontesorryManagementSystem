#include "create_salary.h"
#include "ui_create_salary.h"

create_salary::create_salary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_salary)
{
    ui->setupUi(this);
}

create_salary::~create_salary()
{
    delete ui;
}
