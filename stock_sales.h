#ifndef STOCK_SALES_H
#define STOCK_SALES_H

#include <QWidget>

namespace Ui {
class stock_sales;
}

class stock_sales : public QWidget
{
    Q_OBJECT

public:
    explicit stock_sales(QWidget *parent = 0);
    ~stock_sales();

private slots:
    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_qty_cursorPositionChanged(int arg1, int arg2);

    void on_amtpaid_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

private:
    Ui::stock_sales *ui;
};

#endif // STOCK_SALES_H
