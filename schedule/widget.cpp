#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wel = new QLabel("welcome to your program");
    ok = new QPushButton("ok");
    vb = new QVBoxLayout(this);
    vb->addWidget(wel);
    vb->addWidget(ok);
    connect(ok,SIGNAL(clicked()),this,SLOT(open_tpage()));
}

Widget::~Widget()
{
}

void Widget :: open_tpage()
{
    this->t.show();
    this->close();
}
