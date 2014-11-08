#ifndef PAYDUEFEE_H
#define PAYDUEFEE_H

#include <QWidget>

namespace Ui {
class payduefee;
}

class payduefee : public QWidget
{
    Q_OBJECT

public:
    explicit payduefee(QWidget *parent = 0);
    ~payduefee();

private:
    Ui::payduefee *ui;
};

#endif // PAYDUEFEE_H
