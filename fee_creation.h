#ifndef FEE_CREATION_H
#define FEE_CREATION_H

#include <QWidget>

namespace Ui {
class fee_creation;
}

class fee_creation : public QWidget
{
    Q_OBJECT

public:
    explicit fee_creation(QWidget *parent = 0);
    ~fee_creation();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fee_creation *ui;
};

#endif // FEE_CREATION_H
