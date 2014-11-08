#ifndef SEARCH_H
#define SEARCH_H
#include <QMainWindow>

namespace Ui {
class Search;
}

class Search : public QMainWindow
{
    Q_OBJECT

public:
    void display(QString);
    void sh();
    explicit Search(QWidget *parent = 0);

    ~Search();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_payduue_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
