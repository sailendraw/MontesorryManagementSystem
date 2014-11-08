#ifndef ADD_VENDOR_H
#define ADD_VENDOR_H

#include <QWidget>

namespace Ui {
class add_vendor;
}

class add_vendor : public QWidget
{
    Q_OBJECT

public:
    explicit add_vendor(QWidget *parent = 0);
    ~add_vendor();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::add_vendor *ui;
};

#endif // ADD_VENDOR_H
