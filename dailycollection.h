#ifndef DAILYCOLLECTION_H
#define DAILYCOLLECTION_H

#include <QMainWindow>

namespace Ui {
class DailyCollection;
}

class DailyCollection : public QMainWindow
{
    Q_OBJECT

public:
    explicit DailyCollection(QWidget *parent = 0);
    ~DailyCollection();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);

private:
    Ui::DailyCollection *ui;
};

#endif // DAILYCOLLECTION_H
