#ifndef TEACHER_H
#define TEACHER_H

#include "Day.h"
#include <QString>
#include <QList>

class Teacher
{
public:
    Teacher();
    QList<Day>day;
    QString name;
    Teacher(QString n);
    Teacher(QString, QList<Day>);
};

#endif // TEACHER_H
