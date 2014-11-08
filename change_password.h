#ifndef CHANGE_PASSWORD_H
#define CHANGE_PASSWORD_H

#include <QWidget>

namespace Ui {
class change_password;
}

class change_password : public QWidget
{
    Q_OBJECT

public:
    explicit change_password(QWidget *parent = 0);
    ~change_password();

private:
    Ui::change_password *ui;
};

#endif // CHANGE_PASSWORD_H
