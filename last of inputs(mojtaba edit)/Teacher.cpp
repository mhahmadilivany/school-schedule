#include "Teacher.h"

Teacher :: Teacher(QString n)
{
    name = n;
}
Teacher :: Teacher(QList<Day> d)
{
    //for(int i=0;i<d.length();i++)
      //  this->day[i]=d[i];


}
Teacher :: Teacher(QList<Lesson> l)
{
   // for(int j=0;j<l.length();j++)
    //    this->les[j]=l[j];
}

Teacher :: Teacher(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("انتخاب درس معلم ها");
    this->resize(400,500);
    combo = new QComboBox;
    for(int i=0;i<list_of_lessons.size();i++){
        combo->addItem(list_of_lessons[i].name);
    }
    combo2 = new QComboBox;
    for(int i=0;i<list_of_teachers.size();i++){
        combo2->addItem(list_of_teachers[i].name);
    }
    QPushButton *push = new QPushButton("تایید");
    QHBoxLayout *hb = new QHBoxLayout;
    hb->addWidget(combo);
    hb->addWidget(combo2);
    hb->addWidget(push);
    QGroupBox *group = new QGroupBox(this);
    group->setLayout(hb);
    connect(push,SIGNAL(clicked()),this,SLOT(setLesson()));
}

void Teacher :: setLesson()
{
    list_of_teachers[list_of_teachers.indexOf(combo->currentText())].l.append(list_of_lessons[list_of_lessons.indexOf(combo->currentText())]);  //dars ro ba moallem set mikone be torike hardo ro az liste khodeshun dar miare ke moshakhasateshun bahashun bian

}








