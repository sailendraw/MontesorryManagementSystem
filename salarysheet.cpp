#include "salarysheet.h"
#include "ui_salarysheet.h"
#include "database.h"
#include "QSqlQuery"
#include "QDebug"
salarysheet::salarysheet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::salarysheet)
{
    ui->setupUi(this);
    database *dt=new database;
    ui->stafflist->addItems(dt->stafflist());
    QStringList month;
    month<<"Baisakh"<<"Jestha"<<"Ashad"<<"Shrawan"<<"Bhadra"<<"Ashoj"<<"Kartik"<<"Mangsir"<<"Poush"<<"Magh"<<"Falgun"<<"chaitra";
    ui->month->addItems(month);
    QDate dat;
    ui->dateEdit->setDate(dat.currentDate());
    display();
}

salarysheet::~salarysheet()
{
    delete ui;
}
void salarysheet::display()
{
    QSqlQuery m("SELECT DATE, staff_name, salary_paid, MONTH , payable, balance FROM  `salary");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(m.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(m.value(5).toString()));
        i++;
    }
}

void salarysheet::on_month_currentTextChanged(const QString &arg1)
{

}

void salarysheet::on_month_currentIndexChanged(const QString &arg1)
{
    QSqlQuery m("SELECT DATE, Staff_name, Advance, salary_paid,MONTH , payable, Balance FROM  `salary` WHERE MONTH =  '"+arg1+"'");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(m.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(m.value(5).toString()));
        i++;
    }
    qDebug()<<arg1;

}

void salarysheet::on_stafflist_currentIndexChanged(const QString &arg1)
{
    QSqlQuery m("SELECT DATE, Staff_name, Advance, salary_paid,MONTH , payable, Balance FROM  `salary` WHERE Staff_name =  '"+arg1+"'");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(m.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(m.value(5).toString()));
        i++;
    }
    qDebug()<<arg1;
}

void salarysheet::on_pushButton_3_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/salarysheetreport.xml";
              report = new QtRPT(this);
             // report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
              report->recordCount << ui->tableWidget->rowCount();
              if (report->loadReport(fileName) == false) {
                  qDebug()<<"Report's file not found";
              }
              QObject::connect(report, SIGNAL(setValue(int&, QString&, QVariant&, int)),
                               this, SLOT(setValue(int&, QString&, QVariant&, int)));
             // QObject::connect(report, SIGNAL(setValueImage(int&, QString&, QImage&, int)),
               //                this, SLOT(setValueImage(int&, QString&, QImage&, int)));
            //report->printPDF("test.pdf",true);
              report->printExec(true);
}
void salarysheet::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);

         if (paramName == "SN")
            paramValue = recNo+1;
        if (paramName == "Date") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "StaffName") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "Advance") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }
        if (paramName == "Paid") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }
        if (paramName == "Month") {
            if (ui->tableWidget->item(recNo,4) == 0) return;
            paramValue = ui->tableWidget->item(recNo,4)->text();
        }
        if (paramName == "Payable") {
            if (ui->tableWidget->item(recNo,5) == 0) return;
            paramValue = ui->tableWidget->item(recNo,5)->text();
        }
        if (paramName == "Balance") {
            if (ui->tableWidget->item(recNo,6) == 0) return;
            paramValue = ui->tableWidget->item(recNo,6)->text();
        }
}
