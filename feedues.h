#ifndef FEEDUES_H
#define FEEDUES_H

#include <QWidget>

namespace Ui {
class Feedues;
}

class Feedues : public QWidget
{
    Q_OBJECT

public:
    explicit Feedues(QWidget *parent = 0);
    ~Feedues();

private:
    Ui::Feedues *ui;
};

#endif // FEEDUES_H
