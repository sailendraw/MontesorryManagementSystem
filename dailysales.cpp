#include "dailysales.h"
#include "ui_dailysales.h"
#include "QSqlQuery"
Dailysales::Dailysales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dailysales)
{
    ui->setupUi(this);
    QDate dt;
    ui->dateEdit->setDate(dt.currentDate());
    QSqlQuery m("select Date,product,total from stock_sales");
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

Dailysales::~Dailysales()
{
    delete ui;
}

void Dailysales::on_dateEdit_dateChanged(const QDate &date)
{
QString d=date.toString(Qt::ISODate);
QSqlQuery m("select Date,product,total from stock_sales where Date='"+d+"'");
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
