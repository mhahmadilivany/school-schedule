#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include <QWidget>
#include <QtSql>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QString>
#include "Lesson.h"
#include "Teacher.h"
#include <QtDebug>

class Programming : public QWidget
{
    Q_OBJECT
private:
    QPushButton *mainbutton;
    QList <Lesson> ThisClassLessons;
    QList <Teacher> ThisClassTeachers;
    QList <Lesson> FinalList;
    QList <QString> FinalListPrinter;
    QList <bool> ClassTimes;
    QList <int> LessonTimesInWeek;
    QHBoxLayout *mainlayout;
public:
    explicit Programming(QWidget *parent = 0);
        void creator();

signals:

public slots:
    void ReadFromDatabase();
};

#endif // PROGRAMMING_H
