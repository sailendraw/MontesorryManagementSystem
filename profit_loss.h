#ifndef PROFIT_LOSS_H
#define PROFIT_LOSS_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class profit_loss;
}

class profit_loss : public QWidget
{
    Q_OBJECT

public:
    explicit profit_loss(QWidget *parent = 0);
    void print();
    ~profit_loss();

private slots:
    void on_pushButton_clicked();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);


private:
    Ui::profit_loss *ui;
    QtRPT *report;
};

#endif // PROFIT_LOSS_H
