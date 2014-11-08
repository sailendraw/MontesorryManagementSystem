#include "stock_sales.h"
#include "ui_stock_sales.h"
#include "database.h"
#include "QSqlQuery"
#include "QMessageBox"
stock_sales::stock_sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stock_sales)
{
    ui->setupUi(this);
    database *dt=new database;
       ui->studentlist->addItems(dt->student_list());
    ui->productlist->addItems(dt->product_list());
}

stock_sales::~stock_sales()
{
    delete ui;
}

void stock_sales::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{



}

void stock_sales::on_qty_cursorPositionChanged(int arg1, int arg2)
{

    int unit_price=0;
    int qty=0;
    int total=0;
    qty=ui->qty->text().toInt();
     QString product=ui->productlist->currentText();
    QSqlQuery m("select unitprice from stock_add where Product='"+product+"'");
    while(m.next())
    {
        unit_price=m.value(0).toString().toInt();
    }

total=unit_price*qty;
ui->total->setText(QString::number(total));

}

void stock_sales::on_amtpaid_cursorPositionChanged(int arg1, int arg2)
{
    int paid=0;
    int total=0;
    paid=ui->amtpaid->text().toInt();
    total=ui->total->text().toInt();
    int bal=total-paid;
    ui->balanceamt->setText(QString::number(bal));
}

void stock_sales::on_pushButton_clicked()
{
QString product=ui->productlist->currentText();
int qty=0;
QSqlQuery m1("select Qty from stock where product='"+product+"'");
while(m1.next())
{
    qty=m1.value(0).toString().toInt();

}
if(qty<=0)
{
    QMessageBox::information(this,"WARNING","Selected product '"+product+"'is out of stock",QMessageBox::Ok);
}
else
{
    QDate dte;

         ui->dateEdit->setDate(dte.currentDate());
          QString dy=ui->dateEdit->date().toString();
    QString name=ui->studentlist->currentText();
    QString prod=ui->productlist->currentText();
    QString amt=ui->total->text();
    QString qt=ui->qty->text();
    QString paid=ui->amtpaid->text();
    QString bal=ui->balanceamt->text();
    database *dt=new database;
    int result=dt->insert_sales(dy,name,prod,qt,amt,paid,bal);


}
}
