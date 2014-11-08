#include "events.h"
#include "ui_events.h"
#include "database.h"
#include "QMessageBox"
events::events(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::events)
{
    ui->setupUi(this);
    setWindowTitle("Events Creation Wizard");
    QDate *dt;
    ui->dateEdit->setDate(dt->currentDate());
}

events::~events()
{
    delete ui;
}

void events::on_save_clicked()
{
QString dat=ui->dateEdit->date().toString();
QString time=ui->timeEdit->time().toString();
QString eventdetails=ui->plainTextEdit->toPlainText();
database *dt=new database;
int result=dt->event_cr(dat,time,eventdetails);
if(result)
{
    QMessageBox::information(this,"SUCCESS","Events creation success",QMessageBox::Ok);
}
else
{
      QMessageBox::information(this,"Error","cannot create events",QMessageBox::Ok);
}
}
