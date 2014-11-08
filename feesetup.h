#ifndef FEESETUP_H
#define FEESETUP_H

#include <QWidget>

namespace Ui {
class feesetup;
}

class feesetup : public QWidget
{
    Q_OBJECT

public:
    explicit feesetup(QWidget *parent = 0);
    ~feesetup();

private:
    Ui::feesetup *ui;
};

#endif // FEESETUP_H
