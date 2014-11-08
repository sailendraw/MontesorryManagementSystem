#include "expenditure.h"
#include "ui_expenditure.h"
#include "QSqlQuery"
#include "QDebug"
Expenditure::Expenditure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Expenditure)
{
    ui->setupUi(this);
    QDate dat;
    ui->dateEdit->setDate(dat.currentDate());
    display();
}

Expenditure::~Expenditure()
{
    delete ui;
}

void Expenditure::on_print_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/Expenditurereport.xml";
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
void Expenditure::display()
{
    QSqlQuery m("SELECT date,expense_heading,Amount FROM `expense`");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()) );
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()) );
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()) );

i++;
    }

}

void Expenditure::on_dateEdit_dateChanged(const QDate &date)
{
    QString dy=date.toString(Qt::ISODate);
    QSqlQuery m("SELECT date,expense_heading,Amount FROM `expense` where date='"+dy+"'");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()) );
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()) );
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()) );

i++;
    }
}
void Expenditure::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
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
