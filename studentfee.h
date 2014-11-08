#ifndef STUDENTFEE_H
#define STUDENTFEE_H

#include <QWidget>

namespace Ui {
class studentfee;
}

class studentfee : public QWidget
{
    Q_OBJECT

public:
    explicit studentfee(QWidget *parent = 0);
    ~studentfee();

private slots:
    void on_comboclass_currentIndexChanged(const QString &arg1);
    void on_toolButton_clicked();

    void on_pushButton_3_clicked();

public slots:
     void selectedid(int);

private:
    Ui::studentfee *ui;
};

#endif // STUDENTFEE_H
