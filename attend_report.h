#ifndef ATTEND_REPORT_H
#define ATTEND_REPORT_H

#include <QWidget>

namespace Ui {
class attend_report;
}

class attend_report : public QWidget
{
    Q_OBJECT

public:
    explicit attend_report(QWidget *parent = 0);
    ~attend_report();

private:
    Ui::attend_report *ui;
};

#endif // ATTEND_REPORT_H
