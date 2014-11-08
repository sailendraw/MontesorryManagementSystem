#include "vendor_details.h"
#include "ui_vendor_details.h"

vendor_details::vendor_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vendor_details)
{
    ui->setupUi(this);
}

vendor_details::~vendor_details()
{
    delete ui;
}
