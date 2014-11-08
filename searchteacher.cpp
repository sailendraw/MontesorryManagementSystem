#include "searchteacher.h"
#include "ui_searchteacher.h"
#include "QSqlTableModel"
#include "QSqlQueryModel"
searchteacher::searchteacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchteacher)
{
    ui->setupUi(this);
    QSqlTableModel *model;
    model = new QSqlTableModel(this);
         model->setTable("staff");
         model->setEditStrategy(QSqlTableModel::OnManualSubmit);
         model->setHeaderData(0, Qt::Horizontal, tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, tr("First name"));
         model->setHeaderData(2, Qt::Horizontal, tr("Last name"));
         ui->tableView->setModel(model);
         ui->tableView->resizeColumnsToContents();
         ui->tableView->resizeRowsToContents();
}

searchteacher::~searchteacher()
{
    delete ui;
}

void searchteacher::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
QString name=ui->lineEdit->text();
QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from staff where Firstname like '"+name+"%'");
     ui->tableView->setModel(model);

}
