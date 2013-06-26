#include "School.h"
School :: School(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("School class");
    this->resize(300,200);
    mainlayout = new QHBoxLayout(this);
    gb1 = new QGroupBox;
    gb2 = new QGroupBox;
    vb = new QVBoxLayout;
    sh1 = new QCheckBox();
    sh2 = new QCheckBox();
    sh3 = new QCheckBox();
    sh4 = new QCheckBox();
    y1 = new QCheckBox();
    y2 = new QCheckBox();
    y3 = new QCheckBox();
    y4 = new QCheckBox();
    d1 = new QCheckBox();
    d2 = new QCheckBox();
    d3 = new QCheckBox();
    d4 = new QCheckBox();
    s1 = new QCheckBox();
    s2 = new QCheckBox();
    s3 = new QCheckBox();
    s4 = new QCheckBox();
    ch1 = new QCheckBox();
    ch2 = new QCheckBox();
    ch3 = new QCheckBox();
    ch4 = new QCheckBox();
    forteacherline0 = new QHBoxLayout;
    forteacherline1 = new QHBoxLayout;
    forteacherline2 = new QHBoxLayout;
    forteacherline3 = new QHBoxLayout;
    forteacherline4 = new QHBoxLayout;
    forteacherline5 = new QHBoxLayout;
    forteacherline6 = new QHBoxLayout;
    shanbe = new QLabel("شنبه:");
    yekshanbe = new QLabel("یکشنبه:");
    doshanbe = new QLabel("دوشنبه:");
    seshanbe = new QLabel("سه شنبه:");
    charshanbe = new QLabel("چهارشنبه:");
    zangs = new QLabel("                                                           زنگ اول                         زنگ دوم                         زنگ سوم                زنگ چهارم");
    name = new QLabel("نام دبیر: ");
    QPushButton *push1 = new QPushButton("معلم جدید");
    QPushButton *push2 = new QPushButton("بازگشت");
    QPushButton *push3 = new QPushButton("نمایش معلم های ذخیره شده");
    line = new QLineEdit;
    QVBoxLayout *vb2 = new QVBoxLayout;
    gb1->setLayout(vb2);

    forteacherline1->addWidget(line);
    forteacherline1->addWidget(name);
    forteacherline0->addWidget(zangs);
    forteacherline2->addWidget(sh1);
    forteacherline2->addWidget(sh2);
    forteacherline2->addWidget(sh3);
    forteacherline2->addWidget(sh4);
    forteacherline2->addWidget(shanbe);
    forteacherline3->addWidget(y1);
    forteacherline3->addWidget(y2);
    forteacherline3->addWidget(y3);
    forteacherline3->addWidget(y4);
    forteacherline3->addWidget(yekshanbe);
    forteacherline4->addWidget(d1);
    forteacherline4->addWidget(d2);
    forteacherline4->addWidget(d3);
    forteacherline4->addWidget(d4);
    forteacherline4->addWidget(doshanbe);
    forteacherline5->addWidget(s1);
    forteacherline5->addWidget(s2);
    forteacherline5->addWidget(s3);
    forteacherline5->addWidget(s4);
    forteacherline5->addWidget(seshanbe);
    forteacherline6->addWidget(ch1);
    forteacherline6->addWidget(ch2);
    forteacherline6->addWidget(ch3);
    forteacherline6->addWidget(ch4);
    forteacherline6->addWidget(charshanbe);
    vb->addLayout(forteacherline1);
    vb->addLayout(forteacherline0);
    vb->addLayout(forteacherline2);
    vb->addLayout(forteacherline3);
    vb->addLayout(forteacherline4);
    vb->addLayout(forteacherline5);
    vb->addLayout(forteacherline6);

    gb2->setLayout(vb);
    mainlayout->addWidget(gb2);
    mainlayout->addWidget(gb1);
    vb2->addWidget(push1);
    vb2->addWidget(push3);
    vb2->addWidget(push2);
    connect(push1,SIGNAL(clicked()),this,SLOT(Make_LineEdit()));  //new LineEdit will be made by clicking on the push1 button
    connect(push2,SIGNAL(clicked()),this,SLOT(Open_CPage()));   //the last LineEdit will be saved and next page will e open
    connect(push3,SIGNAL(clicked()),this,SLOT(Open_info()));
}

void School :: Make_LineEdit()
{
    if(line->text()==""){
        QMessageBox *message = new QMessageBox;
        message->warning(this,"اخطار","نام معلم را وارد نکرده اید");
    }
    else{
    Teacher t(line->text());
    Day Shanbeh;
    Day Yekshanbeh;
    Day Doshanbeh;
    Day Seshanbeh;
    Day Charshanbeh;
    t.day.append(Shanbeh);
    t.day.append(Yekshanbeh);
    t.day.append(Doshanbeh);
    t.day.append(Seshanbeh);
    t.day.append(Charshanbeh);
    t.day[0].z1=true;
    t.day[0].z2=true;
    t.day[0].z3=true;
    t.day[0].z4=true;
    t.day[1].z1=true;
    t.day[1].z2=true;
    t.day[1].z3=true;
    t.day[1].z4=true;
    t.day[2].z1=true;
    t.day[2].z2=true;
    t.day[2].z3=true;
    t.day[2].z4=true;
    t.day[3].z1=true;
    t.day[3].z2=true;
    t.day[3].z3=true;
    t.day[3].z4=true;
    t.day[4].z1=true;
    t.day[4].z2=true;
    t.day[4].z3=true;
    t.day[4].z4=true;
    this->list_of_teachers.append(t);
    if (sh1->isChecked()==true)
        t.day[0].z1=false;
    else if (sh2->isChecked()==true)
        t.day[0].z2=false;
    else if (sh3->isChecked()==true)
        t.day[0].z3=false;
    else if (sh4->isChecked()==true)
        t.day[0].z4=false;
    else if (y1->isChecked()==true)
        t.day[1].z1=false;
    else if (y2->isChecked()==true)
        t.day[1].z2=false;
    else if (y3->isChecked()==true)
        t.day[1].z3=false;
    else if (y4->isChecked()==true)
        t.day[1].z4=false;
    else if (d1->isChecked()==true)
        t.day[2].z1=false;
    else if (d2->isChecked()==true)
        t.day[2].z2=false;
    else if (d3->isChecked()==true)
        t.day[2].z3=false;
    else if (d4->isChecked()==true)
        t.day[2].z4=false;
    else if (s1->isChecked()==true)
        t.day[3].z1=false;
    else if (s2->isChecked()==true)
        t.day[3].z2=false;
    else if (s3->isChecked()==true)
        t.day[3].z3=false;
    else if (s4->isChecked()==true)
        t.day[3].z4=false;
    else if (ch1->isChecked()==true)
        t.day[4].z1=false;
    else if (ch2->isChecked()==true)
        t.day[4].z2=false;
    else if (ch3->isChecked()==true)
        t.day[4].z3=false;
    else if (ch4->isChecked()==true)
        t.day[4].z4=false;
    line->setText("");
    sh1->setChecked(false);
    sh2->setChecked(false);
    sh3->setChecked(false);
    sh4->setChecked(false);
    y1->setChecked(false);
    y2->setChecked(false);
    y3->setChecked(false);
    y4->setChecked(false);
    d1->setChecked(false);
    d2->setChecked(false);
    d3 ->setChecked(false);
    d4 ->setChecked(false);
    s1->setChecked(false);
    s2->setChecked(false);
    s3->setChecked(false);
    s4->setChecked(false);
    ch1->setChecked(false);
    ch2->setChecked(false);
    ch3->setChecked(false);
    ch4->setChecked(false);
    NameOfTeachers.append(t.name);
    NameOfTeachers.append("\n");
    list_of_teachers.append(t);
    }

}

void School :: Open_CPage()
{
    Teacher t(line->text());

    this->list_of_teachers.append(t);
    c.show();
    this->close();
}
void School :: Open_info()
{
    QMessageBox *msgbox = new QMessageBox;
    msgbox->setText(NameOfTeachers);
    msgbox->show();
}




