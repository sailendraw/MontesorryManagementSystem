#include "create_discount.h"
#include "ui_create_discount.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *discount;
create_discount::create_discount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_discount)
{
    ui->setupUi(this);
    discount=new QSqlTableModel(this);
    discount->setTable("discount");
    discount->setHeaderData(1,Qt::Horizontal,tr("Discount Name"));
    discount->setHeaderData(2,Qt::Horizontal,tr("Discount Amount"));
    discount->setHeaderData(3,Qt::Horizontal,tr("Description"));
    discount->select();
    ui->tableView->setModel(discount);
  //  ui->tableView->resizeRowsToContents();
}

create_discount::~create_discount()
{
    delete ui;
}

void create_discount::on_pushButton_clicked()
{
    QString discountname=ui->discountname->text();
    QString discountprice=ui->discountedproce->text();
    QString description=ui->description->toPlainText();
    database *db=new database;
    int ok=db->discount(discountname,discountprice,description);
    if(ok)
    {
ui->Message->setText("Insertion Sucess");
discount->select();
ui->tableView->setModel(discount);
return;
    }
    else
    {
ui->Message->setText("Insertion Failed");

    }
}
