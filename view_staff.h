#ifndef VIEW_STAFF_H
#define VIEW_STAFF_H

#include <QWidget>

namespace Ui {
class view_staff;
}

class view_staff : public QWidget
{
    Q_OBJECT

public:
    explicit view_staff(QWidget *parent = 0);
    ~view_staff();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::view_staff *ui;
};

#endif // VIEW_STAFF_H
