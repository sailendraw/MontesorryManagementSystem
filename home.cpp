#include "home.h"
#include "ui_home.h"
#include "QSqlQuery"
#include "QSqlQueryModel"
Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
display_events();
display_stock();
}

Home::~Home()
{
    delete ui;
}
void Home::display_events()
{
QSqlQuery m;
m.exec("SELECT DATE, TIME, EVENTS FROM  `events` ");
int size=m.size();
ui->events->setRowCount(size);
int i=0;
while(m.next())
{
    ui->events->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
     ui->events->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
      ui->events->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
      i++;
}
}
void Home::display_stock()
{
    QSqlQuery m;
    m.exec("SELECT product,Qty FROM `stock` WHERE 1 ");
    int size=m.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(m.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
         ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
             i++;
    }
}
