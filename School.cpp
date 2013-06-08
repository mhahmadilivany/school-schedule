#include "School.h"
#include <QVector>
#include <QDebug>

School :: School(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("School class");
    this->resize(300,200);
    mainlayout = new QHBoxLayout(this);
    gb1 = new QGroupBox;
    gb2 = new QGroupBox;
    vb = new QVBoxLayout;
    QPushButton *push1 = new QPushButton("معلم جدید");
    QPushButton *push2 = new QPushButton("صفحه بعد");
    line = new QLineEdit;
    QVBoxLayout *vb2 = new QVBoxLayout;
    gb1->setLayout(vb2);
    vb->addWidget(line);
    gb2->setLayout(vb);
    mainlayout->addWidget(gb2);
    mainlayout->addWidget(gb1);
    vb2->addWidget(push1);
    vb2->addWidget(push2);
    connect(push1,SIGNAL(clicked()),this,SLOT(Make_LineEdit()));  //new LineEdit will be made by clicking on the push1 button
    connect(push2,SIGNAL(clicked()),this,SLOT(Open_CPage()));   //the last LineEdit will be saved and next page will e open
}

void School :: Make_LineEdit()
{
    Teacher t(line->text());
    this->teachers.push_back(t);
    line = new QLineEdit;
    vb->addWidget(line);
}

void School :: Open_CPage()
{
    Teacher t(line->text());
    this->teachers.push_back(t);
    c.show();
    this->close();
}



