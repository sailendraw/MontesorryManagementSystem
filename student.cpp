#include "student.h"
#include "ui_student.h"
#include "QDebug"
student::student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    ui->txt_application_no->setReadOnly(true);
   QString dat=ui->txt_application_no->text();
      qDebug()<<dat;
//disp(d);

}

student::~student()
{
    delete ui;
}
void student::disp(QString d)
{
    qDebug()<<d;
}
