#ifndef VIEW_STOCK_H
#define VIEW_STOCK_H

#include <QWidget>

namespace Ui {
class view_stock;
}

class view_stock : public QWidget
{
    Q_OBJECT

public:
    explicit view_stock(QWidget *parent = 0);
    ~view_stock();

private slots:
    void on_productname_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::view_stock *ui;
};

#endif // VIEW_STOCK_H
