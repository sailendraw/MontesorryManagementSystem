#ifndef EXPENDITURE_H
#define EXPENDITURE_H

#include <QWidget>
#include "qtrpt.h"
namespace Ui {
class Expenditure;
}

class Expenditure : public QWidget
{
    Q_OBJECT

public:
    explicit Expenditure(QWidget *parent = 0);
    void display();
    ~Expenditure();

private slots:
    void on_print_clicked();
 void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
    void on_dateEdit_dateChanged(const QDate &date);

private:
    Ui::Expenditure *ui;
    QtRPT *report;
};

#endif // EXPENDITURE_H
