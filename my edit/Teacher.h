#ifndef TEACHER_H
#define TEACHER_H

#include "Lesson.h"
#include "Day.h"

#include <QGroupBox>
#include <QWidget>
#include <QString>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>


class Teacher : public QWidget
{
    Q_OBJECT

private:
    QString name;
    QVector<Lesson>les;
    QVector<Day>day;
    QVBoxLayout *vb6;
    QHBoxLayout *mainlayout;
    QGroupBox *g1;
    QGroupBox *g2;
public:
    Teacher(QWidget *parent = 0);
    Teacher(QString n){this->name = n;}
    Teacher(QVector<Lesson>l){this->les = l;}
    Teacher(QVector<Day>d){this->day = d;}

public slots:
    void Make_LineEdit();



};




#endif // TEACHER_H
