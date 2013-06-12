#include "School.h"
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wel = new QLabel("به برنامه خودتان خوش آمدید!");
    this->resize(200,140);
    ok = new QPushButton("تعریف معلم ها");
    ok2=new QPushButton("تعریف دروس");
    vb = new QVBoxLayout(this);
    vb->addWidget(wel);
    vb->addWidget(ok);
    vb->addWidget(ok2);
    connect(ok,SIGNAL(clicked()),this,SLOT(open_spage()));
    connect(ok2,SIGNAL(clicked()),this,SLOT(open_jpage()));
}

Widget::~Widget()
{
}

void Widget :: open_spage()
{
    this->s.show();
    this->close();
}
void Widget :: open_jpage()
{
    this->j.show();
    this->close();
}
