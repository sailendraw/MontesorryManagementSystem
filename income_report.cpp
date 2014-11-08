#include "income_report.h"
#include "ui_income_report.h"
#include "QSqlQuery"
#include "QDebug"
Income_Report::Income_Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Income_Report)
{
    ui->setupUi(this);
    QDate *dt;
    ui->dateEdit->setDate(dt->currentDate());
    display();
}

Income_Report::~Income_Report()
{
    delete ui;
}
void Income_Report::display()
{
   QSqlQuery m("select Date,Particulars,Amount from income");
   int size=m.size();
   int i=0;
   ui->tableWidget->setRowCount(size);
   while(m.next())
   {
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
       i++;
   }
}

void Income_Report::on_dateEdit_dateChanged(const QDate &date)
{
    QString dte=date.toString();
    QSqlQuery m("select Date,Particulars,Amount from income where Date='"+dte+"'");
    int size=m.size();
    int i=0;
    ui->tableWidget->setRowCount(size);
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        i++;
    }


}

void Income_Report::on_Print_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/incomereport.xml";
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
void Income_Report::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);

         if (paramName == "SN")
            paramValue = recNo+1;
        if (paramName == "Date") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "Particulars") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "Amount") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }

}
