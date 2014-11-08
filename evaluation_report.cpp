#include "evaluation_report.h"
#include "ui_evaluation_report.h"
#include "database.h"
#include "QSqlQuery"
Evaluation_report::Evaluation_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Evaluation_report)
{
    ui->setupUi(this);
    database *db=new database;
ui->classlist->addItems(db->classlist());

ui->studentlist->addItems(db->studentlist(ui->classlist->currentText()));

}

Evaluation_report::~Evaluation_report()
{
    delete ui;
}

void Evaluation_report::on_pushButton_clicked()
{
    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
       //   printer.setOutputFileName("nonwritable.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              //return 1;
          }
          QString fileName = "Report/evalulationsheet.xml";
              report = new QtRPT(this);
             // report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
              report->recordCount << ui->tableWidget->rowCount();
              if (report->loadReport(fileName) == false) {
                  qDebug()<<"Report's file not found";
              }
              QObject::connect(report, SIGNAL(setValue(int&, QString&, QVariant&, int)),
                               this, SLOT(setValue(int&, QString&, QVariant&, int)));
                           report->printExec(true);

}

void Evaluation_report::on_studentlist_currentIndexChanged(const QString &arg1)
{
    QSqlQuery qr("SELECT FirstTerm.Subject_id,FirstTerm.First_Mid_Term,FirstTerm.FirstTerm,FirstTerm.Total,FirstTerm.Band,SecondTerm.Second_Mid_Term,SecondTerm.Second_Term,SecondTerm.Total,SecondTerm.Band,ThirdTerm.Final_Mid_Term,ThirdTerm.Final_Term,ThirdTerm.Total,ThirdTerm.Band FROM 	toddlers.FirstTerm FirstTerm,toddlers.SecondTerm SecondTerm,toddlers.ThirdTerm ThirdTerm WHERE FirstTerm.Student_id = SecondTerm.Student_id AND FirstTerm.Student_id = ThirdTerm.Student_id AND FirstTerm.Student_id = '"+arg1+"' AND 	SecondTerm.Student_id = '"+arg1+"' AND 	ThirdTerm.Student_id = '"+arg1+"'");
    int i=0;
    int size=qr.size();
    ui->tableWidget->setRowCount(size);
    while(qr.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(qr.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(qr.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(qr.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(3).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qr.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(qr.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(qr.value(6).toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(qr.value(7).toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(qr.value(8).toString()));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(qr.value(9).toString()));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(qr.value(10).toString()));
        ui->tableWidget->setItem(i,11,new QTableWidgetItem(qr.value(11).toString()));
        ui->tableWidget->setItem(i,12,new QTableWidgetItem(qr.value(12).toString()));
        i++;
    }
}
void Evaluation_report::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage)
{
    Q_UNUSED(reportPage);

         if (paramName == "SN")
            paramValue = recNo+1;
        if (paramName == "Subject") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "FT") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "FTerm") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }
        if (paramName == "FTotal") {
            if (ui->tableWidget->item(recNo,3) == 0) return;
            paramValue = ui->tableWidget->item(recNo,3)->text();
        }
        if (paramName == "FBand") {
            if (ui->tableWidget->item(recNo,4) == 0) return;
            paramValue = ui->tableWidget->item(recNo,4)->text();
        }
        if (paramName == "ST") {
            if (ui->tableWidget->item(recNo,5) == 0) return;
            paramValue = ui->tableWidget->item(recNo,5)->text();
        }
        if (paramName == "STerm") {
            if (ui->tableWidget->item(recNo,6) == 0) return;
            paramValue = ui->tableWidget->item(recNo,6)->text();
        }
        if (paramName == "STotal") {
            if (ui->tableWidget->item(recNo,7) == 0) return;
            paramValue = ui->tableWidget->item(recNo,7)->text();
        }
        if (paramName == "SBand") {
            if (ui->tableWidget->item(recNo,8) == 0) return;
            paramValue = ui->tableWidget->item(recNo,8)->text();
        }
        if (paramName == "TT") {
            if (ui->tableWidget->item(recNo,9) == 0) return;
            paramValue = ui->tableWidget->item(recNo,9)->text();
        }
        if (paramName == "TTerm") {
            if (ui->tableWidget->item(recNo,10) == 0) return;
            paramValue = ui->tableWidget->item(recNo,10)->text();
        }
        if (paramName == "FTotal") {
            if (ui->tableWidget->item(recNo,11) == 0) return;
            paramValue = ui->tableWidget->item(recNo,11)->text();
        }
        if (paramName == "FBand") {
            if (ui->tableWidget->item(recNo,12) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }











}
