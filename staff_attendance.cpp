#include "staff_attendance.h"
#include "ui_staff_attendance.h"
#include "database.h"
#include "QCheckBox"
#include "QMessageBox"
staff_attendance::staff_attendance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staff_attendance)
{
    ui->setupUi(this);
   QDate *t=new QDate;
   ui->dateEdit->setDate(t->currentDate());
   database *db=new database;
   QStringList l=db->stafflist();
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

staff_attendance::~staff_attendance()
{
    delete ui;
}

void staff_attendance::on_pushButton_clicked()
{
    int flag=0;
    QString dt=ui->dateEdit->date().toString();
    int r=ui->tableWidget->rowCount();
    QCheckBox *present;
    QCheckBox *absent;
    database *db= new database;
    for(int i=0;i<r;i++)
    {
       present=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(i,1));
     absent=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(i,2));
       if(present->isChecked())
      {
        db->staff_attendance(dt,ui->tableWidget->item(i,0)->text(),"present","");
        flag=1;

      }
else
      {
          db->staff_attendance(dt,ui->tableWidget->item(i,0)->text(),"Absent",ui->tableWidget->item(i,3)->text());
          flag=1;
      }
 }
    if(flag)
    {
        QMessageBox::information(this,"Attendance taken","Done",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"ERROR","cannot take attendance/may be you are taking same attendance twice",QMessageBox::Ok);
    }
}
