#include "addexpenses.h"
#include "ui_addexpenses.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *ep;
addexpenses::addexpenses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addexpenses)
{
    ui->setupUi(this);
    database *db=new database;
    QStringList lst=db->expenselist();
    ui->expenses->addItems(lst);
    QDate *dt= new QDate;
    ui->date->setDate(dt->currentDate());
    ep=new QSqlTableModel(this);
    ep->setTable("expense");
    ep->setHeaderData(1,Qt::Horizontal,tr("Date"));
    ep->setHeaderData(2,Qt::Horizontal,tr("Particulars"));
    ep->setHeaderData(3,Qt::Horizontal,tr("Amount"));
    ep->select();
    ui->tableView->setModel(ep);
    ui->tableView->resizeRowsToContents();
}

addexpenses::~addexpenses()
{
    delete ui;
}

void addexpenses::on_pushButton_clicked()
{
    QDate date=ui->date->date().currentDate();
    QString exp=ui->expenses->currentText();
    QString price=ui->price->text();
    database *db=new database;
    int ok=db->expense_add(date,exp,price);
    if(ok)
    {
ui->message->setText("<p align='center'><span style=' font-weight:600;'>Data Inserted Sucessfully</span></p>");
ep->select();
ui->tableView->setModel(ep);
return;
    }
    else
    {
        ui->message->setText("<p align='center'><span style=' font-weight:600;'>Insertion Failed</span></p>");

    }
}
