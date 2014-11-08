#ifndef EDITCLASS_H
#define EDITCLASS_H

#include <QWidget>

namespace Ui {
class editclass;
}

class editclass : public QWidget
{
    Q_OBJECT

public:
    explicit editclass(QWidget *parent = 0);
    QString id;
    ~editclass();

public:
    Ui::editclass *ui;
};

#endif // EDITCLASS_H
