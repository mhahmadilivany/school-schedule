#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QList>

class Lesson

{
public:
    int hours;
    bool kind;
    QString name;
    Lesson(QString,int,bool);
    Lesson(QString);
    Lesson();
};


#endif // LESSON_H
