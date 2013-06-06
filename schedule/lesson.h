#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QVector>

class Lesson
{
private:
    QString name;
    int hours;
public:
    Lesson(QString n){this->name = n;}
    Lesson(int h){this->hours = h;}
    Lesson(QString,int);

};


#endif // LESSON_H
