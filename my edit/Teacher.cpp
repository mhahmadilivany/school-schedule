#include "Teacher.h"

Teacher :: Teacher(QWidget *parent)
               : QWidget(parent)
{   mainlayout = new QHBoxLayout;
    this->setLayout(mainlayout);
    g1=new QGroupBox;
    g2=new QGroupBox;
    vb6 = new QVBoxLayout();
    this->setWindowTitle("Teacher");
    this->resize(200,150);
    QPushButton *push = new QPushButton("معلم جدید");
    QVBoxLayout *vb = new QVBoxLayout();
    g1->setLayout(vb);
    mainlayout->addWidget(g1);
    vb->addWidget(push);
    connect(push,SIGNAL(clicked()),this,SLOT(Make_LineEdit()));
}


void Teacher :: Make_LineEdit()
{
    QLineEdit *line = new QLineEdit;
    vb6->addWidget(line);
    g2->setLayout(vb6);
    mainlayout->addWidget(g2);
}
