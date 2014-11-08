#include "feedues.h"
#include "ui_feedues.h"

Feedues::Feedues(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Feedues)
{
    ui->setupUi(this);
}

Feedues::~Feedues()
{
    delete ui;
}
