#include "student_attendance.h"
#include "ui_student_attendance.h"
#include "QDate"
#include "QSqlQueryModel"
#include "QModelIndex"
#include "QStandardItem"
#include "QAbstractItemModel"
#include "database.h"
#include "QDebug"
#include "QCheckBox"
#include "QHeaderView"
#include "QModelIndex"
#include "database.h"
#include "dateconversion.h"
#include "QMessageBox"
student_attendance::student_attendance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_attendance)
{
    ui->setupUi(this);
    QDate *dt= new QDate;
    QString t= dt->currentDate().toString();
    ui->date->setText(t);
    studentattendance();
    QStringList list;
    database *db=new database;
    list=db->classlist();
ui->selectclass->addItems(list);
}

student_attendance::~student_attendance()
{
    delete ui;
}
void student_attendance::studentattendance()
{
//    QAbstractItemModel *m;
//    QStandardItem* item;
//    item = new QStandardItem(true);
//    item->setCheckable(true);
//    item->setCheckState(Qt::Checked);
//  // m->setItemData();
// //   m->setItemData(item);
//    ui->tableView->setite

}

void student_attendance::on_selectclass_currentIndexChanged(const QString &arg1)
{
      database *db=new database;
      QStringList l=db->studentlist(arg1);
      int row=l.size();
  QCheckBox *chk[row];
  QCheckBox *chk2[row];
       ui->tableWidget->setRowCount(row);
     ui->tableWidget->setColumnCount(4);
     ui->tableWidget->setHorizontalHeaderLabels(QString("Student Name;Present;Absent;Remarks").split(";"));
     QHeaderView* header = ui->tableWidget->horizontalHeader();
       header->setSectionResizeMode(QHeaderView::Stretch);
for(int i=0;i<row;i++)
{
    chk[i]=new QCheckBox(this);
     chk2[i]=new QCheckBox(this);
    chk[i]->setChecked(true);
    chk2[i]->setChecked(false);
    chk[i]->setText("Present");
    chk2[i]->setText("Absent");
ui->tableWidget->setItem(i,0,new QTableWidgetItem(l.at(i).toLocal8Bit().constData()));
ui->tableWidget->setCellWidget(i,1,chk[i]);
ui->tableWidget->setCellWidget(i,2,chk2[i]);
}
}

void student_attendance::on_pushButton_clicked()
{

    QString dt=ui->date->text();
    QString cl=ui->selectclass->currentText();
    int r=ui->tableWidget->rowCount();

    QCheckBox *present;
    QCheckBox *absent;

     database *db= new database;
    for(int i=0;i<r;i++)
    {
       present=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(i,1));
     absent=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(i,2));
      //db->take_attendance(dt,ui->tableWidget->item(i,0)->text(),pre,ui->tableWidget->item(i,3)->text());
      if(present->isChecked())
      {
         db->take_attendance(dt,ui->tableWidget->item(i,0)->text(),"present","");

      }
else
      {
          db->take_attendance(dt,ui->tableWidget->item(i,0)->text(),"Absent",ui->tableWidget->item(i,3)->text());
      }
 }
    dateconversion *dat=new dateconversion;
    int year=QDate::currentDate().year();
    int month=QDate::currentDate().month();
    int day=QDate::currentDate().day();
    QString d=dat->cnvToNepali(year,month,day);
    QMessageBox::information(this,"SUCESS","Attendace taken for date '"+d+"'",QMessageBox::Ok);

   // qDebug()<<studentname;

}
