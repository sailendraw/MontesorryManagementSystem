#ifndef EVALUATIONSHEET_H
#define EVALUATIONSHEET_H

#include <QWidget>

namespace Ui {
class EvaluationSheet;
}

class EvaluationSheet : public QWidget
{
    Q_OBJECT

public:
    explicit EvaluationSheet(QWidget *parent = 0);
    void displayintable();
    ~EvaluationSheet();

private slots:
    void on_pushButton_clicked();

    void on_termlist_currentIndexChanged(const QString &arg1);

private:
    Ui::EvaluationSheet *ui;
};

#endif // EVALUATIONSHEET_H
