#ifndef VENDOR_DETAILS_H
#define VENDOR_DETAILS_H

#include <QWidget>

namespace Ui {
class vendor_details;
}

class vendor_details : public QWidget
{
    Q_OBJECT

public:
    explicit vendor_details(QWidget *parent = 0);
    ~vendor_details();

private:
    Ui::vendor_details *ui;
};

#endif // VENDOR_DETAILS_H
