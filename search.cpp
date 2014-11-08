#include "search.h"
#include "ui_search.h"
#include "QSqlTableModel"
#include "QDebug"
#include "student.h"
#include "ui_student.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "database.h"
#include "payduefee.h"

Search::Search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    sh();


}

Search::~Search()
{
    delete ui;
}

void Search::on_tableView_doubleClicked(const QModelIndex &index)
{

QString name=ui->tableView->model()->data(index).toString();
display(name);
}

void Search::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString name=ui->lineEdit->text();
    if(name.isEmpty())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT firstname, lastname, class, roll_no,STATUS FROM  student where firstname like '"+name+"%'");
            model->setHeaderData(0, Qt::Horizontal, tr("Firstname"));
            model->setHeaderData(1, Qt::Horizontal, tr("Lastname"));
            model->setHeaderData(2,Qt::Horizontal,tr("Class"));
            model->setHeaderData(3,Qt::Horizontal,tr("Roll"));
             model->setHeaderData(4,Qt::Horizontal,tr("Status"));
             ui->tableView->setModel(model);
    }
    else
    {
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT firstname, lastname, class, roll_no,STATUS FROM  student where firstname like '"+name+"%'");
        model->setHeaderData(0, Qt::Horizontal, tr("Firstname"));
        model->setHeaderData(1, Qt::Horizontal, tr("Lastname"));
        model->setHeaderData(2,Qt::Horizontal,tr("Class"));
        model->setHeaderData(3,Qt::Horizontal,tr("Roll"));
         model->setHeaderData(4,Qt::Horizontal,tr("Status"));
         ui->tableView->setModel(model);
    }

}

void Search::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT firstname, lastname, class, roll_no,STATUS FROM  student");
        model->setHeaderData(0, Qt::Horizontal, tr("Firstname"));
        model->setHeaderData(1, Qt::Horizontal, tr("Lastname"));
        model->setHeaderData(2,Qt::Horizontal,tr("Class"));
        model->setHeaderData(3,Qt::Horizontal,tr("Roll"));
         model->setHeaderData(4,Qt::Horizontal,tr("Status"));
         ui->tableView->setModel(model);
}
void Search::display(QString d)
{
ui->app_number->setReadOnly(true);
QSqlQuery query("select * from student where app_id='"+d+"'");
while(query.next())
{
ui->app_number->setText(query.value(0).toString());
ui->admission_num->setText(query.value(1).toString());
ui->roll->setText(query.value(2).toString());
ui->txtfirstname->setText(query.value(3).toString());
ui->txtmiddlename->setText(query.value(4).toString());
ui->txtlastname->setText(query.value(5).toString());
ui->txtdate->setDate(query.value(6).toDate());
ui->txtnepali->setText(query.value(8).toString());
ui->txtnationality->addItem(query.value(10).toString());
ui->txtcaste->addItem(query.value(11).toString());
ui->txtbirthplace->setText(query.value(12).toString());
ui->txtreligion->addItem(query.value(13).toString());
ui->txtlanguage->setText(query.value(14).toString());
ui->txtfather->setText(query.value(15).toString());
ui->txtfatherbirth->setText(query.value(16).toString());
ui->txtfalanguage->setText(query.value(17).toString());
ui->txtfatheraddress->setText(query.value(18).toString());
ui->txtlocalfa->setText(query.value(19).toString());
ui->txtmother->setText(query.value(20).toString());
ui->txtmotherbirth->setText(query.value(21).toString());
ui->txtmotherlanguage->setText(query.value(22).toString());
ui->txtmotheradd->setText(query.value(24).toString());
ui->txtmotherlocal->setText(query.value(25).toString());
ui->txtph1->setText(query.value(26).toString());
ui->txthom2->setText(query.value(27).toString());
ui->txtfathermobile->setText(query.value(28).toString());
ui->txtmothermobile->setText(query.value(29).toString());
ui->txtemergency->setText(query.value(30).toString());
ui->txtfatheroccupation->setText(query.value(31).toString());
ui->txtmotheroccu->setText(query.value(32).toString());
ui->txtguardname->setText(query.value(33).toString());
ui->txtguardrelation->setText(query.value(34).toString());
ui->txtcontactguard->setText(query.value(35).toString());
ui->txtguardoccu->setText(query.value(36).toString());
ui->details_2->setPlainText(query.value(37).toString());
ui->txtclassassigned->addItem(query.value(38).toString());

}
QString fname=ui->txtfirstname->text();
QString lname=ui->txtlastname->text();
fname.append(" ");
   fname.append(lname);
    QSqlQuery qr("select Particulars,Amount,Paid,Balance from fee_submission where Balance>0 and student_name='"+fname+"'");
    int size=qr.size();
    ui->tableWidget->setRowCount(size);
    int i=0;
    while(qr.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
                i++;

    }
}




void Search::on_pushButton_7_clicked()
{
    QString id=ui->app_number->text();
    QString name=ui->txtfirstname->text();
    int ok=QMessageBox::information(this,"INFORMATION","Are you sure,You want to delete '"+name+"' This student will stay as inactive",QMessageBox::Ok,QMessageBox::Cancel);
if(ok)
{
    database *dt=new database;
    dt->delete_student(id);
}
}

void Search::on_pushButton_5_clicked()
{
    database *db=new database;
   int rsulte= db->update_student(ui->app_number->text(),  ui->admission_num->text(),ui->roll->text(),ui->txtfirstname->text(), ui->txtmiddlename->text(),ui->txtlastname->text(),ui->txtdate->date().toString(),  ui->txtnepali->text(),
   ui->txtnationality->currentText(),ui->txtcaste->currentText(),ui->txtbirthplace->text(),ui->txtreligion->currentText(),ui->txtlanguage->text(),ui->txtfather->text(),ui->txtfatherbirth->text(),ui->txtfalanguage->text(),ui->txtfatheraddress->text(), ui->txtlocalfa->text(),
    ui->txtmother->text(),ui->txtmotherbirth->text(),ui->txtmotherlanguage->text(),ui->txtmotheradd->text(),ui->txtmotherlocal->text(),ui->txtph1->text(),ui->txthom2->text(),ui->txtfathermobile->text(),ui->txtmothermobile->text(),ui->txtemergency->text(),
    ui->txtfatheroccupation->text(),ui->txtmotheroccu->text(),ui->txtguardname->text(),ui->txtguardrelation->text(),ui->txtcontactguard->text(),ui->txtguardoccu->text(),ui->details_2->toPlainText(),ui->txtclassassigned->currentText());
if(rsulte)
{
    QMessageBox::information(this,"SUCCESS","DATA UPDATED SUCCESSFULLY",QMessageBox::Ok);
    sh();
}
else
{
      QMessageBox::information(this,"Error","Update failed",QMessageBox::Ok);
}
}
void Search::sh()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT app_id,firstname, lastname, class, roll_no,STATUS FROM  student ");
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Firstname"));
        model->setHeaderData(2,Qt::Horizontal,tr("Lastname"));
        model->setHeaderData(3,Qt::Horizontal,tr("Class"));
        model->setHeaderData(4,Qt::Horizontal,tr("roll_no"));
        model->setHeaderData(5,Qt::Horizontal,tr("Status"));
         ui->tableView->setModel(model);
}

void Search::on_payduue_clicked()
{
payduefee *due=new payduefee;
due->show();
}
