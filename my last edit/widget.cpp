#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wel = new QLabel("welcome to your program");
    this->resize(200,140);
    ok = new QPushButton("ok");
    vb = new QVBoxLayout(this);
    vb->addWidget(wel);
    vb->addWidget(ok);
    connect(ok,SIGNAL(clicked()),this,SLOT(open_spage()));
}

Widget::~Widget()
{
}

void Widget :: open_spage()
{
    this->s.show();
    this->close();
}
