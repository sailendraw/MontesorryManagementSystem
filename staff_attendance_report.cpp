#include "staff_attendance_report.h"
#include "ui_staff_attendance_report.h"
#include "QSqlQuery"
#include "database.h"
staff_attendance_report::staff_attendance_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staff_attendance_report)
{
    ui->setupUi(this);
    display();
    database *dt=new database;
    ui->comboBox->addItems(dt->stafflist());
}

staff_attendance_report::~staff_attendance_report()
{
    delete ui;
}

void staff_attendance_report::on_pushButton_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/staff_attendance_report.xml";
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
void staff_attendance_report::display()
{
QSqlQuery m("select staff_name,Date,Status from staff_attendance");
int size=m.size();
ui->tableWidget->setRowCount(size);
int i=0;
while(m.next())
{
   ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
   ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
   ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
   i++;
}
}
void staff_attendance_report::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);


            if (paramName == "Market") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
            if (paramName == "Date") {
                if (ui->tableWidget->item(recNo,1) == 0) return;
                paramValue = ui->tableWidget->item(recNo,1)->text();
            }
        if (paramName == "Status") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }

}

void staff_attendance_report::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery m("select staff_name,Date,Status from staff_attendance where staff_name='"+arg1+"'");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
       i++;
    }

}
