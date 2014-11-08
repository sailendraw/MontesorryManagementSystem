#include "viewclass.h"
#include "ui_viewclass.h"
#include "QSqlQueryModel"
#include "QDebug"
#include "editclass.h"
#include "QSqlQuery"
#include "QMessageBox"
 QString id;
viewclass::viewclass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewclass)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT *  FROM  class");
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Class"));
        model->setHeaderData(2,Qt::Horizontal,tr("No.std"));
        ui->tableView->setModel(model);
}

viewclass::~viewclass()
{
    delete ui;
}

void viewclass::on_lineEdit_textChanged(const QString &arg1)
{
    QString name=ui->lineEdit->text();
    if(name.isEmpty())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT *  FROM  `class`  where classname like '"+name+"%'");
            model->setHeaderData(0, Qt::Horizontal, tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, tr("Class"));
            model->setHeaderData(2,Qt::Horizontal,tr("No.std"));
                     ui->tableView->setModel(model);
    }
    else
    {
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT *  FROM  `class`  where classname like '"+name+"%'");
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Class"));
        model->setHeaderData(2,Qt::Horizontal,tr("No.std"));
                ui->tableView->setModel(model);
    }
}

void viewclass::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString text;
   id=index.data().toString();
    QSqlQuery qr;
    qr.exec("SELECT  `classname` FROM  `class`   WHERE id='"+id+"' " );
    while(qr.next())
    {
        text=qr.value(0).toString();
    }
    ui->lineEdit->setText(text);

}

void viewclass::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QSqlQuery qr("update class set classname='"+name+"' where id='"+id+"'");
    bool ok=qr.exec();
    if(ok)
    {
        QMessageBox::information(this,"Sucess","Data Updated",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"Failed","Data Duplication Error/or something went wrong!!!",QMessageBox::Ok);
    }

}

void viewclass::on_del_clicked()
{
    QString name=ui->lineEdit->text();
    QSqlQuery qr("Delete from class where id='"+id+"'");
    bool ok=qr.exec();
    if(ok)
    {
        QMessageBox::information(this,"Sucess","Data Deleted",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"Failed","something went wrong!!!",QMessageBox::Ok);

    }

}
