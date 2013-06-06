#include "Teacher.h"

Teacher :: Teacher(QWidget *parent)
               : QWidget(parent)
{
    this->setWindowTitle("Teacher");
    this->resize(200,150);
    QPushButton *push = new QPushButton("معلم جدید");
    QVBoxLayout *vb = new QVBoxLayout(this);
    vb->addWidget(push);
    connect(push,SIGNAL(clicked()),this,SLOT(Make_LineEdit()));
}


void Teacher :: Make_LineEdit()
{
    QLineEdit *line = new QLineEdit;
    QVBoxLayout *vb = new QVBoxLayout(this);
    vb->addWidget(line);
}
