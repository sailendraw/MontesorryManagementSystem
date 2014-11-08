#include "dashboard.h"
#include "ui_dashboard.h"
#include "QDateTime"
#include "QToolBar"
#include "QToolButton"
#include"QDebug"
#include"addtoddlers.h"
#include "view_staff.h"
#include "view_purchase.h"
//#include "add_user.h"
#include "add_product.h"
#include "add_vendor.h"
#include "payslip.h"
#include "fee_submission.h"
#include "search.h"
#include "upgrade.h"
#include "toddlersmaster.h"
#include "searchteacher.h"
#include "purchase_report.h"
#include "sales_report.h"
#include "salarysheet.h"
#include "fee_due_report.h"
#include "income_report.h"
#include "expenditure.h"
#include "stock_sales.h"
#include "add_vendor.h"
#include "add_product.h"
#include "vendor_details.h"
#include "product_add.h"
#include "class_create.h"
#include "viewclass.h"
#include "staff_attendance.h"
#include "attend_report.h"
//#include "add_user.h"
#include "add_user.h"
#include "view_stock.h"
#include "fee_creation.h"
#include "create_discount.h"
#include "expenses_heading.h"
#include "addexpenses.h"
#include "product_add.h"
#include "student_attendance.h"
#include "studentfee.h"
#include "staff_attendance_report.h"
#include "home.h"
#include "events.h"
#include "addextrafee.h"
#include "dailysales.h"
#include "dailycollection.h"
#include "pre_bill_generation.h"
#include "profit_loss.h"
#include "evaluationsheet.h"
#include "evaluation_report.h"
#include "student_attendance_report.h"
#include "QEvent"
#include "QMessageBox"
dashboard::dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
    QString t;
    QDateTime *n= new QDateTime;
    t=n->currentDateTime().toString();
    ui->label_2->setText(t);
    setWindowTitle("Toddlers Montessary Management System");
   setWindowState(Qt::WindowMaximized);
dash_home();

           QToolButton *studentButton=new QToolButton(this);
           QToolButton *staffButton=new QToolButton(this);
           QToolButton *ReportButton=new QToolButton(this);
          QToolButton *ClassButton=new QToolButton(this);
           QToolButton *ExitButton=new QToolButton(this);
           QToolButton *settings=new QToolButton(this);
           QToolButton *stock= new QToolButton(this);

           studentButton->setText("student");
           staffButton->setText("Staff");
           ReportButton->setText("Report");
            ClassButton->setText("Class");
           ExitButton->setText("Exit");
           settings->setText("Settings");
           stock->setText("Stock");
               //setting icon to toolbutton

           //ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        studentButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        staffButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ReportButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
               ClassButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ExitButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        settings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        stock->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
      //  studentButton->setArrowType(Qt::RightArrow);

        studentButton->setIcon(QIcon(":/icon/girl"));
          staffButton->setIcon(QIcon(":/icon/girl_8"));
          ReportButton->setIcon(QIcon(":/icon/report"));
          ClassButton->setIcon(QIcon(":/icon/School_Clip_Art_162"));
          settings->setIcon(QIcon(":/icon/configure-icon"));
          ExitButton->setIcon(QIcon(":/icon/exit"));
          stock->setIcon((QIcon(":/icon/box3")));
          //finish adding icon



   //setting QAction
          QAction *add_std=new QAction("Add student", this);
          QAction *view_std=new QAction("View", this);
          QAction *up_std=new QAction("upgrade", this);
          QAction *evaluation_std=new QAction("Evaluation sheet", this);
          QAction *bill=new QAction("Fee Submission",this);
           QAction *stu_atten=new QAction("Attendance",this);
          QAction *add_staff=new QAction("Add",this);
          QAction *view_staff= new QAction("View",this);
          QAction  *atten_staff=new QAction("Attendance",this);
          QAction *staff_sal= new QAction("Salary",this);
          QAction *acc_payslip= new QAction("Payslip",this);
          QAction *acc_due= new QAction("Dues",this);
          QAction *fee_sub=new QAction("Fee Reciept",this);
          QAction *stock_vendor=new QAction("Add Vendor",this);
          QAction *stock_product=new QAction("Add product",this);
          QAction *stsales= new QAction("stock sales",this);
          QAction *st_purchase=new QAction("Purchase",this);
          QAction *st_add= new QAction("View Stock",this);
          QAction *class_create=new QAction("Create",this);
          QAction *class_view=new QAction("View",this);
          QAction *report_gen= new QAction("Purchase Report",this);
          QAction *report_gen1=new QAction("Sales Report",this);
          QAction *Report_gen2= new QAction("Evaluation sheet",this);
          QAction *Report_gen3= new QAction("Salarysheet_Report",this);
          QAction *Report_gen4= new QAction("Fee Due Report",this);
          QAction *report_gen5= new QAction("Income",this);
          QAction *report_gen6= new QAction("Total Expenditure",this);
          QAction *report_gen7= new QAction("Staff Attendance",this);
          QAction *report_gen8= new QAction("Profit & Loss",this);
          QAction *event_creation=new QAction("Create Event",this);
          QAction *pre_bill_generation=new QAction("Pre-bill",this);
          QAction *std_atten_report=new QAction("Student Attendance Report",this);
          //QAction *hom= addWidget(*Home);

          //QAction *Ex= new QAction("exit",this);

          //from here submenu on toolbar started



          studentButton->setPopupMode(QToolButton::InstantPopup);
       //  studentButton->setArrowType(Qt::RightArrow);
                  QMenu *saveMenu=new QMenu(studentButton);
                     saveMenu->addAction(add_std);
                     saveMenu->addAction(view_std);
                     saveMenu->addAction(up_std);
                     saveMenu->addAction(evaluation_std);
                     saveMenu->addAction((bill));
                     saveMenu->addAction(stu_atten);
                     studentButton->setMenu(saveMenu);
                     saveMenu->addAction(pre_bill_generation);
staffButton->setPopupMode(QToolButton::InstantPopup);
                     QMenu *staff= new QMenu(staffButton);
                     staff->addAction(add_staff);
                     staff->addAction(view_staff);
                     staff->addAction(atten_staff);
                     staff->addAction(staff_sal);
                     staffButton->setMenu(staff);

stock->setPopupMode(QToolButton::InstantPopup);
QMenu *stockm= new QMenu(stock);
stockm->addAction(stock_vendor);
stockm->addAction(stock_product);
stockm->addAction(stsales);
stockm->addAction(st_purchase);
stockm->addAction(st_add);
stock->setMenu(stockm);

ClassButton->setPopupMode(QToolButton::InstantPopup);
QMenu *cl= new QMenu(ClassButton);
cl->addAction(class_create);
cl->addAction(class_view);
ClassButton->setMenu(cl);

ReportButton->setPopupMode(QToolButton::InstantPopup);
QMenu *rpt= new QMenu(ReportButton);
rpt->addAction(report_gen);
rpt->addAction(report_gen1);
rpt->addAction(Report_gen2);
rpt->addAction(Report_gen3);
rpt->addAction(Report_gen4);
rpt->addAction(report_gen5);
rpt->addAction(report_gen6);
rpt->addAction(report_gen7);
rpt->addAction(report_gen8);
rpt->addAction(std_atten_report);
ReportButton->setMenu(rpt);

//QMenu *ext= new QMenu(ExitButton);
//ExitButton->setMenu(ext);

settings->setPopupMode(QToolButton::InstantPopup);
QMenu *jpt=new QMenu(settings);
jpt->addAction(ui->actionAdd_user);
jpt->addAction(ui->actionChange_password);
jpt->addAction(event_creation);
settings->setMenu(jpt);





          ui->toolBar->addWidget(studentButton);
          ui->toolBar->addSeparator();
          ui->toolBar->addWidget(staffButton);
          ui->toolBar->addSeparator();
          ui->toolBar->addWidget(ClassButton);
          ui->toolBar->addSeparator();
          ui->toolBar->addWidget(stock);
          ui->toolBar->addSeparator();
           ui->toolBar->addWidget(ReportButton);
          ui->toolBar->addSeparator();
          ui->toolBar->addWidget((settings));
          ui->toolBar->addSeparator();
          ui->toolBar->addWidget(ExitButton);
          ui->toolBar->addSeparator();
            //ui->toolBar->setStyleSheet();



          //connecting action with slots
         connect(add_std,SIGNAL(triggered()),this,SLOT(add_student()));
         connect(view_std,SIGNAL(triggered()),this,SLOT(search_student()));
         connect(up_std,SIGNAL(triggered()),this,SLOT(Upgrade()));
         connect(evaluation_std,SIGNAL(triggered()),this,SLOT(evaluationsheet()));
         connect(bill,SIGNAL(triggered()),this,SLOT(Fee_submission()));
         connect(add_staff,SIGNAL(triggered()),this,SLOT(addstaff()));
         connect(view_staff,SIGNAL(triggered()),this,SLOT(viewstaff()));
         connect(staff_sal,SIGNAL(triggered()),this,SLOT(salary()));
         //connect(ExitButton,SIGNAL(triggered()),this,SLOT(hide()));
         connect(report_gen,SIGNAL(triggered()),this,SLOT(purchasereport()));
         connect(report_gen1,SIGNAL(triggered()),this,SLOT(salesrpt()));
         connect(Report_gen2,SIGNAL(triggered()),this,SLOT(eva_sheet()));
         connect(Report_gen3,SIGNAL(triggered()),this,SLOT(salarysht()));
         connect(Report_gen4,SIGNAL(triggered()),this,SLOT(fee_defaulter()));
         connect(report_gen5,SIGNAL(triggered()),this,SLOT(income_rep()));
         connect(report_gen6,SIGNAL(triggered()),this,SLOT(expenditure_rpt()));
         connect(stock_vendor,SIGNAL(triggered()),this,SLOT(stock_vendor()));
         connect(stock_product,SIGNAL(triggered()),this,SLOT(stock_add_product()));
         connect(st_add,SIGNAL(triggered()),this,SLOT(stock_add()));
         connect(stsales,SIGNAL(triggered()),this,SLOT(stocksales()));
         connect(st_purchase,SIGNAL(triggered()),this,SLOT(stock_prch()));
         connect(class_create,SIGNAL(triggered()),this,SLOT(class_cr()));
         connect(class_view,SIGNAL(triggered()),this,SLOT(view_cl()));
         connect(atten_staff,SIGNAL(triggered()),this,SLOT(staffattendace_daily()));
         connect(report_gen7,SIGNAL(triggered()),this,SLOT(atten_report()));
         connect(ui->actionAdd_user,SIGNAL(triggered()),this,SLOT(user_add()));
         connect(ui->actionAdd_Category,SIGNAL(triggered()),this,SLOT(feecreation()));
         connect(ui->actionAdd_Discount,SIGNAL(triggered()),this,SLOT(discount()));
         connect(ui->actionAdd_Heading,SIGNAL(triggered()),this,SLOT(expense()));
         connect(ui->actionExpenses_Details,SIGNAL(triggered()),this,SLOT(addexpense()));
         connect(stu_atten,SIGNAL(triggered()),this,SLOT(student_at()));
        connect(ui->actionFee_Setup,SIGNAL(triggered()),this,SLOT(setupfee()));
        connect(ui->actionHome,SIGNAL(triggered()),this,SLOT(dash_home()));
        connect(event_creation,SIGNAL(triggered()),this,SLOT(event()));
        connect(ui->actionExtra_Fee,SIGNAL(triggered()),this,SLOT(xtraafee()));
        connect(ui->actionDaily_Sales_Collection,SIGNAL(triggered()),this,SLOT(dailyc()));
        connect(ui->actionDaily_Fee_Collection,SIGNAL(triggered()),this,SLOT(dailyfeec()));
        connect(pre_bill_generation,SIGNAL(triggered()),this,SLOT(pre_bill()));
        connect(report_gen8,SIGNAL(triggered()),this,SLOT(profit_loss_report()));
        connect(evaluation_std,SIGNAL(triggered()),this,SLOT(evaluation_sheet()));
        connect(Report_gen2,SIGNAL(triggered()),this,SLOT(evaluation_sheet_report()));
        connect(std_atten_report,SIGNAL(triggered()),this,SLOT(attendance_report()));
        QEvent *event;
        if (event->type() == QEvent::Close) {
               QMessageBox::information(this,"Close?","Are you sure you want to quit application",QMessageBox::Ok,QMessageBox::Cancel);
            }

}

dashboard::~dashboard()
{
    delete ui;
}
void dashboard::add_student()
{
addtoddlers *todd=new addtoddlers;
ui->container->addWidget(todd);
ui->container->setCurrentWidget(todd);
todd->show();
todd->activateWindow();
}
void dashboard::search_student()
{
    Search *srch=new Search;
    ui->container->addWidget(srch);
    ui->container->setCurrentWidget(srch);
    srch->show();
    srch->activateWindow();
}
void dashboard::edit_student()
{
qDebug()<<"Everything is fine";
}
void dashboard::delete_student()
{
qDebug()<<"Everything is fine";
}
void dashboard::Fee_submission()
{
    fee_submission *fee=new fee_submission;
    ui->container->addWidget(fee);
    ui->container->setCurrentWidget(fee);
    fee->show();
    fee->activateWindow();
}
void dashboard::Upgrade()
{
  upgrade *up= new upgrade;
  ui->container->addWidget(up);
  ui->container->setCurrentWidget(up);
  up->show();
  up->activateWindow();
}
void dashboard::evaluationsheet()
{
    qDebug()<<"Everything is fine";
}
void dashboard::addstaff()
{
    toddlersmaster *t= new toddlersmaster;
    ui->container->addWidget(t);
    ui->container->setCurrentWidget(t);
    t->show();
    t->activateWindow();
}
void dashboard::viewstaff()
{
    searchteacher *tchr=new searchteacher;
    ui->container->addWidget(tchr);
    ui->container->setCurrentWidget(tchr);
    tchr->show();
    tchr->activateWindow();
}
void dashboard::salary()
{
    payslip *pay= new payslip;
    ui->container->addWidget(pay);
    ui->container->setCurrentWidget(pay);
    pay->show();
    pay->activateWindow();
}
void dashboard::purchasereport()
{
purchase_report *p= new purchase_report;
ui->container->addWidget(p);
ui->container->setCurrentWidget(p);
p->show();
p->activateWindow();
}
void dashboard::salesrpt()
{
sales_report *sal=new sales_report;
ui->container->addWidget(sal);
ui->container->setCurrentWidget(sal);
sal->show();
sal->activateWindow();
}
void dashboard::salarysht()
{
salarysheet *slry= new salarysheet;
ui->container->addWidget(slry);
ui->container->setCurrentWidget(slry);
slry->show();
slry->activateWindow();
}
void dashboard::fee_defaulter()
{
fee_due_report *fee=new fee_due_report;
ui->container->addWidget(fee);
ui->container->setCurrentWidget(fee);
fee->show();
fee->activateWindow();
}
void dashboard::income_rep()
{
    Income_Report *inc= new Income_Report;
    ui->container->addWidget(inc);
    ui->container->setCurrentWidget(inc);
   inc->show();
   inc->activateWindow();
}
void dashboard::expenditure_rpt()
{
    Expenditure *expn=new Expenditure;
    ui->container->addWidget(expn);
    ui->container->setCurrentWidget(expn);
    expn->show();
    expn->activateWindow();
}
void dashboard::eva_sheet()
{

}
void dashboard::stock_add_product()
{
    add_product *prd= new add_product;
    ui->container->addWidget(prd);
    ui->container->setCurrentWidget(prd);
    prd->show();
    prd->activateWindow();
}
void dashboard::stock_details()
{

}
void dashboard::stock_purchase()
{

}
void dashboard::stocksales()
{
stock_sales *st= new stock_sales;
ui->container->addWidget(st);
ui->container->setCurrentWidget(st);
st->show();
st->activateWindow();

}
void dashboard::stock_vendor_details()
{
    vendor_details *vndr= new vendor_details;
    ui->container->addWidget(vndr);
    ui->container->setCurrentWidget(vndr);
    vndr->show();
    vndr->activateWindow();

}
void dashboard::stock_vendor()
{
add_vendor *vnd= new add_vendor;
ui->container->addWidget(vnd);
ui->container->setCurrentWidget(vnd);
vnd->show();
vnd->activateWindow();
}
void dashboard::stock_add()
{
    view_stock *prduct=new view_stock;
    ui->container->addWidget(prduct);
    ui->container->setCurrentWidget(prduct);
    prduct->show();
    prduct->activateWindow();
}
void dashboard::class_cr()
{
    class_create *cl_cr= new class_create;
   ui->container->addWidget(cl_cr);
   ui->container->setCurrentWidget(cl_cr);
   cl_cr->show();
   cl_cr->activateWindow();
}
void dashboard::view_cl()
{
    viewclass *viewcl= new viewclass;
    ui->container->addWidget(viewcl);
    ui->container->setCurrentWidget(viewcl);
    viewcl->show();
    viewcl->activateWindow();
}
void dashboard::staffattendace_daily()
{
    staff_attendance *stf= new staff_attendance;
    ui->container->addWidget(stf);
    ui->container->setCurrentWidget(stf);
    stf->show();
    stf->activateWindow();
}
void dashboard::atten_report()
{
staff_attendance_report *at= new staff_attendance_report;
ui->container->addWidget(at);
ui->container->setCurrentWidget(at);
at->show();
at->activateWindow();
}
void dashboard::loggeduser(QString user)
{
    ui->logged->setText(user);
}
void dashboard::user_add()
{
    Add_user *user= new Add_user;
    ui->container->addWidget(user);
    ui->container->setCurrentWidget(user);
    user->show();
    user->activateWindow();
}
void dashboard::change_pwd()
{

}
void dashboard::feecreation()
{
fee_creation *fee= new fee_creation;
ui->container->addWidget(fee);
ui->container->setCurrentWidget(fee);
fee->show();
fee->activateWindow();
}
void dashboard::discount()
{
create_discount *cr=new create_discount;
ui->container->addWidget(cr);
ui->container->setCurrentWidget(cr);
cr->show();
cr->activateWindow();
}
void dashboard::expense()
{
    expenses_heading *ex=new expenses_heading;
    ui->container->addWidget(ex);
    ui->container->setCurrentWidget(ex);
    ex->show();
    ex->activateWindow();

}

void dashboard::addexpense()
{
addexpenses *eh=new addexpenses;
ui->container->addWidget(eh);
ui->container->setCurrentWidget(eh);
eh->show();
eh->activateWindow();
}
void dashboard::student_at()
{
student_attendance *st=new student_attendance;
ui->container->addWidget(st);
ui->container->setCurrentWidget(st);
st->show();
st->activateWindow();
}
void dashboard::setupfee()
{
    studentfee *fe=new studentfee;
    fe->show();
}
void dashboard::dash_home()
{
    Home *eh= new Home;
    ui->container->addWidget(eh);
    ui->container->setCurrentWidget(eh);
    eh->show();
    eh->activateWindow();
}
void dashboard::event()
{
events * ev=new events;
ev->show();



}
void dashboard::xtraafee()
{
    addextrafee *fm=new addextrafee;
    fm->show();

}
void dashboard::dailyc()
{
    Dailysales *ds= new Dailysales;
    ui->container->addWidget(ds);
    ui->container->setCurrentWidget(ds);
    ds->activateWindow();
    ds->show();

}
void dashboard::dailyfeec()
{
    DailyCollection *dc=new DailyCollection;
    ui->container->addWidget(dc);
    ui->container->setCurrentWidget(dc);
    dc->activateWindow();
    dc->show();

}
void dashboard::stock_prch()
{
    product_add *dc=new product_add;
    ui->container->addWidget(dc);
    ui->container->setCurrentWidget(dc);
    dc->activateWindow();
    dc->show();


}
void dashboard::pre_bill()
{
    pre_bill_generation *dc=new pre_bill_generation;
    ui->container->addWidget(dc);
    ui->container->setCurrentWidget(dc);
    dc->activateWindow();
    dc->show();
}
void dashboard::profit_loss_report()
{
    profit_loss *dc=new profit_loss;
    ui->container->addWidget(dc);
    ui->container->setCurrentWidget(dc);
    dc->activateWindow();
    dc->show();
}
void dashboard::evaluation_sheet()
{
  EvaluationSheet *dc=new EvaluationSheet;
    ui->container->addWidget(dc);
    ui->container->setCurrentWidget(dc);
    dc->activateWindow();
    dc->show();
}
void dashboard::evaluation_sheet_report()
{
   Evaluation_report *dc=new Evaluation_report;
      ui->container->addWidget(dc);
      ui->container->setCurrentWidget(dc);
      dc->activateWindow();
      dc->show();
}
void dashboard::attendance_report()
{
    student_attendance_report *dc=new student_attendance_report;
       ui->container->addWidget(dc);
       ui->container->setCurrentWidget(dc);
       dc->activateWindow();
       dc->show();
}

void dashboard::on_dashboard_iconSizeChanged(const QSize &iconSize)
{

}
void dashboard::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close Program",
                                                                tr("Are you sure you want to quit?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}
