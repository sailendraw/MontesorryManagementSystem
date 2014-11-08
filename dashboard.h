#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = 0);
    ~dashboard();

public slots:
    void add_student();
    void search_student();
    void edit_student();
    void delete_student();
    void Upgrade();
    void Fee_submission();
    void evaluationsheet();
    void addstaff();
    void viewstaff();
    void salary();
    void purchasereport();
    void salesrpt();
    void eva_sheet();
    void salarysht();
    void fee_defaulter();
    void income_rep();
    void expenditure_rpt();
    void stock_vendor();
    void stock_purchase();
    void stock_details();
    void stocksales();
    void stock_add_product();
    void stock_vendor_details();
    void stock_add();
    void class_cr();
    void view_cl();
    void staffattendace_daily();
    void atten_report();
    void loggeduser(QString);
    void user_add();
    void change_pwd();
    void feecreation();
    void discount();
    void expense();
    void addexpense();
    void student_at();
    void setupfee();
    void dash_home();
    void event();
    void xtraafee();
    void dailyc();
    void dailyfeec();
    void stock_prch();
    void pre_bill();
    void profit_loss_report();
    void evaluation_sheet();
    void evaluation_sheet_report();
    void attendance_report();
    void closeEvent(QCloseEvent *);
private slots:
    void on_dashboard_iconSizeChanged(const QSize &iconSize);

private:
    Ui::dashboard *ui;
};

#endif // DASHBOARD_H
