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
    this->c.show();
}
void Widget :: Setemoallemodars()
{
}
