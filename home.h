#ifndef HOME_H
#define HOME_H

#include <QWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    void display_events();
    void display_stock();
    ~Home();

private:
    Ui::Home *ui;
};

#endif // HOME_H
