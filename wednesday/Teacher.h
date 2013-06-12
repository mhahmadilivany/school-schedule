#ifndef TEACHER_H
#define TEACHER_H

#include "Lesson.h"
#include "Day.h"
#include "lesson_maker.h"
#include <QWidget>
#include <QString>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>


class Teacher     //public QWidget
{
    //Q_OBJECT

private:

    QVector <Lesson> les;
    QVector<Day>day;

public:
    //Teacher();
    QString name;
    Teacher(QWidget *parent = 0);
    Teacher(QString n);//{this->name = n;}
    Teacher(QList <Lesson> l);//{this->les = l;}
    Teacher(QList <Day> d);//{this->day = d;}

};




#endif // TEACHER_H
