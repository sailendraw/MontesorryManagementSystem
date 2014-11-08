#include "feesetup.h"
#include "ui_feesetup.h"
#include "QCheckBox"
#include "QSqlQuery"
#include "QVBoxLayout"
feesetup::feesetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::feesetup)
{


}

feesetup::~feesetup()
{
    delete ui;
}
