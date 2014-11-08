#ifndef UPGRADE_H
#define UPGRADE_H

#include <QWidget>

namespace Ui {
class upgrade;
}

class upgrade : public QWidget
{
    Q_OBJECT

public:
    explicit upgrade(QWidget *parent = 0);
    ~upgrade();

private slots:
    void on_upgradebtn_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_upgarde_class_currentIndexChanged(const QString &arg1);

    void on_upgarde_class_activated(const QString &arg1);

private:
    Ui::upgrade *ui;
};

#endif // UPGRADE_H
