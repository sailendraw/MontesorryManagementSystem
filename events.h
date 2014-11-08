#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

namespace Ui {
class events;
}

class events : public QWidget
{
    Q_OBJECT

public:
    explicit events(QWidget *parent = 0);
    ~events();

private slots:
    void on_save_clicked();

private:
    Ui::events *ui;
};

#endif // EVENTS_H
