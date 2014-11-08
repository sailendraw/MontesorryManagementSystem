#ifndef SEARCHTEACHER_H
#define SEARCHTEACHER_H

#include <QMainWindow>

namespace Ui {
class searchteacher;
}

class searchteacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchteacher(QWidget *parent = 0);
    ~searchteacher();

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::searchteacher *ui;
};

#endif // SEARCHTEACHER_H
