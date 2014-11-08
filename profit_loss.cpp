#include "profit_loss.h"
#include "ui_profit_loss.h"
#include "QSqlQuery"
#include "QTableWidgetItem"
#include "qtrpt.h"
profit_loss::profit_loss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profit_loss)
{
    ui->setupUi(this);
}

profit_loss::~profit_loss()
{
    delete ui;
}

void profit_loss::on_pushButton_clicked()
{
    QTableWidgetItem *item;
    QSqlQuery query("select product,amount from stock_add union select expense_Heading,amount from expense");
    QSqlQuery qr("SELECT Particulars, Amount FROM fee_submission UNION ALL SELECT product AS particulars, amount FROM stock_sales");
     int row=query.size();
     QDate dt;
     ui->dateEdit->setDate(dt.currentDate());
     int index=0;
      ui->tableWidget->setRowCount(row);
     while (query.next() && qr.next()) {

                 ui-> tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
                 ui->tableWidget->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
               ui->tableWidget->setItem(index,2,new QTableWidgetItem(qr.value(0).toString()));
                ui->tableWidget->setItem(index,3,new QTableWidgetItem(qr.value(1).toString()));
                  index++;



                   }
     print();
}
void profit_loss::print()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/profitloss.xml";
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

void profit_loss::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{

    Q_UNUSED(reportPage);

         if (paramName == "S.N")
            paramValue = recNo+1;
        if (paramName == "Expenditure") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "exAmount") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "Income") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }
        if (paramName == "inAmount") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }

}
