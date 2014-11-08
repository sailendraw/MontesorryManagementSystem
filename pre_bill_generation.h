#ifndef PRE_BILL_GENERATION_H
#define PRE_BILL_GENERATION_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class pre_bill_generation;
}

class pre_bill_generation : public QWidget
{
    Q_OBJECT

public:
    explicit pre_bill_generation(QWidget *parent = 0);
    ~pre_bill_generation();

private slots:
    void on_generate_clicked();

    void on_save_clicked();
    void on_month_currentIndexChanged(const QString &arg1);

public slots:
     void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

private:
    Ui::pre_bill_generation *ui;
    QtRPT *report;
};

#endif // PRE_BILL_GENERATION_H
