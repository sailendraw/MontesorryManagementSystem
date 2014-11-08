#include "upgrade.h"
#include "ui_upgrade.h"
#include "database.h"
#include "QMessageBox"
#include "QCheckBox"
#include "QDebug"
upgrade::upgrade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::upgrade)
{
    ui->setupUi(this);
    database *db=new database;
    QStringList current_class=db->classlist();
    QStringList upgrade_class=db->classlist();
    ui->comboBox->addItems(current_class);
    ui->upgarde_class->addItems(upgrade_class);
}

upgrade::~upgrade()
{
    delete ui;
}

void upgrade::on_upgradebtn_clicked()
{
    QString current_class=ui->comboBox->currentText();
    QString upgrade_cl=ui->upgarde_class->currentText();
    if(current_class==upgrade_cl)
    {
        QMessageBox::information(this,"Error","You cannot upgrade to same class");
    }
    else
    {
        int size=ui->tableWidget->rowCount();
        for(int i=0;i<size;i++)
        {
        QCheckBox *cb = qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(i,1));
        if(cb->isChecked())
        {
        qDebug()<<"checkd";
        }
        else
        {
            qDebug()<<"not checked";
        }
}
    }
}

void upgrade::on_comboBox_currentTextChanged(const QString &arg1)
{
    database *db=new database;
    QStringList l=db->studentlist(arg1);
    int row=l.size();
QCheckBox *chk[row];
     ui->tableWidget->setRowCount(row);
   ui->tableWidget->setColumnCount(2);
   ui->tableWidget->setHorizontalHeaderLabels(QString("Student Name;upgrade;").split(";"));
   QHeaderView* header = ui->tableWidget->horizontalHeader();
     header->setSectionResizeMode(QHeaderView::Stretch);
for(int i=0;i<row;i++)
{
  chk[i]=new QCheckBox(this);
  chk[i]->setChecked(true);
  chk[i]->setText("Upgrade");
ui->tableWidget->setItem(i,0,new QTableWidgetItem(l.at(i).toLocal8Bit().constData()));
ui->tableWidget->setCellWidget(i,1,chk[i]);

}
}

void upgrade::on_upgarde_class_currentIndexChanged(const QString &arg1)
{


}


void upgrade::on_upgarde_class_activated(const QString &arg1)
{

}
