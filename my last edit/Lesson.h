#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QVector>

class Lesson
{
private:
    QString name;
    int hours;
    bool kind;
public:
    Lesson(QString n){this->name = n;}
    Lesson(int h){this->hours = h;}
    Lesson(bool k){this->kind = k;}
    Lesson(QString,int,bool);

};


#endif // LESSON_H
