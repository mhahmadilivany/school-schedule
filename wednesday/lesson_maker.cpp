#include "lesson_maker.h"
#include <QVector>
#include "Lesson.h"
#include <QList>
#include "Class.h"
#include <QDebug>
#include <widget.h>
#include <QScrollArea>

lesson_maker :: lesson_maker(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("lesson maker");
    this->resize(300,200);
    mainlayout = new QHBoxLayout(this);
    gb1 = new QGroupBox;
    gb2 = new QGroupBox;
    vb = new QVBoxLayout;
    QPushButton *push1 = new QPushButton("درس جدید");
    QPushButton *push2 = new QPushButton("بازگشت");
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

void lesson_maker :: Make_LineEdit()
{
    Lesson t(line->text());
    this->list_of_lessons.append(t);
    line = new QLineEdit;
    vb->addWidget(line);
}

void lesson_maker :: Open_CPage()
{
    Lesson t(line->text());
    this->list_of_lessons.append(t);

    this->close();
}



