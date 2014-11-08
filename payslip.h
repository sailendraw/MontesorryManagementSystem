#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <QMainWindow>

namespace Ui {
class payslip;
}

class payslip : public QMainWindow
{
    Q_OBJECT

public:
    explicit payslip(QWidget *parent = 0);
    void displaynumber();
    ~payslip();

private slots:
    void on_paid_cursorPositionChanged(int arg1, int arg2);

    void on_stafflist_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::payslip *ui;
};

#endif // PAYSLIP_H
