#include "student_attendance_report.h"
#include "ui_student_attendance_report.h"
#include "database.h"
database *dta=new database;
student_attendance_report::student_attendance_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_attendance_report)
{
    ui->setupUi(this);
    ui->classlist->addItems(dta->classlist());
    ui->studentlist->addItems(dta->studentlist(ui->studentlist->currentText()));
}

student_attendance_report::~student_attendance_report()
{
    delete ui;
}

void student_attendance_report::on_printbtn_clicked()
{

}
