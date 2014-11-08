#ifndef DATABASE_H
#define DATABASE_H
#include "QString"
#include "QTableView"
class database
{
public:
    database();
    int login_check(QString ,QString );
    int db_connection();
    void show_user();
    int insert(QString,QString,QString,QString,QString);
    int add_class(QString,QString);
    int toddlers_add(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,
                     QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    QStringList classlist();
    QStringList studentlist(QString);
    int insert_staff(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,
                     QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    int insert_Vendor(QString,QString,QString);
    QStringList vendor_list();
    int insert_product(QString,QString);
    QStringList product_list();
    int insert_stock(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    int fee_crtn(QString,QString,QString,QString);
    int discount(QString,QString,QString);
    int expenseheading(QString,QString);
    QStringList expenselist();
    int expense_add(QDate,QString,QString);
    QStringList stafflist();
   void take_attendance(QString,QString,QString,QString);
   void fee_submission(QString,QString,QString,QString,QString,QString,QString,QString);
   void delete_student(QString);
   int staff_attendance(QString,QString,QString,QString);
   QString staff_salary_amount(QString);
int insert_salary(QString,QString,QString,QString,QString,QString,QString);
QStringList student_list();
int insert_sales(QString,QString,QString,QString,QString,QString,QString);
int event_cr(QString,QString,QString);
void db_close();
int insert_xtra_fee(QString,QString);
QStringList xtrafe();
int fee_assigned(QString stdname, QString cl, QString feeheading, QString amt);
int pre_bill_insert(QString,QString);
int update_student(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
QStringList subjectlist();
int firstterm(QString,QString,QString,QString,QString);
int secondterm(QString,QString,QString,QString,QString);
int finalterm(QString marks, QString total, QString band, QString name, QString subject);
int firstmidterm(QString,QString,QString,QString);
int secondmidterm(QString,QString,QString,QString);
int finalmidterm(QString,QString,QString,QString);

};

#endif // DATABASE_H
