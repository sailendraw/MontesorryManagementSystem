#ifndef ADDEXTRAFEE_H
#define ADDEXTRAFEE_H

#include <QWidget>

namespace Ui {
class addextrafee;
}

class addextrafee : public QWidget
{
    Q_OBJECT

public:
    explicit addextrafee(QWidget *parent = 0);
    ~addextrafee();

private slots:
    void on_savebtn_clicked();
    void display();

private:
    Ui::addextrafee *ui;
};

#endif // ADDEXTRAFEE_H
