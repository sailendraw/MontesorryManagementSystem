#include "pre_bill_generation.h"
#include "ui_pre_bill_generation.h"
#include "database.h"
#include "QStringList"
#include "QSqlTableModel"
#include "qtrpt.h"
#include "QTableWidgetItem"
 database *db=new database;
pre_bill_generation::pre_bill_generation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pre_bill_generation)
{
    ui->setupUi(this);

    QStringList res=db->classlist();
    ui->class_2->addItems(res);

}

pre_bill_generation::~pre_bill_generation()
{
    delete ui;
}

void pre_bill_generation::on_generate_clicked()
{
db->pre_bill_insert(ui->month->currentText(),ui->class_2->currentText());
   QString cl=ui->class_2->currentText();
   QString m=ui->month->currentText();
  QTableWidgetItem *item;
   QSqlQuery query("SELECT  name ,  month ,  class ,  particulars ,  amount ,  prevbalance FROM  prebill  where class='"+cl+"' and month='"+m+"'");
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
                ui-> tableWidget->setItem(index,5,new QTableWidgetItem(query.value(5).toString()));
                   index++;

                  }
}

void pre_bill_generation::on_save_clicked()
{
    QPrinter printer;

          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/prebill.xml";
              report = new QtRPT(this);
             // report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
              report->recordCount << ui->tableWidget->rowCount();
              if (report->loadReport(fileName) == false) {
                  qDebug()<<"Report's file not found";
              }
              QObject::connect(report, SIGNAL(setValue(int&, QString&, QVariant&, int)),
                               this, SLOT(setValue(int&, QString&, QVariant&, int)));
                    report->printExec(true);
}
void pre_bill_generation::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);


    if (paramName == "Market") {
        if (ui->tableWidget->item(recNo,0) == 0) return;
        paramValue = ui->tableWidget->item(recNo,0)->text();
    }
    if (paramName == "Month") {
        if (ui->tableWidget->item(recNo,1) == 0) return;
        paramValue = ui->tableWidget->item(recNo,1)->text();
    }
    if (paramName == "class") {
        if (ui->tableWidget->item(recNo,2) == 0) return;
        paramValue = ui->tableWidget->item(recNo,2)->text();
    }
    if (paramName == "Particulars") {
        if (ui->tableWidget->item(recNo,3) == 0) return;
        paramValue = ui->tableWidget->item(recNo,3)->text();
    }
    if (paramName == "Price") {
        if (ui->tableWidget->item(recNo,4) == 0) return;
        paramValue = ui->tableWidget->item(recNo,4)->text();
    }
    if(paramName=="PreviousBalance")
    {
        if (ui->tableWidget->item(recNo,5) == 0) return;
        paramValue = ui->tableWidget->item(recNo,5)->text();
    }


}


void pre_bill_generation::on_month_currentIndexChanged(const QString &arg1)
{

        QString cl=ui->class_2->currentText();
       QString m=ui->month->currentText();

       QSqlQuery query("SELECT  name ,  month ,  class ,  particulars ,  amount ,  prevbalance FROM  prebill  where class='"+cl+"' and month='"+arg1+"'");
        int row=query.size();
             int index=0;
         ui->tableWidget->setRowCount(row);
        while (query.next()) {

                      ui-> tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
                    ui->tableWidget->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
                    ui->tableWidget->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
                    ui->tableWidget->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
                   ui-> tableWidget->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
                    ui-> tableWidget->setItem(index,5,new QTableWidgetItem(query.value(5).toString()));
                       index++;

                      }
}
