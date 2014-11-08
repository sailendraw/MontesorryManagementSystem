#include "evaluationsheet.h"
#include "ui_evaluationsheet.h"
#include "database.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlError"
#include "QMessageBox"
database *dbase=new database;
EvaluationSheet::EvaluationSheet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvaluationSheet)
{
    ui->setupUi(this);
    ui->comboclass->addItems(dbase->classlist());
    ui->studentlist->addItems(dbase->studentlist(ui->comboclass->currentText()));
    ui->subjectlist->addItems(dbase->subjectlist());
    QString name=ui->studentlist->currentText();
    QSqlQuery qr("SELECT dob, roll_no, fath_name FROM  student WHERE CONCAT(firstname,'  ', lastname ) ='"+name+"';");
    while(qr.next())
    {
        QString dob=QString::number(qr.value(0).toInt());
        ui->txtdob->setText(dob);
        ui->txtroll->setText(qr.value(1).toString());
        ui->txtfathername->setText(qr.value(2).toString());
    }
    qDebug()<<qr.lastError().text();
}

EvaluationSheet::~EvaluationSheet()
{
    delete ui;
}

void EvaluationSheet::on_pushButton_clicked()
{
QString test=ui->termlist->currentText();
if(test=="First Mid Term")
{
QString marks=ui->txtmarks->text();
QString total=ui->txttotal->text();
QString band=ui->txtband->text();
QString name=ui->studentlist->currentText();
QString roll=ui->subjectlist->currentText();
dbase->firstterm(marks,total,band,name,roll);
displayintable();
}
else if(test=="First Term")
{
    QString marks=ui->txtmarks->text();
    QString total=ui->txttotal->text();
    QString band=ui->txtband->text();
    QString name=ui->studentlist->currentText();
    QString roll=ui->subjectlist->currentText();
    dbase->firstmidterm(marks,name,ui->subjectlist->currentText(),"test");
displayintable();
}
else if(test=="Second Mid Term")
{
    QString marks=ui->txtmarks->text();
    QString total=ui->txttotal->text();
    QString band=ui->txtband->text();
    QString name=ui->studentlist->currentText();
    QString roll=ui->subjectlist->currentText();
    dbase->secondterm(marks,total,band,name,roll);
    displayintable();
}
else if(test=="Second Term")
{
    QString marks=ui->txtmarks->text();
    QString total=ui->txttotal->text();
    QString band=ui->txtband->text();
    QString name=ui->studentlist->currentText();
    QString roll=ui->subjectlist->currentText();
    dbase->secondmidterm(marks,name,ui->subjectlist->currentText(),name);

    displayintable();
}
else if(test=="Final Mid Term")
{
    QString marks=ui->txtmarks->text();
    QString total=ui->txttotal->text();
    QString band=ui->txtband->text();
    QString name=ui->studentlist->currentText();
    QString roll=ui->subjectlist->currentText();
    dbase->finalterm(marks,total,band,name,roll);
    displayintable();
}
else if(test=="Final Term")
{
    QString marks=ui->txtmarks->text();
    QString total=ui->txttotal->text();
    QString band=ui->txtband->text();
    QString name=ui->studentlist->currentText();
    QString roll=ui->subjectlist->currentText();
    dbase->finalmidterm(marks,name,ui->subjectlist->currentText(),name);
    displayintable();
}
else
{
QMessageBox::information(this,"Error","Please select valid Term to Enter marks",QMessageBox::Ok);
}
}
void EvaluationSheet::displayintable()
{
    QString name=ui->studentlist->currentText();
    QString arg1=ui->termlist->currentText();
    QSqlQuery qr;

    if (arg1=="First Mid Term")
    {
        int i=0;
        qr.exec("SELECT Student_id,Subject_id,First_Mid_Term,Total, Band FROM  FirstTerm WHERE student_id =  '"+name+"'");
        int row=qr.size();
        ui->tableWidget->setRowCount(row);
        while(qr.next())
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(qr.value(4).toString()));
            i++;
        }
    }
}

void EvaluationSheet::on_termlist_currentIndexChanged(const QString &arg1)
{
    QString name=ui->studentlist->currentText();
    QSqlQuery qr;

    if (arg1=="First Mid Term")
    {
        int i=0;
        qr.exec("SELECT Student_id,Subject_id,First_Mid_Term,Total, Band FROM  FirstTerm WHERE student_id =  '"+name+"'");
        int row=qr.size();
        ui->tableWidget->setRowCount(row);
        while(qr.next())
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(qr.value(4).toString()));
            i++;
        }
    }
    else if(arg1=="Second Mid Term")
    {

            int i=0;
            qr.exec("SELECT Student_id,Subject_id,First_Mid_Term,Total, Band FROM  SecondTerm WHERE student_id =  '"+name+"'");
            int row=qr.size();
            ui->tableWidget->setRowCount(row);
            while(qr.next())
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(qr.value(4).toString()));
                i++;
            }
        }
      else if(arg1=="Final Mid Term")
    {

            int i=0;
            qr.exec("SELECT Student_id,Subject_id,First_Mid_Term,Total, Band FROM  ThirdTerm WHERE student_id =  '"+name+"'");
            int row=qr.size();
            ui->tableWidget->setRowCount(row);
            while(qr.next())
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(qr.value(4).toString()));
                i++;
            }
        }

    else
    {

    }
}
