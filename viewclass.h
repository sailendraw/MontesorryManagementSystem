#ifndef VIEWCLASS_H
#define VIEWCLASS_H

#include <QWidget>

namespace Ui {
class viewclass;
}

class viewclass : public QWidget
{
    Q_OBJECT

public:
    explicit viewclass(QWidget *parent = 0);
    ~viewclass();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_del_clicked();

private:
    Ui::viewclass *ui;
};

#endif // VIEWCLASS_H
