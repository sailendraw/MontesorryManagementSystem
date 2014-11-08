#include "fee_creation.h"
#include "ui_fee_creation.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *feedisplay;
fee_creation::fee_creation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fee_creation)
{
    ui->setupUi(this);
    feedisplay=new QSqlTableModel(this);
    feedisplay->setTable("Fee_creation");
   // feedisplay->setHeaderData(1,Qt::Horizontal,tr("Id"));
    feedisplay->setHeaderData(1,Qt::Horizontal,tr("Fee Heading"));
    feedisplay->setHeaderData(2,Qt::Horizontal,tr("Class"));
    feedisplay->setHeaderData(3,Qt::Horizontal,tr("Price"));
    feedisplay->setHeaderData(4,Qt::Horizontal,tr("Description"));
    feedisplay->select();
ui->tableView->setModel(feedisplay);
ui->tableView->resizeRowsToContents();
database *dt=new database;
ui->comboBox->addItems(dt->classlist());

}

fee_creation::~fee_creation()
{
    delete ui;
}

void fee_creation::on_pushButton_3_clicked()
{

}

void fee_creation::on_pushButton_clicked()
{
    QString feename=ui->feename->text();
    QString feeprice=ui->price->text();
    QString description=ui->feedesc->toPlainText();
    QString classname=ui->comboBox->currentText();
    database *db=new database;
   int ok=db->fee_crtn(feename,classname,feeprice,description);
   if(ok)
   {
ui->messagelabel->setText("Insertion Success");
feedisplay->select();
ui->tableView->setModel(feedisplay);
   }
   else
   {
ui->messagelabel->setText("Insertion Failed");
   }
}

void fee_creation::on_pushButton_2_clicked()
{
    this->close();
}
