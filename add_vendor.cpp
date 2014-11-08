#include "add_vendor.h"
#include "ui_add_vendor.h"
#include "database.h"
#include "QMessageBox"
#include "QSqlTableModel"
QSqlTableModel *m;
add_vendor::add_vendor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_vendor)
{
    ui->setupUi(this);
    m=new QSqlTableModel(this);
    m->setTable("vendor");
   // m->setHeaderData(1,Qt::Horizontal,"Id");
    m->setHeaderData(1,Qt::Horizontal,"Vendorname");
    m->setHeaderData(2,Qt::Horizontal,"Description");
    m->setHeaderData(3,Qt::Horizontal,"Phone");
    m->select();
    ui->tableView->setModel(m);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();

}

add_vendor::~add_vendor()
{
    delete ui;
}

void add_vendor::on_pushButton_2_clicked()
{
QString vendorname=ui->txt_vendor_name->text();
QString vendorphone=ui->txt_vendor_ph->text();
QString vendordesc=ui->txt_vendro_desc->toPlainText();
database *dt=new database;
int result=dt->insert_Vendor(vendorname,vendordesc,vendorphone);
if(result)
{
ui->message->setText("Vendor added successfully");
m->select();
//ui->tableView->setmodel(m);
ui->tableView->setModel(m);
}
else
{
ui->message->setText("Error in adding vendor");
}
}
