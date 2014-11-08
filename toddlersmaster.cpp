#include "toddlersmaster.h"
#include "ui_toddlersmaster.h"
#include "database.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "QDate"
toddlersmaster::toddlersmaster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::toddlersmaster)
{

    ui->setupUi(this);
    QSqlQuery qr("select id from staff order by id desc limit 1");

     int tid=0;
    while(qr.next())
    {
       QString id=qr.value(0).toString();
       tid=id.toInt();
       tid=tid+1;
    }
    ui->dateEdit->setDate(QDate::currentDate());
    ui->txtadminno->setText(QString::number(tid));
    QStringList Nationality;
    QStringList gender;
    QStringList blood;
    QStringList Relation;
    Nationality<<"Nepali";
    gender<<"Male"<<"Female";
    blood<<"A+"<<"B+"<<"AB+"<<"O+"<<"AB-"<<"A-"<<"O-"<<"B-"<<"AB-";
    Relation<<"Married"<<"Single";
    ui->married->addItems(Relation);
    ui->nationality->addItems(Nationality);
    ui->blood->addItems(blood);
    ui->gender->addItems(gender);

}

toddlersmaster::~toddlersmaster()
{
    delete ui;
}

void toddlersmaster::on_save_clicked()
{
QString dte=ui->dateEdit->date().toString();
QString firstname=ui->txtfirstname->text();
QString middlename=ui->txtmiddlename->text();
QString lname=ui->txtlname->text();
QString nationality=ui->nationality->currentText();
QString religion=ui->txtreligion->text();
QString gender=ui->gender->currentText();
QString relation=ui->married->currentText();
QString dob=ui->txtdob->text();
QString bloodgroup=ui->blood->currentText();
QString street=ui->txt_adddress->text();
QString street1=ui->txt_address_2->text();
QString city=ui->txt_city->text();
QString state=ui->txt_state->text();
QString pincode=ui->txt_pincode->text();
QString mobile=ui->txt_phone->text();
QString mobile2=ui->txt_phone2->text();
QString email=ui->txt_email->text();
QString academic_current_education=ui->txt_education->text();
QString academic_current_level=ui->txt_current_education->text();
QString postion=ui->txt_position->text();
QString assigned=ui->txt_assigned_class->text();
QString remarks="sss";
QString salary=ui->txt_salary->text();
QString pf=ui->txt_pf->text();
QString bank_ac=ui->txt_bank->text();
QString bank_name=ui->txt_bankname->text();
QString country=ui->txt_country->text();
database *staff=new database;
int result=staff->insert_staff(dte,firstname,middlename,lname,nationality,religion,gender,relation,dob,bloodgroup,street,street1,city,state,pincode,mobile,mobile2,email,academic_current_education
                               ,academic_current_level,postion,assigned,remarks,salary,pf,bank_ac,bank_name,country);
if(result)
{
QMessageBox::information(this,"SUCESS","DATA INSERTED",QMessageBox::Ok);
}
else
{
QMessageBox::information(this,"ERROR","Insertion failed",QMessageBox::Ok);
}
}

void toddlersmaster::on_txtfirstname_editingFinished()
{
    QString fname=ui->txtfirstname->text();
    fname[0]=fname.at(0).toUpper();
    ui->txtfirstname->setText(fname);
}
void toddlersmaster::on_txtmiddlename_editingFinished()
{
    QString fname=ui->txtmiddlename->text();
    fname[0]=fname.at(0).toUpper();
    ui->txtmiddlename->setText(fname);
}

void toddlersmaster::on_txtlname_editingFinished()
{
    QString fname=ui->txtlname->text();
    fname[0]=fname.at(0).toUpper();
    ui->txtlname->setText(fname);
}
