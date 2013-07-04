#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include <QString>
#include "Lesson.h"
#include <QList>

class SchoolClass
{
private:

public:
    QString class_name;
    SchoolClass();
    QList<Lesson> class_lesson;
    SchoolClass(QString);
};

#endif // SCHOOLCLASS_H
