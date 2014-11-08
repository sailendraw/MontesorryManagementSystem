#include "change_password.h"
#include "ui_change_password.h"

change_password::change_password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_password)
{
    ui->setupUi(this);
    setWindowTitle("Change Password");
}

change_password::~change_password()
{
    delete ui;
}
