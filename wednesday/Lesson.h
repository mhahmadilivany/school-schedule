#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QList>

class Lesson

{
private:
    QString name;
    int hours;
    bool kind;
public:
    Lesson(QString,int,bool);
    Lesson(QString);
    Lesson();
};


#endif // LESSON_H
