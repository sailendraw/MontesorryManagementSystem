#include "fee_submission.h"
#include "ui_fee_submission.h"
#include "database.h"
#include "QDebug"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QtRPT/qtrpt.h"
#include "numberstowords.h"
QString inwords;
QStringList amtlist;
database *dat=new database;
QStringList feelist;
int total=0;
 database *lst=new database;
fee_submission::fee_submission(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fee_submission)
{
    ui->setupUi(this);
        QStringList list;
    list<<"Baisakh"<<"Jestha"<<"Ashad"<<"Shrawan"<<"Bhadra"<<"Ashoj"<<"Kartik"<<"Mangisr"<<"Poush"<<"Magh"<<"Falgun"<<"Chaitra";
    ui->month->addItems(list);
     QStringList classlist=lst->classlist();
ui->classlist->addItems(classlist);
ui->Extrafee->addItems(dat->xtrafe());
ui->date->setDate(QDate::currentDate());

 int r=ui->particulars->model()->rowCount();
for(int i=0;i<r;i++)
{
// QString particulars=ui->particulars->indexAt(QPoint(2,1)).data().toString();
//  QString amt=ui->particulars->indexAt(QPoint(1,1)).data().toString();
feelist<<ui->particulars->model()->data(ui->particulars->model()->index(i,0)).toStringList();
QString amt=ui->particulars->model()->data(ui->particulars->model()->index(i,1)).toString();
amtlist<<ui->particulars->model()->data(ui->particulars->model()->index(i,1)).toStringList();
total=total+amt.toInt();

}
ui->total->setText(QString::number(total));
 QString name=ui->student->currentText();
 displayfee(name);

}

fee_submission::~fee_submission()
{
    delete ui;
}

void fee_submission::on_save_clicked()
{

    QString stdname=ui->student->currentText();
    QString dt=ui->date->date().toString();
    QString month=ui->month->currentText();
    QString cl=ui->classlist->currentText();
    QString Paid=ui->paid->text();
    QString amt=ui->total->text();
   QString balance=ui->balance->text();

int size=feelist.size();
for(int i=0;i<size;i++)
{
   // qDebug()<<feelist.at(i).toLocal8Bit().constData();
    dat->fee_submission(dt,month,stdname,cl,feelist.at(i).toLocal8Bit().constData(),amtlist.at(i).toLocal8Bit().constData(),Paid,balance);
}

displayfee(ui->student->currentText());
}
void fee_submission::stdlst()
{

}

void fee_submission::on_classlist_currentTextChanged(const QString &arg1)
{
    ui->student->clear();
  QStringList lt=lst->studentlist(arg1);
  ui->student->addItems(lt);

}

void fee_submission::on_student_currentIndexChanged(const QString &arg1)
{
    QString c=ui->classlist->currentText();


    QSqlQuery m("select fee_heading,Amount from fee_assigned where class='"+c+"' and student_name='"+arg1+"' ");
    int size=m.size();
    ui->particulars->setRowCount(size);
    int i=0;
    while (m.next())
    {
        ui->particulars->setItem(i,0,new QTableWidgetItem(m.value(0).toString()));
        ui->particulars->setItem(i,1,new QTableWidgetItem(m.value(1).toString()));
        i++;
    }
    QSqlQuery m1("SELECT balance as balance FROM fee_submission WHERE student_name='"+arg1+"'");
 //   while(m1.next())
    //ui->due->setText(m1.value(0).toString());
}

void fee_submission::on_paid_cursorPositionChanged(int arg1, int arg2)
{
    int paid=ui->paid->text().toInt();
    int t=ui->total->text().toInt();
    int balance=t-paid;
    ui->balance->setText(QString::number(balance));
    numberstowords *w=new numberstowords;
    inwords=w->numberToText(paid);
}
void fee_submission::displayfee(QString student)
{
    //qDebug()<<"function is called";
    QSqlQuery query("SELECT DATE,MONTH , Class, student_name, Particulars, Amount, Paid, Balance FROM  `fee_submission` WHERE student_name =  '"+student+"'");
    int si=query.size();
    ui->tableWidget->setRowCount(si);
    int i=0;
  while(query.next())
  {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
         ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
         ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
         ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
         ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
         ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
         //ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
         i++;
    }
}

void fee_submission::on_save_2_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/monthlybill.xml";
              report = new QtRPT(this);
             // report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
              report->recordCount << ui->tableWidget->rowCount();
              if (report->loadReport(fileName) == false) {
                  qDebug()<<"Report's file not found";
              }
              QObject::connect(report, SIGNAL(setValue(int&, QString&, QVariant&, int)), this, SLOT(setValue(int&, QString&, QVariant&, int)));
                report->printExec(true);
}
void fee_submission::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);

         if (paramName == "S.N")
            paramValue = recNo+1;
         if (paramName == "Inwords")
            paramValue = inwords;
         if (paramName == "Name")
            paramValue = ui->student->currentText();
         if (paramName == "Class")
            paramValue = ui->classlist->currentText();
         if (paramName == "Month")
            paramValue = ui->month->currentText();
         if (paramName == "Date")
            paramValue = ui->date->date();
        if (paramName == "Particulars") {
            if (ui->particulars->item(recNo,0) == 0) return;
            paramValue = ui->particulars->item(recNo,0)->text();
        }
        if (paramName == "Amount") {
            if (ui->particulars->item(recNo,1) == 0) return;
            paramValue = ui->particulars->item(recNo,1)->text();
        }

        if (paramName == "Paid")
           paramValue = ui->paid->text();
        if (paramName == "Balance")
           paramValue = ui->balance->text();
}

void fee_submission::on_toolButton_clicked()
{
    QString current_item=ui->Extrafee->currentText();
    int row=ui->particulars->rowCount();
    int col=ui->particulars->columnCount();
    ui->particulars->insertRow(row);
    int r=ui->particulars->rowCount();
  	ui->particulars->setRowCount(r);
	int ttl=ui->total->text().toInt();
	int p;
    QSqlQuery m("select Particulars,Amount from extrafee where Particulars='"+current_item+"' ");
	while(m.next())
	{
    int s=r-1;
        ui->particulars->setItem(s,0,new QTableWidgetItem(m.value(0).toString()));
        ui->particulars->setItem(s,1,new QTableWidgetItem(m.value(1).toString()));

	p=m.value(1).toString().toInt();
			}
	ttl=ttl+p;
	ui->total->setText(QString::number(ttl));
}
