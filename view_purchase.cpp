#include "view_purchase.h"
#include "ui_view_purchase.h"

view_purchase::view_purchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view_purchase)
{
    ui->setupUi(this);
}

view_purchase::~view_purchase()
{
    delete ui;
}
