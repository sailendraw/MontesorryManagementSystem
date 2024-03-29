#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_btn_login_clicked();

    void on_btn_quit_clicked();

    void on_txt_password_returnPressed();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
