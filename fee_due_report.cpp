#include "fee_due_report.h"
#include "ui_fee_due_report.h"
#include "QDate"
#include "QStringList"
#include "database.h"
#include "QSqlQuery"
fee_due_report::fee_due_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fee_due_report)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    QStringList m;
    m<<"Baisakh"<<"Jestha"<<"Ashad"<<"Shrawan"<<"Bhadra"<<"Ashoj"<<"Kartik"<<"Mangsir"<<"Paush"<<"Magh"<<"Falgun"<<"Chaitra";
    ui->month->addItems(m);
    database *db=new database;
    ui->studentclass->addItems(db->classlist());
    ui->studentlist->addItems(db->studentlist(ui->studentclass->currentText()));
}

fee_due_report::~fee_due_report()
{
    delete ui;
}
void fee_due_report::displaydata()
{
    QString d=ui->dateEdit->date().toString();
    QString s=ui->studentlist->currentText();
    QString mo=ui->month->currentText();
    int i=0;
QSqlQuery m("SELECT  `Date` ,  `Month` ,  `Particulars` ,  `Balance` FROM  `fee_submission` WHERE  MONTH =  '"+mo+"'AND student_name =  '"+s+"'");
int size=m.size();
ui->tableWidget->setRowCount(size);
while(m.next())
{
ui->tableWidget->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
ui->tableWidget->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
ui->tableWidget->setItem(i,2,new QTableWidgetItem(m.value(2).toString()));
ui->tableWidget->setItem(i,3,new QTableWidgetItem(m.value(3).toString()));
i++;
}
}

void fee_due_report::on_studentlist_activated(const QString &arg1)
{
    displaydata();
}

void fee_due_report::on_month_currentIndexChanged(const QString &arg1)
{
    displaydata();
}
