#include "login.h"
#include "ui_login.h"
#include<dashboard.h>
#include "QSqlDatabase"
#include "QDebug"
#include "database.h"
#include "QMessageBox"
QString username;
 database *rslt=new database;
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    int rs=rslt->db_connection();
    if(!rs)
    {
        qDebug()<<"ERROR in connecting Database";
        QMessageBox::information(this,"ERROR DATABASE","Error in Connecting to Database",QMessageBox::Ok);
        return;

    }
    ui->txt_username->setFocus();


}

login::~login()
{
    delete ui;
}

void login::on_btn_login_clicked()
{


        username=ui->txt_username->text();
       QString password=ui->txt_password->text();
       if(username.isEmpty() || password.isEmpty())
       {
           ui->error->setText("<p align=center><span style= color:#f91019;>Username or password field is empty</span></p></body></html>");
           ui->txt_username->clear();
           ui->txt_password->clear();
           ui->txt_username->setFocus();
           return;
       }
int ok=rslt->login_check(username,password);
if(ok)
{
     this->hide();
    dashboard *dsh=new dashboard;
    dsh->loggeduser(username);
      dsh->show();
}
else
{
ui->error->setText("<p align=center><span style= color:#f91019;>Username or Password Doesnt match!!!</span></p></body></html>");
ui->txt_username->clear();
ui->txt_password->clear();
ui->txt_username->setFocus();
}
}

void login::on_btn_quit_clicked()
{
    exit(0);
}

void login::on_txt_password_returnPressed()
{
   on_btn_login_clicked();
}
