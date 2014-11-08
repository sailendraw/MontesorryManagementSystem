#include "addtoddlers.h"
#include "ui_addtoddlers.h"
#include "QDebug"
#include "QFocusEvent"
#include "QCalendarWidget"
#include "database.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "QCheckBox"
#include "QShortcut"
#include "QDate"
#include "dateconversion.h"
addtoddlers::addtoddlers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addtoddlers)
{

    ui->setupUi(this);
    ui->txt_application_no->setReadOnly(true);
    //ui->discount->hide();
    QSqlQuery qry,qr;
       QSqlQueryModel *m= new QSqlQueryModel;
       qry.exec("SELECT classname from class");
       m->setQuery(qry);
       ui->assignedclass->setModel(m);       QStringList rel,nation,ss;
       rel<<"Hindu"<<"Christian"<<"Muslim"<<"Buddhist";
       ui->relgn->addItems(rel);
       nation<<"Nepali"<<"Indian"<<"Chinese"<<"US";

       ui->nationality->addItems(nation);
       ui->comboBox->setEnabled(false);
       ui->dateEdit->setDate(QDate::currentDate());

qr.exec("SELECT app_id         FROM student         ORDER BY app_id DESC         LIMIT 1");
int i=0;
while(qr.next())
{
     QString num=qr.value(0).toString();
     i=num.toInt();
     i=i+1;
}

ui->txt_application_no->setText(QString::number(i));
setWindowTitle("ADD STUDENT");
QShortcut *shortcut=new QShortcut(QKeySequence(tr("Ctrl+S", "Save")),this,SLOT(on_pushButton_2_clicked()));

}

addtoddlers::~addtoddlers()
{
    delete ui;
}

void addtoddlers::on_pushButton_3_clicked()
{

    this->close();
}




void addtoddlers::on_dateEdit_userDateChanged(const QDate &date)
{
    //date=ui->dateEdit->text();
  //  ui->txt_dob_nepali->setText(date);
      // qDebug()<<date.toString();

}

void addtoddlers::on_checkBox_2_clicked()
{
   //ui->co
}

void addtoddlers::on_scholarship_clicked()
{
    //ui->discount->show();
}

void addtoddlers::on_pushButton_2_clicked()
{

   QString admission=ui->txt_admission_number->text();
   QString roll=ui->txt_roll_num->text();
   QString firstname=ui->firstname->text();
   QString middlename=ui->middlename->text();
   QString lastname=ui->lastname->text();
   QString dob=ui->dateEdit->text();
   QString nepaliname=ui->nepaliname->text();
   QString nepalidob=ui->txt_dob_nepali->text();
   QString nationality=ui->nationality->currentText();
   QString caste=ui->caste->currentText();
   QString birthplace=ui->birthplace->text();
   QString religion=ui->relgn->currentText();
   QString language=ui->language->text();
   QString student_language=ui->txt_language->text();
   QString father_name=ui->fathername->text();
   QString father_living;
   if(ui->father_living_yes->isChecked())
   {
       father_living="yes";
   }
   else
   {
       father_living="no";
   }
   QString father_birthplace=ui->birthplace->text();
  QString father_address=ui->father_address->text();
   QString father_local_address=ui->father_local_address->text();
   QString father_mobile=ui->father_mobile->text();
   QString father_occupation=ui->father_occupation->text();
   QString mother_name=ui->mothername->text();
   QString mother_birthplace=ui->motherbirthplace->text();
   QString mother_address=ui->mother_address->text();
   QString mother_local_address=ui->mother_local_add->text();
   QString mother_language=ui->mother_language->text();
   QString mother_living;
   if(ui->mother_living_yes->isChecked())
   {
       mother_living="yes";
   }
   else
   {
       mother_living="no";
    }
   QString mother_mobile=ui->mother_mobile->text();
   QString mother_occupation=ui->mother_occupation->text();
   QString home_ph1=ui->homephone->text();
   QString home_phn2=ui->homephone_2->text();
   QString email=ui->mother_email->text();
   QString emergency_contact=ui->emergency_cnt->text();
   QString guardian_name=ui->guardianname->text();
   QString guardian_contact=ui->guardian_cnt->text();
   QString guradian_occup=ui->guardian_occupation->text();
   QString guardian_address=ui->guardian_add->text();
   QString guardian_relation=ui->relation->text();
   QString details=ui->details->toPlainText();
   QString academic_details=ui->assignedclass->currentText();

   database *db=new database;
  int result= db->toddlers_add(admission,roll,firstname,middlename,lastname,dob,nepaliname,nepalidob,nationality,caste,birthplace,religion,student_language,language,father_name,father_address,father_local_address,father_living,
                    father_birthplace,father_mobile,father_occupation,mother_name,mother_birthplace,mother_address,mother_local_address,mother_living,mother_language,
                    mother_mobile,mother_occupation,home_ph1,home_phn2,email,emergency_contact,guardian_name,guardian_contact,guradian_occup,guardian_address,guardian_relation,details,academic_details);
if(result)
{
    QMessageBox::information(this,"SUCCESS","DATA ADDED",QMessageBox::Ok);
    return;
}
QMessageBox::information(this,"ERROR","CANNOT ADD",QMessageBox::Ok);
}

void addtoddlers::on_tabWidget_currentChanged(int index)
{

}

void addtoddlers::on_pushButton_4_clicked()
{

}

void addtoddlers::on_firstname_editingFinished()
{
    QString name=ui->firstname->text();
  name[0] = name.at(0).toTitleCase();
 ui->firstname->setText(name);
}

void addtoddlers::on_firstname_selectionChanged()
{
    QString fname=ui->firstname->text();
    fname[0] = fname.at(0).toTitleCase();
    ui->firstname->setText(fname);
}

void addtoddlers::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->comboBox->setEnabled(true);
    }
    else
    {
        ui->comboBox->setEnabled(false);
    }

}

void addtoddlers::on_dateEdit_dateChanged(const QDate &date)
{
   int year;
   int day;
   int month;
   year=ui->dateEdit->date().year();
   day=ui->dateEdit->date().day();
   month=ui->dateEdit->date().month();
   dateconversion *dc=new dateconversion;

    QString dt=dc->cnvToNepali(year,month,day);
       ui->txt_dob_nepali->setText(dt);
}

void addtoddlers::on_firstname_cursorPositionChanged(int arg1, int arg2)
{

}

void addtoddlers::on_middlename_editingFinished()
{
    QString middle=ui->middlename->text();
    middle[0]=middle.at(0).toUpper();
    ui->middlename->setText(middle);
}

void addtoddlers::on_lastname_editingFinished()
{
    QString lastname=ui->lastname->text();
    lastname[0]=lastname.at(0).toUpper();
    ui->lastname->setText(lastname);
}
