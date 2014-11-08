#include "sales_report.h"
#include "ui_sales_report.h"
#include "database.h"
#include "QSqlQuery"
#include "QDebug"
#include "QPrinter"
#include "qtrpt.h"
sales_report::sales_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sales_report)
{
    ui->setupUi(this);
    QDate *dat=new QDate;
    ui->dateEdit->setDate(dat->currentDate());
display();
}

sales_report::~sales_report()
{
    delete ui;
}
void sales_report::display()
{
QSqlQuery m("select date,product,qty,total from stock_sales");
int size=m.size();
ui->tableWidget->setRowCount(size);
int i=0;
while(m.next())
{
   ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
   ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
   ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
   ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
   i++;
}
}

void sales_report::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString pname=ui->lineEdit->text();
    if(pname=="")
    {
        QSqlQuery m("select date,product,qty,total from stock_sales");
        int size=m.size();
        ui->tableWidget->setRowCount(size);
        int i=0;
        while(m.next())
        {
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
           i++;
        }
    }
    else
    {
        QSqlQuery m("select date,product,qty,total from stock_sales where product='"+pname+"'");
        int size=m.size();
        ui->tableWidget->setRowCount(size);
        int i=0;
        while(m.next())
        {
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
           i++;
        }
    }
}

void sales_report::on_dateEdit_userDateChanged(const QDate &date)
{

}

void sales_report::on_dateEdit_dateChanged(const QDate &date)
{
    QString name=date.toString();
     QSqlQuery m("select date,product,qty,total from stock_sales where date='"+name+"'");
     int size=m.size();
     ui->tableWidget->setRowCount(size);
     int i=0;
     while(m.next())
     {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        i++;
 }
    qDebug()<<"date is changed"<<name;
}

void sales_report::on_pushButton_3_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/salesreport.xml";
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
void sales_report::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);

         if (paramName == "SN")
            paramValue = recNo+1;
        if (paramName == "Date") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "Product") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "Qty") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }
        if (paramName == "Total") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }

}
