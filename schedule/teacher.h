#ifndef TEACHER_H
#define TEACHER_H

#include "Lesson.h"
#include "Day.h"

#include <QWidget>
#include <QString>
#include <QVector>


class Teacher : public QWidget
{
    Q_OBJECT

private:
    QString name;
    QVector<Lesson>les;
    QVector<Day>day;

public:
    Teacher(QWidget *parent = 0);
    //Teacher(QString n){this->name = n;}
    //Teacher(QVector<Lesson>l){this->les = l;}
    //Teacher(QVector<Day>d){this->day = d;}


};




#endif // TEACHER_H
