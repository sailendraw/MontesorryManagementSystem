#include "attend_report.h"
#include "ui_attend_report.h"

attend_report::attend_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attend_report)
{
    ui->setupUi(this);
}

attend_report::~attend_report()
{
    delete ui;
}
