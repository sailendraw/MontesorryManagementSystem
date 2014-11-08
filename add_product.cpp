#include "add_product.h"
#include "ui_add_product.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *modl;
add_product::add_product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_product)
{
    ui->setupUi(this);
    modl=new QSqlTableModel(this);
    modl->setTable("product");
    modl->setHeaderData(1,Qt::Horizontal,"Product");
    modl->setHeaderData(2,Qt::Horizontal,"Description");
    modl->select();
    ui->tableView->setModel(modl);
}

add_product::~add_product()
{
    delete ui;
}

void add_product::on_save_clicked()
{
QString product=ui->productname->text();
QString desc=ui->desc->toPlainText();
database *dt=new database;
int ok=dt->insert_product(product,desc);
if(ok)
{
ui->message->setText("Product added successfully");
modl->select();
ui->tableView->setModel(modl);
}
else
{
ui->message->setText("Product cannot be added please contact");
}

}
