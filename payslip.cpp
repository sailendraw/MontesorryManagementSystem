#include "payslip.h"
#include "ui_payslip.h"
#include "database.h"
#include "QSqlQuery"
#include "QMessageBox"
payslip::payslip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::payslip)
{
    ui->setupUi(this);
    database *db= new database;
    QStringList l=db->stafflist();
    ui->stafflist->addItems(l);
    QStringList month;
    month<<"Baisakh"<<"Jeshtha"<<"Ashad"<<"Shrawan"<<"Bhadra"<<"Ashoj"<<"Kartik"<<"Mangsir"<<"Poush"<<"Magh"<<"Falgun"<<"Chaitra";
ui->month->addItems(month);
displaynumber();
}

payslip::~payslip()
{
    delete ui;
}

void payslip::on_paid_cursorPositionChanged(int arg1, int arg2)
{
    int payable=ui->payable->text().toInt();
    int paid=ui->paid->text().toInt();
    int balance=payable-paid;
    QString bal;
     bal=QString::number(balance);
    if(balance<=0)
    {

        ui->advance->setText(bal);
        ui->balamount->setText(bal);
    }
    else
    {
    ui->balamount->setText(bal);
    }
    ui->balamount->setText(bal);
}

void payslip::on_stafflist_currentTextChanged(const QString &arg1)
{
    database *d=new database;
    QString t=d->staff_salary_amount(arg1);
    ui->payable->setText(t);

}
void payslip::displaynumber()
{
    int i=0;
    QSqlQuery mo("select id from salary ordery by id desc limit 1");
    while(mo.next())
    {
      i=mo.value(0).toString().toInt();
      i=i+1;
    }
    ui->refno->setText(QString::number(i));
    QSqlQuery mt("SELECT DATE, Staff_name, Advance, salary_paid, MONTH , Payable, Balance FROM  `salary`");
    int j=0;
    ui->tableWidget->setRowCount(mt.size());
    while(mt.next())
    {
      ui->tableWidget->setItem(j,0,new QTableWidgetItem(mt.value(0).toString()));
      ui->tableWidget->setItem(j,1,new QTableWidgetItem(mt.value(1).toString()));
      ui->tableWidget->setItem(j,2,new QTableWidgetItem(mt.value(2).toString()));
      ui->tableWidget->setItem(j,3,new QTableWidgetItem(mt.value(3).toString()));
      ui->tableWidget->setItem(j,4,new QTableWidgetItem(mt.value(4).toString()));
      ui->tableWidget->setItem(j,5,new QTableWidgetItem(mt.value(5).toString()));
      ui->tableWidget->setItem(j,6,new QTableWidgetItem(mt.value(6).toString()));
       j++;
    }

}

void payslip::on_pushButton_clicked()
{
    QString staffname=ui->stafflist->currentText();
    QString salarymonth=ui->month->currentText();
    QString dat=ui->dateEdit->date().toString();
    QString adv=ui->advance->text();
    QString paid=ui->paid->text();
    QString payable=ui->payable->text();
    QString balance=ui->balamount->text();
    database *dt=new database;
    int i;
    i=dt->insert_salary(dat,staffname,adv,paid,salarymonth,payable,balance);
    if(i)
    {
        QMessageBox::information(this,"Success","Done",QMessageBox::Ok);
        displaynumber();
    }
    else
    {
        QMessageBox::information(this,"Error","I cannot insert data",QMessageBox::Ok);
    }

}
