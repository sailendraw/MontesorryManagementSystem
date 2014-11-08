#include "addextrafee.h"
#include "ui_addextrafee.h"
#include "database.h"
#include "QMessageBox"
#include "QSqlQueryModel"
addextrafee::addextrafee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addextrafee)
{
    ui->setupUi(this);
    display();
}

addextrafee::~addextrafee()
{
    delete ui;
}

void addextrafee::on_savebtn_clicked()
{
    database *dt=new database;
QString heading=ui->feeheading->text();
QString feeamount=ui->feeamount->text();
int result=dt->insert_xtra_fee(heading,feeamount);
if(result)
{
QMessageBox::information(this,"Success","Fee created",QMessageBox::Ok);
}
else
{
    QMessageBox::information(this,"Error","Unable to add",QMessageBox::Ok);
display();
}
}
void addextrafee::display()
{
    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT *  FROM  `extrafee` ");
       model->setHeaderData(0, Qt::Horizontal, tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, tr("Fee Particulars"));
       model->setHeaderData(2, Qt::Horizontal, tr("Amount"));

     ui->tableView->setModel(model);
}
