#ifndef TODDLERSMASTER_H
#define TODDLERSMASTER_H

#include <QMainWindow>

namespace Ui {
class toddlersmaster;
}

class toddlersmaster : public QMainWindow
{
    Q_OBJECT

public:
    explicit toddlersmaster(QWidget *parent = 0);
    ~toddlersmaster();

private slots:
    void on_save_clicked();

    void on_txtfirstname_editingFinished();

    void on_txtmiddlename_editingFinished();

    void on_txtlname_editingFinished();

private:
    Ui::toddlersmaster *ui;
};

#endif // TODDLERSMASTER_H
