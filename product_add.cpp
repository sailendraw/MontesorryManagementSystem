#include "product_add.h"
#include "ui_product_add.h"
#include "database.h"
#include "QDebug"
#include "QSqlTableModel"
QSqlTableModel *list;
QString s;
QString t;
product_add::product_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::product_add)
{
    ui->setupUi(this);
    QStringList vd;
    QStringList prdct;
    database *dt=new database;
    vd=dt->vendor_list();
    prdct=dt->product_list();
    ui->product->addItems(prdct);
    ui->vendor->addItems(vd);
    list=new QSqlTableModel(this);
    list->setTable("stock_add");
   // list->setHeaderData(1,Qt::Horizontal,tr("ID"));
    list->setHeaderData(1,Qt::Horizontal,tr("Date"));
    list->setHeaderData(2,Qt::Horizontal,tr("Product"));
    list->setHeaderData(3,Qt::Horizontal,tr("Vendor"));
    list->setHeaderData(4,Qt::Horizontal,tr("Qty"));
    list->setHeaderData(5,Qt::Horizontal,tr("Unit Price"));
    list->setHeaderData(6,Qt::Horizontal,tr("Amount"));
    list->setHeaderData(7,Qt::Horizontal,tr("Paid"));
    list->setHeaderData(8,Qt::Horizontal,tr("Balance"));
    list->setHeaderData(9,Qt::Horizontal,tr("Check No"));
    list->select();
    ui->tableView->setModel(list);
    ui->tableView->resizeColumnsToContents();
}

product_add::~product_add()
{
    delete ui;
}

void product_add::on_pushButton_clicked()
{

    QString dat=ui->dateEdit->date().toString();
    QString prd=ui->product->currentText();
    QString vndr=ui->vendor->currentText();
   QString qty=ui->qty->text();
    QString amt=ui->amt->text();
 QString paid=ui->paid->text();
QString balance=ui->blnce->text();
 QString unit_price=ui->unitprice->text();
   QString check_num=ui->chck->text();
  database *dt=new database;
  int result=dt->insert_stock(dat,prd,vndr,qty,amt,paid,balance,unit_price,check_num);
  if(result)
  {
      ui->message->setText("Stock Added Successfully");
      list->select();
      ui->tableView->setModel(list);
return;
  }
  ui->message->setText("Insertion Failed");
}

void product_add::on_amt_cursorPositionChanged(int arg1, int arg2)
{

}

void product_add::on_qty_cursorPositionChanged(int arg1, int arg2)
{
    int qty=ui->qty->text().toInt();
    int amt=ui->amt->text().toInt();

int balance=ui->blnce->text().toInt();
   int unit_price=ui->unitprice->text().toInt();
   QString check_num=ui->chck->text();
int total=qty*unit_price;
s=QString::number(total);

    ui->amt->setText(s);

}

void product_add::on_paid_cursorPositionChanged(int arg1, int arg2)
{
int paid=ui->paid->text().toInt();
int amt=ui->amt->text().toInt();
int tot=amt-paid;
t=QString::number(tot);

//QString::number(total);

   ui->blnce->setText(t);
}

void product_add::on_product_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * from stock_add where Product='"+arg1+"'");
        model->setHeaderData(1,Qt::Horizontal,tr("Date"));
        model->setHeaderData(2,Qt::Horizontal,tr("Product"));
        model->setHeaderData(3,Qt::Horizontal,tr("Vendor"));
        model->setHeaderData(4,Qt::Horizontal,tr("Qty"));
        model->setHeaderData(5,Qt::Horizontal,tr("Unit Price"));
        model->setHeaderData(6,Qt::Horizontal,tr("Amount"));
        model->setHeaderData(7,Qt::Horizontal,tr("Paid"));
        model->setHeaderData(8,Qt::Horizontal,tr("Balance"));
        model->setHeaderData(9,Qt::Horizontal,tr("Check No"));
        ui->tableView->setModel(model);
}
