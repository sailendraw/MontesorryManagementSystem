#include "new_school.h"
#include "ui_new_school.h"

New_school::New_school(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::New_school)
{
    ui->setupUi(this);
}

New_school::~New_school()
{
    delete ui;
}
