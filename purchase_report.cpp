#include "purchase_report.h"
#include "ui_purchase_report.h"
#include "QSqlQueryModel"
#include "QDebug"
#include "QHeaderView"
#include "QTableWidgetItem"
 QSqlQueryModel *mdel;
 QStringList dlist;
purchase_report::purchase_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::purchase_report)
{
    ui->setupUi(this);

   QTableWidgetItem *item;
   QSqlQuery query("SELECT   `Date` ,  `Product` ,  `Vendor` ,  `Qty` ,  `Amount`  FROM  `stock_add`");
    int row=query.size();
    QDate dt;
    ui->dateEdit->setDate(dt.currentDate());
    int index=0;
     ui->tableWidget->setRowCount(row);
    while (query.next()) {

                  ui-> tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
                ui->tableWidget->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
               ui-> tableWidget->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
                   index++;

                  }
}

purchase_report::~purchase_report()
{
    delete ui;
}
void purchase_report::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
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
        if (paramName == "Vendor") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }
        if (paramName == "Qty") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }
        if (paramName == "Amt") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }
}

void purchase_report::on_pushButton_3_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/purchasereport.xml";
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
              //report->printPreview();
              report->printExec();
}

void purchase_report::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString text=ui->lineEdit->text();
    if(text=="")
    {
    }
    else
    {
    QSqlQuery query("SELECT   `Date` ,  `Product` ,  `Vendor` ,  `Qty` ,  `Amount`  FROM  `stock_add` where product='"+text+"' or Vendor='"+text+"'");
     int row=query.size();
     QDate dt;
     ui->dateEdit->setDate(dt.currentDate());
     int index=0;
      ui->tableWidget->setRowCount(row);
     while (query.next()) {

                   ui-> tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
                 ui->tableWidget->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
                 ui->tableWidget->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
                 ui->tableWidget->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
                ui-> tableWidget->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
                    index++;

                   }
    }
}
