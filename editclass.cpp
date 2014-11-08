#include "editclass.h"
#include "ui_editclass.h"

editclass::editclass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editclass)
{
    ui->setupUi(this);
    ui->classname->setText(id);
}

editclass::~editclass()
{
    delete ui;
}
