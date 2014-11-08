#ifndef FEE_DUE_REPORT_H
#define FEE_DUE_REPORT_H

#include <QWidget>

namespace Ui {
class fee_due_report;
}

class fee_due_report : public QWidget
{
    Q_OBJECT

public:
    explicit fee_due_report(QWidget *parent = 0);
    void displaydata();
    ~fee_due_report();

private slots:
    void on_studentlist_activated(const QString &arg1);

    void on_month_currentIndexChanged(const QString &arg1);

private:
    Ui::fee_due_report *ui;
};

#endif // FEE_DUE_REPORT_H
