#include "payduefee.h"
#include "ui_payduefee.h"

payduefee::payduefee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payduefee)
{
    ui->setupUi(this);
    setWindowTitle("PAY DUE ..::..Toddlers' Zone Montessory Management system");
}

payduefee::~payduefee()
{
    delete ui;
}
