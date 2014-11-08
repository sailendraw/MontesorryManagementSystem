#ifndef FEE_SUBMISSION_H
#define FEE_SUBMISSION_H
#include "QtRPT/qtrpt.h"
#include <QWidget>

namespace Ui {
class fee_submission;
}

class fee_submission : public QWidget
{
    Q_OBJECT

public:
    explicit fee_submission(QWidget *parent = 0);
    void displayfee(QString);
    QtRPT *report;
    ~fee_submission();

private:
    Ui::fee_submission *ui;

public slots:
    void stdlst();
private slots:
    void on_save_clicked();
    void on_classlist_currentTextChanged(const QString &arg1);
    void on_student_currentIndexChanged(const QString &arg1);
    void on_paid_cursorPositionChanged(int arg1, int arg2);
    void on_save_2_clicked();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

    void on_toolButton_clicked();
};

#endif // FEE_SUBMISSION_H
