#ifndef ADDTODDLERS_H
#define ADDTODDLERS_H
#include "QSqlQueryModel"
#include <QMainWindow>

namespace Ui {
class addtoddlers;
}

class addtoddlers : public QMainWindow
{
    Q_OBJECT

public:
    explicit addtoddlers(QWidget *parent = 0);
       ~addtoddlers();

private slots:
    void on_pushButton_3_clicked();
   void on_dateEdit_userDateChanged(const QDate &date);

    void on_checkBox_2_clicked();

    void on_scholarship_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_4_clicked();

    void on_firstname_editingFinished();

    void on_firstname_selectionChanged();

    void on_checkBox_clicked();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_firstname_cursorPositionChanged(int arg1, int arg2);

    void on_middlename_editingFinished();

    void on_lastname_editingFinished();

private:
    Ui::addtoddlers *ui;
};

#endif // ADDTODDLERS_H
