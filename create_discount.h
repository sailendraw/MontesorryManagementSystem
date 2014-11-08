#ifndef CREATE_DISCOUNT_H
#define CREATE_DISCOUNT_H

#include <QWidget>

namespace Ui {
class create_discount;
}

class create_discount : public QWidget
{
    Q_OBJECT

public:
    explicit create_discount(QWidget *parent = 0);
    ~create_discount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::create_discount *ui;
};

#endif // CREATE_DISCOUNT_H
