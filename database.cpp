#include "database.h"
#include "QMessageBox"
#include "QSqlDatabase"
#include <QtGui>
#include <QByteArray>
#include "QSqlQuery"
#include "QSqlTableModel"
#include "QDebug"
#include "QSqlError"
#include "addtoddlers.h"
#include "QString"
#include <QtWidgets>

//#include "add_user.h"
//Add_user *usr= new Add_user;

QStringList dt;
QStringList n;
database::database()
{



}
int database::login_check(QString uname,QString password)
{
    QSqlQuery query;
   query.exec("select username,password,status from login where username='"+uname+"'and password='"+password+"' and status='active'");
   int rows=query.size();
    if(rows<1)
    {
        return false;
    }
    return true;
}


int database::db_connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
      db.setHostName("127.0.0.1");
      db.setDatabaseName("toddlers");
      db.setUserName("root");
         bool ok = db.open();
         if(!ok)
         {
                        db.close();
                        return false;
         }
         return true;
}
void database::show_user()
{



}
int database::insert(QString firstname,QString lastname,QString username,QString password,QString status)
{
    QSqlQuery query;
    query.prepare("INSERT INTO login (firstname, lastname,username,password,status) "
                    "VALUES (:firstname, :lastname,:username,:password,:status)");
      query.bindValue(":firstname", firstname);
      query.bindValue(":lastname", lastname);
      query.bindValue(":username", username);
      query.bindValue(":password",password);
      query.bindValue(":status",status);
     bool ok= query.exec();
     if(ok)
     {
         return true;
     }
     else
     {
        // QMessageBox::warning(this,"Error","Insertion Failed",QMessageBox::Ok);
         return 0;
     }
     return true;
}
int database::add_class(QString name,QString student)
{
    QSqlQuery query;
    query.prepare("INSERT INTO class (classname,no_student)" "VALUES(:classname,:nostudent)");
    query.bindValue(":classname",name);
    query.bindValue(":no_student",student);
    bool ok=query.exec();
    if(ok)
    {
        return true;
    }
    //qDebug()<<query.lastError();
    return false;
}
int database::toddlers_add(QString admsn,QString roll,QString firstname,QString middlename,QString lastname,QString dob,QString nepaliname,QString nepalidob,QString nationality,QString caste,QString birthplace,QString religion,QString std_language,QString language,QString father_name,QString father_addresses,QString father_local_addresses,
                           QString father_living,QString father_birthplace,QString father_mobile,QString father_occupation,QString mother_name,QString mother_birthplace,QString mother_address,QString mother_local_address,QString mother_living,
                           QString mother_language, QString mother_mobile,QString mother_occupation,QString home_ph1,QString home_phn2,QString email,QString emergency_contact,QString guardian_name,QString guardian_contact,QString guard_occu,QString guardian_address,QString guardian_relation,QString details,QString academic_details)
{
    QSqlQuery query;
    query.prepare("INSERT INTO student(admission_num, roll_no, firstname, middlename, lastname, dob, nep_name, nep_dob, nationality, caste, birthplace, religion, language, fath_name, fath_birth, fath_living, fath_lang, fath_add, fath_local_add, mother_name, Birthplace_moth, moth_lang, moth_living, moth_add, moth_local_add, contact_home, contact_home1, contact_home2, father_mobile, mother_mobile, Emergency_contact, fath_occupation, moth_occupation,guardian_name, guardian_rel, guardian_cont, guardian_occupation, student_details, class)"
                              "VALUES (:admission,:roll,:firstname,:middlename,:lastname,:dob,:nepaliname,:nepalidob,:nationality,:caste,:birthplace,:religion,:language,:father_name,:father_birthplace,:father_living,:father_language,:father_address,:father_local_address,:mother_name,:mother_birthplace,:mother_language,:mother_living,:mother_address,:mother_local_address,:home_ph1,:home_phn2,:father_mobile,:mother_mobile,:emergency_contact,:father_occupation,:mother_occupation,:guardian_name,:guardian_relation,:guardian_contact,:guardian_occu,:guardian_address,:detls,:academic_details)");
    query.bindValue(":admission",admsn);
    query.bindValue(":roll",roll);
    query.bindValue(":firstname",firstname);
    query.bindValue(":middlename",middlename);
    query.bindValue(":lastname",lastname);
    query.bindValue(":dob",dob);
    query.bindValue(":nepaliname",nepaliname);
    query.bindValue(":nepalidob",nepalidob);
    query.bindValue(":nationality",nationality);
    query.bindValue(":caste",caste);
    query.bindValue(":birthplace",birthplace);
    query.bindValue(":religion",religion);
    query.bindValue(":mother_language",mother_language);
    query.bindValue(":language",std_language);
    query.bindValue(":father_name",father_name);
    query.bindValue(":father_address",father_addresses);
    query.bindValue(":father_living",father_living);
    query.bindValue(":father_language",language);
    query.bindValue(":father_birthplace",father_birthplace);
    query.bindValue(":father_local_address",father_local_addresses);
    query.bindValue(":father_mobile",father_mobile);
    query.bindValue(":father_occupation",father_occupation);
    query.bindValue(":mother_name",mother_name);
    query.bindValue(":mother_birthplace",mother_birthplace);
    query.bindValue(":mother_occupation",mother_occupation);
    query.bindValue(":mother_address",mother_address);
    query.bindValue(":mother_local_address",mother_local_address);
    query.bindValue(":mother_living",mother_living);
    query.bindValue(":mother_mobile",mother_mobile);
    query.bindValue(":mother_occupation",mother_occupation);
    query.bindValue(":home_ph1",home_ph1);
    query.bindValue(":home_phn2",home_phn2);
    query.bindValue(":email",email);
    query.bindValue(":emergency_contact",emergency_contact);
    query.bindValue(":guardian_name",guardian_name);
    query.bindValue(":guardian_contact",guardian_contact);
    query.bindValue(":guardian_occu",guard_occu);
    query.bindValue(":guardian_address",guardian_address);
    query.bindValue(":guardian_relation",guardian_relation);
    query.bindValue(":detls",details);
    query.bindValue(":academic_details",academic_details);
//    query.bindValue(":middlename",middlename);
//    query.bindValue(":middlename",middlename);
    bool ok=query.exec();
    if(ok)
    {
        return true;
    }
    qDebug()<<query.lastError();
return false;

}
QStringList database::studentlist(QString cls)
{
    QSqlQuery query;
    query.exec("SELECT CONCAT( firstname,  ' ', middlename,  ' ', lastname ) FROM student where class='"+cls+"' and status='active'");
    QStringList studentlst;
    while(query.next())
    {
        studentlst<<query.value(0).toString();
    }
    return studentlst;

}
QStringList database::classlist()
{
QSqlQuery query;
QStringList country;
int i=0;
query.exec("select classname from class");
while (query.next()) {
        country<< query.value(0).toString();
// country = query.value(1).toStringList();
        i=i+1;
}
return country;
}
int database::insert_staff(QString dte,QString firstname,QString middlename,QString lname,QString nationality,QString religion,QString gender,QString relation,QString dob,QString bloodgroup,QString street,QString street1,QString city,QString state,QString pincode,QString mobile,QString mobile2,QString email,QString academic_current_education
                           ,QString academic_current_level,QString postion,QString assigned,QString remarks,QString salary,QString pf,QString bank_ac,QString bank_name,QString country)
{
QSqlQuery query;
query.prepare("INSERT INTO staff (`DATE`, `Firstname`, `Middlename`, `Lastname`, `Address1`, `Address2`, `City`, `Nationality`, `DOB`, `Gender`, `State`, `Pincode`, `Country`, `BloodGroup`, `Maritial Status`, `Religion`, `Phone`, `Phone1`, `Email`, `Education`, `Current`, `Position`, `Assigned_class`, `Remarks`, `Salary`, `PF`, `Bank`, `Bank_name`)"
              "VALUES (:dt,:fname,:mname,:lname,:add,:add1,:cty,:nation,:dob,:gndr,:st,:pncode,:cntry,:bg,:mst,:relgn,:ph,:ph1,:eml,:edu,:curredu,:pos,:assigned,:rmkrs,:sal,:pf,:bank,:bankname)");
query.bindValue(":dt",dte);
query.bindValue(":fname",firstname);
query.bindValue(":mname",middlename);
query.bindValue(":lname",lname);
query.bindValue(":add",street);
query.bindValue(":add1",street1);
query.bindValue(":cty",city);
query.bindValue(":nation",nationality);
query.bindValue(":dob",dob);
query.bindValue(":gndr",gender);
query.bindValue(":st",state);
query.bindValue(":pncode",pincode);
query.bindValue(":cntry",country);
query.bindValue(":bg",bloodgroup);
query.bindValue(":mst",relation);
query.bindValue(":relgn",religion);
query.bindValue(":ph",mobile);
query.bindValue(":ph1",mobile2);
query.bindValue(":eml",email);
query.bindValue(":edu",academic_current_education);
query.bindValue(":curredu",academic_current_level);
query.bindValue(":pos",postion);
query.bindValue(":assigned",assigned);
query.bindValue(":rmkrs",remarks);
query.bindValue(":sal",salary);
query.bindValue(":pf",pf);
query.bindValue(":bank",bank_ac);
query.bindValue(":bankname",bank_name);
bool ok=query.exec();
if(ok)
{
    return true;
}
else
{
    qDebug()<<query.lastError().text();
    return false;
}
}
int database::insert_Vendor(QString vendorname,QString vendordesc,QString vendorphone)
{
QSqlQuery Query;
Query.prepare("INSERT INTO  vendor (vendor_name , vendor_desc ,phone) VALUES ( :vendorname,  :vendordesc,  :vendorphone)");
Query.bindValue(":vendorname",vendorname);
Query.bindValue(":vendordesc",vendordesc);
Query.bindValue(":vendorphone",vendorphone);
bool ok=Query.exec();
if(ok)
{
    return true;
}
qDebug()<<Query.lastError();
return false;
}
QStringList database::vendor_list()
{
    QSqlQuery query;
    query.exec("SELECT vendor_name from vendor");
    QStringList studentlst;
    while(query.next())
    {
        studentlst<<query.value(0).toString();
    }
    return studentlst;

}
int database::insert_product(QString product,QString desc)
{
QSqlQuery qr;
qr.prepare("INSERT INTO  product (product_name ,product_desc )" " VALUES (:productname,  :product_desc)");
qr.bindValue(":productname",product);
qr.bindValue(":product_desc",desc);
bool ok=qr.exec();
if(ok)
{
    return true;
}
return false;
}
QStringList database::product_list()
{
    QSqlQuery query;
    query.exec("select Product from stock_add");
    QStringList productlist;
    while(query.next())
    {
        productlist<<query.value(0).toString();
    }
    return productlist;


}
int database::insert_stock(QString date, QString vendor, QString product, QString unit, QString qt, QString amt, QString paid, QString bal, QString chck)
{
QSqlQuery qr;
qr.prepare("INSERT INTO stock_add (Date, Product, Vendor, Qty, unitprice, Amount, paid, Balance, check_no)" "VALUES (:da,:prd,:ven,:qt,:unit,:amt,:pad,:bal,:chk)");
qr.bindValue(":da",date);
qr.bindValue(":prd",product);
qr.bindValue(":ven",vendor);
qr.bindValue(":qt",qt);
qr.bindValue(":unit",unit);
qr.bindValue(":amt",amt);
qr.bindValue(":pad",paid);
qr.bindValue(":bal",bal);
qr.bindValue(":chk",chck);
bool ok=qr.exec();
if(ok)
{
    return true;
}
qDebug()<<qr.lastError();
return false;
}
int database::fee_crtn(QString feename,QString feeclass,QString price,QString descrip)
{
    QSqlQuery qr;
    qr.prepare("INSERT INTO Fee_creation (Fee_name,class, fee_amount, fee_description)" "VALUES (:finame,:fclass,:f_price,:f_desc)");
    qr.bindValue(":finame",feename);
    qr.bindValue(":fclass",feeclass);
    qr.bindValue(":f_price",price);
    qr.bindValue(":f_desc",descrip);
    bool ok=qr.exec();
    if(ok)
    {
        return true;
    }
    return false;
}
int database::discount(QString disname, QString disprice, QString discrip)
{
    QSqlQuery qr;
    qr.prepare("INSERT INTO toddlers.discount (discount_name, discount_amount, discount_description)" "VALUES (:name,:price,:desc);");
    qr.bindValue(":name",disname);
    qr.bindValue(":price",disprice);
    qr.bindValue(":desc",discrip);
    bool ok=qr.exec();
    if(ok)
    {
        return true;
    }
    return false;
}
int database::expenseheading(QString name,QString desc)
{
QSqlQuery qrr;
qrr.prepare("INSERT INTO  `toddlers`.`expenses_creation` (expense_name)" "VALUES (:name);");
qrr.bindValue(":name",name);
bool ok=qrr.exec();
if(ok)
{
    return true;
}
return false;
}
QStringList database::expenselist()
{
    QSqlQuery query;
    query.exec("SELECT expense_name from expenses_creation");
    QStringList expenlst;
    while(query.next())
    {
        expenlst<<query.value(0).toString();
    }
    return expenlst;
}
int database::expense_add(QDate dt,QString heading,QString amount)
{
    QSqlQuery qr;
    qr.prepare("INSERT INTO  expense (date ,expense_Heading ,Amount)" " VALUES (:d,:h,:a )");
    qr.bindValue(":d",dt);
    qr.bindValue(":h",heading);
    qr.bindValue(":a",amount);
    bool ok=qr.exec();
    if(ok)
    {
        return true;
    }
   return false;
}
QStringList database::stafflist()
{
    QSqlQuery query;
    query.exec("SELECT CONCAT( Firstname,' ', Lastname ) FROM staff");
    QStringList stafflst;
    while(query.next())
    {
        stafflst<<query.value(0).toString();
    }
    return stafflst;
}
void database::take_attendance(QString dte, QString name, QString status, QString remarks)
{
    QSqlQuery query("SELECT DATE, Student_name  FROM  `student_attendance`");
     while(query.next())
    {
         dt<<query.value(0).toStringList();
       n<<query.value(1).toStringList();
    }

if(query.size()==0)
{
    QSqlQuery dad;
    dad.prepare("INSERT INTO student_attendance (Date, Student_name, status, remarks)" "VALUES (:dat,:nam,:stat,:rema)");
    dad.bindValue(":dat",dte);
    dad.bindValue(":nam",name);
    dad.bindValue(":stat",status);
    dad.bindValue(":rema",remarks);
    dad.exec();
}
else
{      for(int j=0;j<dt.size();j++)
       {
           QString dat=dt.at(j).toLocal8Bit().constData();
           QString stuname=n.at(j).toLocal8Bit().constData();
           if(dat==dte && name==stuname)
           {
//prevent from duplicate data entering
           }
           else
           {
               QSqlQuery dad;
               dad.prepare("INSERT INTO student_attendance (Date, Student_name, status, remarks)" "VALUES (:dat,:nam,:stat,:rema)");
               dad.bindValue(":dat",dte);
               dad.bindValue(":nam",name);
               dad.bindValue(":stat",status);
               dad.bindValue(":rema",remarks);
               dad.exec();
            break;
           }
       }
}
 }
void database::fee_submission(QString date,QString month,QString studentname,QString cla,QString parti,QString amt,QString paid,QString balance)
{
QSqlQuery query;
query.prepare("INSERT INTO `toddlers`.`fee_submission` (`Date`, `Month`, `Class`, `student_name`, `Particulars`, `Amount`, `Paid`, `Balance`)" "VALUES (:d,:m,:c,:st,:part,:amt,:paid,:bal)");
query.bindValue(":d",date);
query.bindValue(":m",month);
query.bindValue(":st",studentname);
query.bindValue(":c",cla);
query.bindValue(":part",parti);
query.bindValue(":amt",amt);
query.bindValue(":paid",paid);
query.bindValue(":bal",balance);
bool ok=query.exec();
if(ok)
{
    return;
}
else
{
   // QMessageBox::information(this,"ERROR","ERROR",QMessageBox::Ok);
    qDebug()<<query.lastError().text();
}
}
void database::delete_student(QString id)
{
QSqlQuery query;
query.exec("Update student set status='inactive' where app_id='"+id+"'");
if(query.exec())
{
    qDebug()<<query.lastError().text();
}
}



int database::staff_attendance(QString dte,QString name,QString status,QString remarks)
{

    QSqlQuery query("SELECT Date, staff_name  FROM  staff_attendance");
   if(query.size()==0)
{
    QSqlQuery dad;
    dad.prepare("INSERT INTO staff_attendance (Date, staff_name, Status, remarks)" "VALUES (:dat,:nam,:stat,:rema)");
    dad.bindValue(":dat",dte);
    dad.bindValue(":nam",name);
    dad.bindValue(":stat",status);
    dad.bindValue(":rema",remarks);
    dad.exec();
    qDebug()<<dad.lastError().text();
}

else
   {



               QSqlQuery dad,m;
               m.exec("select Date,staff_name from staff_attendance where staff_name='"+name+"' and Date='"+dte+"'");
               int s=m.size();
               if(s>=1)
               {
                   return -1;
               }

          else
               {

               dad.prepare("INSERT INTO staff_attendance (Date, staff_name, Status, remarks)" "VALUES (:dat,:nam,:stat,:rema)");
               dad.bindValue(":dat",dte);
               dad.bindValue(":nam",name);
               dad.bindValue(":stat",status);
               dad.bindValue(":rema",remarks);
               dad.exec();
               qDebug()<<dad.lastError().text();
               return true;
               }

   }


}
QString database::staff_salary_amount(QString name){
    QSqlQuery query;
     QString feeamount;
    query.exec("SELECT Salary  FROM staff WHERE (SELECT CONCAT( Firstname,  ' ', Lastname )) =  '"+name+"'");
    while(query.next())
    {
       feeamount=query.value(0).toString();

    }
     return feeamount;

}
int database::insert_salary(QString dt,QString stfname,QString adv,QString pad,QString mth,QString pyble,QString balamt)
{
    QSqlQuery query;
    query.prepare("INSERT INTO salary (`Date`, `Staff_name`, `Advance`, `salary_paid`, `Month`, `Payable`, `Balance`) VALUES (:dat,:stname,:adv,:salpaid,:mth,:pay,:bal);");
    query.bindValue(":dat",dt);
    query.bindValue(":stname",stfname);
    query.bindValue(":adv",adv);
    query.bindValue(":salpaid",pad);
    query.bindValue(":mth",mth);
    query.bindValue(":pay",pyble);
    query.bindValue(":bal",balamt);
    bool ok=query.exec();
    if(ok)
    {
        return true;
    }

      qDebug()<<query.lastError().text();

return false;
}
QStringList database::student_list()
{
    QStringList stname;
    QSqlQuery m("select concat(firstname,' ',lastname) from student");
    while(m.next())
    {
        stname<<m.value(0).toString();
    }
    return stname;
}
int database::insert_sales(QString d,QString stname,QString prod,QString Qty,QString total,QString amt,QString balnce)
{
    QSqlQuery query,Q;
    query.prepare("INSERT INTO `stock_sales` (Date, student_name, product, Qty, Total, Amount, Balance) ""VALUES (:dat, :st,:prod, :qt,:total, :paid, :bal)");
    query.bindValue(":dat",d);
    query.bindValue(":st",stname);
    query.bindValue(":prod",prod);
    query.bindValue(":qt",Qty);
    query.bindValue(":total",total);
    query.bindValue(":paid",amt);
    query.bindValue(":bal",balnce);
    bool ok=query.exec();
    if(ok)
    {
Q.exec("update stock set Qty=Qty-'"+Qty+"' where product='"+prod+"'");
return true;
    }
    else
    {
        qDebug()<<query.lastError().text();
        return false;
    }
}
int database::event_cr(QString dt, QString ti, QString ev)
{
QSqlQuery qr;
qr.prepare("INSERT INTO `toddlers`.`events` (`date`, `time`, `events`)" "VALUES (:dt,:t,:e)");
qr.bindValue(":dt",dt);
qr.bindValue(":t",ti);
qr.bindValue(":e",ev);
bool ok=qr.exec();
if(ok)
{
    return true;
}
else
{
    qDebug()<<qr.lastError().text();
    return false;
}
}
void database::db_close()
{

}
int database::insert_xtra_fee(QString fee, QString amt)
{
    QSqlQuery mo;
    mo.prepare("INSERT INTO `toddlers`.`extrafee` (`Particulars`, `Amount`)" "VALUES (:fee,:amt);");
    mo.bindValue(":fee",fee);
    mo.bindValue(":amt",amt);
    bool ok=mo.exec();
    if(ok)
    {
        return true;
    }
    else
    {
        return false;
    }
}
QStringList  database::xtrafe()
{
    QStringList fe;
QSqlQuery m("select Particulars from extrafee");
while(m.next())
{
    fe<<m.value(0).toString();
}
return fe;
}

int database::fee_assigned(QString stdname, QString cl, QString feeheading,QString amt)
{
    QSqlQuery mo;
    mo.prepare("INSERT INTO fee_assigned (student_name,class,fee_heading,Amount)" "VALUES (:student_name,:class,:fee_heading,:Amount);");
    mo.bindValue(":student_name",stdname);
    mo.bindValue(":class",cl);
    mo.bindValue(":fee_heading",feeheading);
    mo.bindValue(":Amount",amt);
    bool ok=mo.exec();
    if(ok)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int database::pre_bill_insert(QString month,QString cl)
{
    QSqlQuery mo,qr;
    qr.exec("select * from fee_assigned where class='"+cl+"'");
    while(qr.next())
    {
        mo.prepare("INSERT INTO prebill (name, month, class, particulars, amount)" "VALUES (:student_name,:month,:class,:fee_heading,:Amount);");
        mo.bindValue(":student_name",qr.value(1).toString());
        mo.bindValue(":month",month);
        mo.bindValue(":class",cl);
        mo.bindValue(":fee_heading",qr.value(3).toString());
        mo.bindValue(":Amount",qr.value(4).toString());
        mo.exec();
        qDebug()<<mo.lastError().text();

    }
    return true;
}
int database::update_student(QString id, QString adm, QString roll, QString fname, QString mname, QString lname, QString da, QString nepaliname, QString nationality, QString caste, QString birth, QString rlgn, QString lnguage, QString faname, QString fabirth, QString falang, QString faadd, QString localfaadd,
QString mother, QString motherbrth, QString mlang, QString madd, QString mlocal, QString ph1, QString homph2, QString famobile, QString mothermobile, QString emergency, QString faoccup, QString mooccu, QString guardname, QString guardrelation, QString contactguard, QString guradoccu, QString details, QString cl)
{
QSqlQuery query;
bool ok=query.exec("UPDATE student SET admission_num = '"+adm+"', roll_no = '"+roll+"', firstname = '"+fname+"', middlename = '"+mname+"', lastname = '"+lname+"', dob = '"+da+"', nep_name = '"+nepaliname+"', nep_dob = '"+birth+"', nationality = '"+nationality+"', caste = '"+caste+"', birthplace = '"+birth+"', religion = '"+rlgn+"', language = '"+lnguage+"', fath_name = '"+faname+"', fath_birth = '"+fabirth+"', fath_living = '1', fath_lang = '"+falang+"', fath_add = '"+faadd+"', fath_local_add = '"+localfaadd+"',mother_name = '"+mother+"',Birthplace_moth = '"+motherbrth+"', moth_lang = '"+mlang+"', moth_living = '1', moth_add = '"+madd+"', moth_local_add = '"+mlocal+"', contact_home = '"+ph1+"', contact_home1 = '"+homph2+"', contact_home2 = '"+famobile+"', father_mobile = '"+famobile+"', mother_mobile = '"+mothermobile+"', Emergency_contact = '"+emergency+"', fath_occupation = '"+faoccup+"', moth_occupation = '"+mooccu+"', guardian_name = '"+guardname+"', guardian_rel = '"+guardrelation+"', guardian_cont = '"+contactguard+"', guardian_occupation = '"+guradoccu+"', student_details = '"+details+"', class = '"+cl+"', fiance = 'ssdfsdf' WHERE student.app_id = '"+id+"'; ");
      if(ok)
{
    return true;
}
qDebug()<<query.lastError().text();
return false;
}
QStringList database::subjectlist()
{
    QStringList list;
    QSqlQuery qr("select subject_name FROM subject");
    while(qr.next())
    {
        list<<qr.value(0).toString();
    }
    return list;
}
int database::firstterm(QString marks, QString total, QString band, QString name, QString subject)
{
QSqlQuery qr;
qr.prepare("INSERT INTO FirstTerm (First_Mid_Term, Student_id, Subject_id, Total, Band)" " VALUES (:marks,:name,:sub,:t,:bnd);");
qr.bindValue(":marks",marks);
qr.bindValue(":name",name);
qr.bindValue(":sub",subject);
qr.bindValue(":t",total);
qr.bindValue(":bnd",band);
qr.exec();
return true;
}
int database::secondterm(QString marks, QString total, QString band, QString name, QString subject)
{
    QSqlQuery qr;
    qr.prepare("INSERT INTO SecondTerm (Student_id, Subject_id, Second_Mid_Term,Total, Band)" " VALUES (:name,:sub,:marks,:t,:bnd);");
    qr.bindValue(":name",name);
    qr.bindValue(":sub",subject);
     qr.bindValue(":marks",marks);
    qr.bindValue(":t",total);
    qr.bindValue(":bnd",band);
    qr.exec();
    return true;
}
int database::finalterm(QString marks, QString total, QString band, QString name, QString subject)
{
    QSqlQuery qr;
    qr.prepare("INSERT INTO ThirdTerm (Student_id, Subject_id, Final_Mid_Term, Total, Band) " " VALUES (:name,:sub,:marks,:t,:bnd);");
       qr.bindValue(":name",name);
    qr.bindValue(":sub",subject);
     qr.bindValue(":marks",marks);
    qr.bindValue(":t",total);
    qr.bindValue(":bnd",band);
    qr.exec();
    return true;
}

int database::firstmidterm(QString marks, QString total, QString name, QString subject)
{
    QSqlQuery qr;
    qr.prepare("UPDATE  `FirstTerm` SET  `FirstTerm` =  '"+marks+"', where Student_id='"+total+"' and Subject_id='"+name+"'");
qr.exec();
    return true;
}
int database::secondmidterm(QString marks, QString total, QString name, QString subject)
{
    QSqlQuery qr;
    qr.prepare("UPDATE  `SecondTerm` SET  `SecondTerm` =  '"+marks+"', where Student_id='"+total+"' and Subject_id='"+name+"'");
qr.exec();
    return true;
}
int database::finalmidterm(QString marks, QString total, QString name, QString subject)
{
    QSqlQuery qr;
    qr.prepare("UPDATE  `ThirdTerm` SET  `Final_Term` =  '"+marks+"', where Student_id='"+total+"' and Subject_id='"+name+"'");
qr.exec();
    return true;
}
