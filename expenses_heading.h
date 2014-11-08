#ifndef EXPENSES_HEADING_H
#define EXPENSES_HEADING_H

#include <QWidget>

namespace Ui {
class expenses_heading;
}

class expenses_heading : public QWidget
{
    Q_OBJECT

public:
    explicit expenses_heading(QWidget *parent = 0);
    ~expenses_heading();

private slots:
    void on_savebtn_clicked();

private:
    Ui::expenses_heading *ui;
};

#endif // EXPENSES_HEADING_H
