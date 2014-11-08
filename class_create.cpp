#include "class_create.h"
#include "ui_class_create.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *mdl;
class_create::class_create(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::class_create)
{
    ui->setupUi(this);
    mdl=new QSqlTableModel(this);
    mdl->setTable("class");
    mdl->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mdl->select();
       mdl->setHeaderData(1,Qt::Horizontal,tr("classname"));
    mdl->setHeaderData(2,Qt::Horizontal,tr("no of student"));
ui->tableView->setModel(mdl);








}



class_create::~class_create()
{
    delete ui;
}

void class_create::on_pushButton_clicked()
{
database *rs=new database;
QString username=ui->classname->text();
QString nostudent=ui->noofstudent->text();
if(username.isEmpty()||nostudent.isEmpty())
{
ui->errormsg->setText("<h1>FIELD EMPTY</h1>");
return;
}
ui->errormsg->clear();
int ok=rs->add_class(username,nostudent);

    if(ok)
    {
        ui->successlbl->setText("Class created Successfully");
        mdl->select();
        ui->tableView->setModel(mdl);
        return;
    }
ui->successlbl->setText("<h3>Error in Creating Class</h3>");

}

void class_create::on_classname_cursorPositionChanged(int arg1, int arg2)
{
    ui->errormsg->clear();
}
void class_create::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter)
    {
        mdl->database().transaction();
            if (mdl->submitAll()) {
                mdl->database().commit();
            } else {
                mdl->database().rollback();

    }
    }
}
