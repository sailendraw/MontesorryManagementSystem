#include "dailycollection.h"
#include "ui_dailycollection.h"
#include "QSqlQuery"
DailyCollection::DailyCollection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DailyCollection)
{
    ui->setupUi(this);
    QDate dt;
    ui->dateEdit->setDate(dt.currentDate());
    QSqlQuery m("SELECT DATE,MONTH , particulars, paid FROM  `fee_submission` ");
    int size=m.size();
    ui->Feelist->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->Feelist->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->Feelist->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->Feelist->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->Feelist->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        i++;
    }
}

DailyCollection::~DailyCollection()
{
    delete ui;
}

void DailyCollection::on_dateEdit_dateChanged(const QDate &date)
{
    QString da=date.toString(Qt::ISODate);
    QSqlQuery m("SELECT DATE,MONTH , particulars, paid FROM  `fee_submission` where Date='"+da+"'");
    int size=m.size();
    ui->Feelist->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->Feelist->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->Feelist->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        ui->Feelist->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
        ui->Feelist->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
        i++;
    }

}
