#ifndef ADDEXPENSES_H
#define ADDEXPENSES_H

#include <QWidget>

namespace Ui {
class addexpenses;
}

class addexpenses : public QWidget
{
    Q_OBJECT

public:
    explicit addexpenses(QWidget *parent = 0);
    ~addexpenses();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addexpenses *ui;
};

#endif // ADDEXPENSES_H
