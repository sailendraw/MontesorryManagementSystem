#include "studentfee.h"
#include "ui_studentfee.h"
#include "database.h"
#include "QSqlQuery"
#include "QCheckBox"
#include "QVBoxLayout"
#include "QDebug"
#include "QStringList"
#include "QSqlQueryModel"
#include "QMessageBox"
int r=0;
int row=1;
 int ik=0;

QStringList fee;
QStringList *lt=new QStringList;
 QSqlQueryModel *mod = new QSqlQueryModel;
 database *d=new database;
studentfee::studentfee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentfee)
{
    ui->setupUi(this);
    setWindowTitle("Fee Setup");
    database *dt=new database;
ui->tableWidget->setRowCount(1);

ui->comboclass->addItems(dt->classlist());
//ui->tableWidget->horizontalHeader()->stretchLastSection();

}

studentfee::~studentfee()
{
    delete ui;
}

void studentfee::on_comboclass_currentIndexChanged(const QString &arg1)
{
   QSqlQuery query("SELECT  `fee_id` ,  `Fee_name`,fee_amount FROM  `Fee_creation` where class='"+arg1+"'");
    ui->student->clear();
    ui->comboBox->clear();
    fee.clear();
ui->student->addItems(d->studentlist(arg1));

    int row=query.size();


       while(query.next())
       {
fee<<query.value(1).toStringList();
       }

ui->comboBox->addItems(fee);

}

void studentfee::selectedid(int k)
{
    qDebug()<<k;
}

void studentfee::on_toolButton_clicked()
{
    QString feename=ui->comboBox->currentText();
    QString feeclass=ui->comboclass->currentText();
    ui->tableWidget->setColumnCount(3);
    QSqlQuery query("SELECT    `Fee_name`,class,fee_amount FROM  `Fee_creation` where class='"+feeclass+"' and Fee_name='"+feename+"'");
    int s=query.size();
    int sh=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(sh);
    while(query.next())
      {

      ui->tableWidget->setItem(ik,0,new QTableWidgetItem(query.value(0).toString()));
      ui->tableWidget->setItem(ik,1,new QTableWidgetItem(query.value(1).toString()));
      ui->tableWidget->setItem(ik,2,new QTableWidgetItem(query.value(2).toString()));
        ik++;
      }



}

void studentfee::on_pushButton_3_clicked()
{
int rowc=ui->tableWidget->rowCount();
int colc=ui->tableWidget->columnCount();
int kl=rowc-1;
int lk=colc-1;

for(int k=0;k<kl;k++)
{

            int result=d->fee_assigned(ui->student->currentText(),ui->tableWidget->item(k,1)->text(),ui->tableWidget->item(k,0)->text(),ui->tableWidget->item(k,2)->text());
  if(result)
  {
      QMessageBox::information(this,"Success","Sucess",QMessageBox::Ok);
  }
  else
     {
       QMessageBox::information(this,"Failed","Duplicate Data entry or contact service provider",QMessageBox::Ok);

  }
}

}


