#ifndef DATECONVERSION_H
#define DATECONVERSION_H

#include <QMainWindow>

class dateconversion : public QMainWindow
{
    Q_OBJECT
public:
    explicit dateconversion(QWidget *parent = 0);
    int is_leap_year(int);
    QString cnvToNepali(int, int , int);
    QString get_nepali_month(int);
    QString get_day_of_week(int);
signals:

public slots:

};

#endif // DATECONVERSION_H
