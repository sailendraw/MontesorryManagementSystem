#include "expenses_heading.h"
#include "ui_expenses_heading.h"
#include "database.h"
#include "QSqlTableModel"
QSqlTableModel *exp;
expenses_heading::expenses_heading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expenses_heading)
{
    ui->setupUi(this);
    exp=new QSqlTableModel(this);
    exp->setTable("expenses_creation");
    exp->setHeaderData(1,Qt::Horizontal,("Expense Heading"));
    exp->select();
ui->tableView->setModel(exp);
ui->tableView->resizeRowsToContents();
ui->tableView->resizeRowsToContents();

}

expenses_heading::~expenses_heading()
{
    delete ui;
}

void expenses_heading::on_savebtn_clicked()
{
   QString name=ui->title->text();
   QString desc=ui->description->toPlainText();
   database *db=new database;
  int ok=db->expenseheading(name,desc);
  if(ok)
  {
      ui->message->setText("Insertion Success");
      exp->select();
      ui->tableView->setModel(exp);
      return;
  }
  else
  {
      ui->message->setText("Insertion Failed");
  }
}
