#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wel = new QLabel("به برنامه تنظیم برنامه هفتگی خودکار خوش آمدید!");
    this->resize(200,140);
    ok = new QPushButton("تعریف معلم ها");
    ok2=new QPushButton("تعریف دروس");
    kelas=new QPushButton("ایجاد کلاس");
    setemoallemodars=new QPushButton("هماهنگی معلمها و دروس");
    quit = new QPushButton("خروج");
    tanzim = new QPushButton("تنظیم برنامه هفتگی");
    vb = new QVBoxLayout(this);
    vb->addWidget(wel);
    vb->addWidget(ok);
    vb->addWidget(ok2);
    vb->addWidget(kelas);
    vb->addWidget(setemoallemodars);
    vb->addWidget(tanzim);
    vb->addWidget(quit);
    connect(ok,SIGNAL(clicked()),this,SLOT(open_spage()));
    connect(ok2,SIGNAL(clicked()),this,SLOT(open_jpage()));
    connect(kelas,SIGNAL(clicked()),this,SLOT(Kelas()));
    connect(setemoallemodars,SIGNAL(clicked()),this,SLOT(Setemoallemodars()));
    connect(quit,SIGNAL(clicked()),this,SLOT(Quit()));
}

Widget::~Widget()
{
}

void Widget :: open_spage()
{
    this->s.show();
}
void Widget :: open_jpage()
{
    this->j.show();
}
void Widget :: Quit()
{
    this->close();
}

void Widget :: Tanzim()
{
}

void Widget :: Kelas()
{
    QSqlQuery query;
    QList<QString>l;
    query.exec("select name,hour,kind from lessons;");
    while(query.next()){
         QString n = query.value(0).toString();
         int h = query.value(1).toInt();
         int k = query.value(2).toInt();
         bool ki = false;
         if(k == 1)ki = true;
         Lesson q(n,h,ki);
         //class_lessons.append(q);
         l.append(n);
    }
    for(int i =0;i<l.size();i++) c.lessoncombo->addItem(l[i]);
    this->c.show();
}
void Widget :: Setemoallemodars()
{
    QSqlQuery query;
    QList<QString>l;

    query.exec("select name,hour,kind from lessons;");
    while(query.next()){
        QString n = query.value(0).toString();
        int h = query.value(1).toInt();
        int k = query.value(2).toInt();
        bool ki = false;
        if(k == 1)ki = true;
        Lesson q(n,h,ki);
        //setinglistlesson.append(q);
            l.append(n);}
    for(int i =0;i<l.size();i++)
        Setting.lessonscombo->addItem(l[i]);
    QSqlQuery myquery;
    QList<QString>ll;
    myquery.exec("select name,hours from teachers;");
    while(myquery.next()){
        QString n = myquery.value(0).toString();
        int h = myquery.value(1).toInt();
        Teacher q(n);
        //settinglistteacher.append(q);
        ll.append(n);}
    for(int i =0;i<ll.size();i++)
        Setting.teacherscombo->addItem(ll[i]);
    this->Setting.show();
}
