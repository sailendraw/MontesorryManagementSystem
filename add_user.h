#ifndef ADD_USER_H
#define ADD_USER_H

#include <QMainWindow>

namespace Ui {
class Add_user;
}

class Add_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_user(QWidget *parent = 0);
    ~Add_user();

private slots:
    void on_pushButton_clicked();

    void on_confirm_password_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

private:
    Ui::Add_user *ui;
};

#endif // ADD_USER_H
