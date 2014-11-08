#ifndef DAILYSALES_H
#define DAILYSALES_H

#include <QWidget>

namespace Ui {
class Dailysales;
}

class Dailysales : public QWidget
{
    Q_OBJECT

public:
    explicit Dailysales(QWidget *parent = 0);
    ~Dailysales();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);

private:
    Ui::Dailysales *ui;
};

#endif // DAILYSALES_H
