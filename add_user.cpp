#include "add_user.h"
#include "ui_add_user.h"
#include "QSqlTableModel"
#include "QMessageBox"
#include "QString"
#include "database.h"
 QSqlTableModel *model;
Add_user::Add_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_user)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
        model->setTable("login");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("First name"));
        model->setHeaderData(2, Qt::Horizontal, tr("Last name"));
        model->setHeaderData(3, Qt::Horizontal, tr("Username"));
        model->setHeaderData(4, Qt::Horizontal, tr("Password"));
        model->setHeaderData(5, Qt::Horizontal, tr("Status"));

        ui->tableView->setModel(model);

}

Add_user::~Add_user()
{
    delete ui;
}

void Add_user::on_pushButton_clicked()
{
    model->database().transaction();
        if (model->submitAll()) {
            model->database().commit();
            ui->error->setText("DATA UPDATED");
        } else {
            model->database().rollback();
            QMessageBox::warning(this, tr("Add user"), tr("The database reported an error: %1"));

}
}

void Add_user::on_confirm_password_cursorPositionChanged(int arg1, int arg2)
{
    QString pwd=ui->password->text();
    QString pwd1=ui->confirm_password->text();
    if((QString::compare(pwd1,pwd))==0)
    {
        ui->error->setText("Password matched");
    }
    else
    {
        ui->error->setText("Password Doesnot matched");
    }
}

void Add_user::on_pushButton_2_clicked()
{
    QString firstname=ui->firstname->text();
    QString lastname=ui->lastname->text();
    QString username=ui->lastname->text();
    QString password=ui->password->text();
    QString status="active";
    if(!(firstname.isNull()||lastname.isNull()||username.isNull()||password.isNull()))
    {
        ui->message->setText("<p align='center'><span style= 'font-size:12pt''; font-weight:600; color:'#f91b04'';>You cannot left field empty!!!</span></p></body></html>");
    }
    {
       database *insrt=new database;
       bool r=insrt->insert(firstname,lastname,username,password,status);
       if(r)
       {
           ui->message->setText("Insertion Success");
           model->select();
       ui->tableView->setModel(model);
       }
       else
       {
           ui->message->setText("Insertion Failed");
       }

    }
}
