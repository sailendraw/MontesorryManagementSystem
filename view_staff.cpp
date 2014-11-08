#include "view_staff.h"
#include "ui_view_staff.h"

view_staff::view_staff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view_staff)
{
    ui->setupUi(this);
}

view_staff::~view_staff()
{
    delete ui;
}

void view_staff::on_lineEdit_textChanged(const QString &arg1)
{

}
