#ifndef EVALUATION_REPORT_H
#define EVALUATION_REPORT_H
#include "qtrpt.h"
#include <QWidget>

namespace Ui {
class Evaluation_report;
}

class Evaluation_report : public QWidget
{
    Q_OBJECT

public:
    explicit Evaluation_report(QWidget *parent = 0);
    ~Evaluation_report();

private slots:
    void on_pushButton_clicked();

    void on_studentlist_currentIndexChanged(const QString &arg1);
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

private:
    Ui::Evaluation_report *ui;
    QtRPT *report;
};

#endif // EVALUATION_REPORT_H
