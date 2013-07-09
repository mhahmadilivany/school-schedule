#include "classes.h"

Classes::Classes(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("make class");
    classmainlayout = new QHBoxLayout(this);
    classHB1 = new QHBoxLayout;
    classHB2 = new QHBoxLayout;
    classHB3 = new QHBoxLayout;
    classname = new QLabel("نام کلاس:");
    classnamelineedit = new QLineEdit;
    classVB1 = new QVBoxLayout;
    classVB2 = new QVBoxLayout;
    classVB3 = new QVBoxLayout;
    lessoncombo = new QComboBox;
    classHB1->addWidget(classnamelineedit);
    classHB1->addWidget(classname);
    classVB1->addLayout(classHB1);
    classVB1->addLayout(classHB2);
    back = new QPushButton("بازگشت");
    showinfo = new QPushButton("کلاسهای ذخیره شده");
    showinfolessons = new QPushButton("دروس ثبت شده");
    sabt = new QPushButton("ثبت کلاس");
    sabtedars = new QPushButton("ثبت درس");
    classmainlayout->addLayout(classVB1);
    classmainlayout->addLayout(classVB2);
    classVB2->addWidget(sabt);
    classVB2->addWidget(showinfo);
    classVB2->addWidget(showinfolessons);
    classVB2->addWidget(back);
    classHB2->addWidget(lessoncombo);
    classHB2->addWidget(sabtedars);
    connect(sabt,SIGNAL(clicked()),this,SLOT(sabtekelas()));
    connect(showinfo,SIGNAL(clicked()),this,SLOT(show_info()));
    connect(showinfolessons,SIGNAL(clicked()),this,SLOT(show_info_lessons()));
    connect(sabtedars,SIGNAL(clicked()),this,SLOT(sabte_dars()));
    connect(back,SIGNAL(clicked()),this,SLOT(close()));
}

void Classes::sabtekelas(){
        SchoolClass SC(classnamelineedit->text());
        showinfoforclass.append(SC.class_name);
        showinfoforclass.append("\n");
        classnamelineedit->setText("");
        x += 1;
        QSqlQuery query("CREATE TABLE class"+QString::number(x)+" (name text,hour int,kind int);",db2);
        QSqlQuery dquery;
        dquery.exec("select from lessons;");
        while(dquery.next()){
            QString n = dquery.value(0).toString();
            int h = dquery.value(1).toInt();
            int k = dquery.value(2).toInt();
            bool ki = false;
            if(k == 1)ki = true;
            Lesson q(n,h,ki);
            class_lessons.append(q);
        }
}

void Classes :: show_info()
{
    QMessageBox *classmsgbox = new QMessageBox;
    classmsgbox->setText(showinfoforclass);
    classmsgbox->show();
}

void Classes :: show_info_lessons()
{
    QList<QString>l;
    QSqlQuery query("select name from class"+QString::number(x));
    while(query.next()){
        QString v = query.value(0).toString();
        l.append(v);
    }
    QString s;
    for(int i=0;i<l.size();i++)s += l[i]+"\n";
    QMessageBox *classmsgbox = new QMessageBox;
    classmsgbox->setText(s);
    classmsgbox->show();
}

void Classes :: sabte_dars()
{
    QString c;
    c = lessoncombo->currentText();
    QSqlQuery myquery;
    myquery.exec("SELECT hour,kind FROM lessons WHERE name='"+c+"'");
    int h = myquery.value(0).toInt();
    QString sh = myquery.value(0).toString();
    QString k = myquery.value(1).toString();
    QSqlQuery newquery;
    newquery.exec("insert into class"+QString::number(x)+" values('"+c+"','"+sh+"','"+k+"');");
}
