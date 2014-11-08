#ifndef VIEW_PURCHASE_H
#define VIEW_PURCHASE_H

#include <QWidget>

namespace Ui {
class view_purchase;
}

class view_purchase : public QWidget
{
    Q_OBJECT

public:
    explicit view_purchase(QWidget *parent = 0);
    ~view_purchase();

private:
    Ui::view_purchase *ui;
};

#endif // VIEW_PURCHASE_H
