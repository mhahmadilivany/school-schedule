#ifndef TEACHER_H
#define TEACHER_H

#include "Lesson.h"
#include <QComboBox>
#include "Day.h"
#include "lesson_maker.h"
#include <QGroupBox>
#include <QWidget>
#include <QString>
#include <QList>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>


class Teacher // : public QWidget
{
 //   Q_OBJECT

private:
    QComboBox *combo;
    QComboBox *combo2;

public:
    Teacher();
    QList <Lesson> les;
    QList<Day>day;

    QString name;
    Teacher(QWidget *parent = 0);
    Teacher(QString n);//{this->name = n;}
    Teacher(QList <Lesson> l);//{this->les = l;}
    Teacher(QList <Day> d);//{this->day = d;}
public slots:
    void setLesson();

};




#endif // TEACHER_H
