#ifndef CLASS_CREATE_H
#define CLASS_CREATE_H
#include "QKeyEvent"
#include <QMainWindow>

namespace Ui {
class class_create;
}

class class_create : public QMainWindow
{
    Q_OBJECT

public:
    explicit class_create(QWidget *parent = 0);
    ~class_create();

private slots:
    void on_pushButton_clicked();

    void on_classname_cursorPositionChanged(int arg1, int arg2);
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::class_create *ui;
};

#endif // CLASS_CREATE_H
