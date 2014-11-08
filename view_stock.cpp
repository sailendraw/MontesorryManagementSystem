#include "view_stock.h"
#include "ui_view_stock.h"
#include "QSqlQueryModel"
view_stock::view_stock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view_stock)
{
    ui->setupUi(this);
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select product,Qty from stock");
    model->setHeaderData(0,Qt::Horizontal,tr("Product"));
    model->setHeaderData(1,Qt::Horizontal,tr("Quantity"));
    ui->tableView->setModel(model);
}

view_stock::~view_stock()
{
    delete ui;
}

void view_stock::on_productname_cursorPositionChanged(int arg1, int arg2)
{
    QString productname=ui->productname->text();
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select product,Qty from stock where product='"+productname+"'");
    model->setHeaderData(0,Qt::Horizontal,tr("Product"));
    model->setHeaderData(1,Qt::Horizontal,tr("Quantity"));
    ui->tableView->setModel(model);
}


