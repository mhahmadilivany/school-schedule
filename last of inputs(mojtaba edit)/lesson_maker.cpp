#include "lesson_maker.h"



lesson_maker :: lesson_maker(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("lesson maker");
    this->resize(300,200);
    mainlayout = new QHBoxLayout(this);
    foreachlessonv = new QVBoxLayout;
    foreachlessonh1 = new QHBoxLayout;
    foreachlessonh2 = new QHBoxLayout;
    foreachlessonh3 = new QHBoxLayout;
    nameoflesson = new QLabel("نام درس: ");
    line = new QLineEdit;
    foreachlessonh1->addWidget(line);
    foreachlessonh1->addWidget(nameoflesson);
    msgbox2 = new QMessageBox;

    kindoflesson = new QLabel("نوع درس: ");
    ekhorom = new QRadioButton("عمومی");
    ekhorom2 = new QRadioButton("اختصاصی");
    foreachlessonh2->addWidget(ekhorom);
    foreachlessonh2->addWidget(ekhorom2);
    foreachlessonh2->addWidget(kindoflesson);


    gb1 = new QGroupBox;
    gb2 = new QGroupBox;
    vb = new QVBoxLayout;

    push1 = new QPushButton("درس جدید");
    push2 = new QPushButton("بازگشت");
    push3= new QPushButton("دروس وارد شده");

    line2 = new QLineEdit;
    hoursofteachin = new QLabel("ساعت تدریس در هفته: ");
    foreachlessonh3->addWidget(line2);
    foreachlessonh3->addWidget(hoursofteachin);

    gforekhorom = new QGroupBox;
    hforekhorom = new QHBoxLayout;
    foreachlessonv->addLayout(foreachlessonh1);
    foreachlessonv->addLayout(foreachlessonh2);
    foreachlessonv->addLayout(foreachlessonh3);
    gforekhorom->setLayout(foreachlessonv);
    QVBoxLayout *vb2 = new QVBoxLayout;
    gb1->setLayout(vb2);

    vb->addWidget(gforekhorom);
    gb2->setLayout(vb);
    mainlayout->addWidget(gb2);
    mainlayout->addWidget(gb1);
    vb2->addWidget(push1);
    vb2->addWidget(push3);
    vb2->addWidget(push2);
    connect(push1,SIGNAL(clicked()),this,SLOT(New_Lesson()));
    connect(push2,SIGNAL(clicked()),this,SLOT(Go_Back()));
    connect(push3,SIGNAL(clicked()),this,SLOT(Open_infopage()));
}

void lesson_maker :: New_Lesson()
{
    if(line->text()=="" && line2->text()=="" && ekhorom->isChecked()==false && ekhorom2->isChecked()==false){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","هیچ ورودی ای یافت نشد");
    }
    else if(line->text()==""){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نام درس را وارد نکرده اید");
    }
    else if(ekhorom->isChecked()==false && ekhorom2->isChecked()==false && line2->text()==""){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نوع درس و ساعت تدریس در هفته را مشخص نکرده اید");
    }
    else if(ekhorom->isChecked()==false && ekhorom2->isChecked()==false){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نوع درس را مشخص نکرده اید");
    }
    else if(line2->text()==""){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","ساعت تدریس در هفته را وارد نکرده اید");
    }
    else if(line->text()=="" && line2->text()==""){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نام درس و ساعت تدریس را مشخص نکرده اید");
    }
    else if(line->text()=="" && ekhorom->isChecked()==false && ekhorom2->isChecked()==false){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نام و نوع درس را مشخص نکرده اید");
    }
    else{
    Lesson S(line->text(),line2->text().mid(0).toInt(),ekhorom2->isChecked()); // for special lessons it returns TRUE
    this->list_of_lessons.append(S);
    NameOfLessons.append(S.name);
    NameOfLessons.append("\n");
    ekhorom->setAutoExclusive(false);
    ekhorom2->setAutoExclusive(false);
    ekhorom->setChecked(false);
    ekhorom2->setChecked(false);
    ekhorom->setAutoExclusive(true);
    ekhorom2->setAutoExclusive(true);
    line->setText("");
    line2->setText("");
    }
}

void lesson_maker :: Go_Back()
{
    Lesson t(line->text());
    this->list_of_lessons.append(t);
    this->close();
}
void lesson_maker :: Open_infopage()
{
    msgbox2->setText(NameOfLessons);
    msgbox2->show();
}
lesson_maker::lesson_maker(QList<Lesson> t)
{
    list_of_lessons = t;
}

