#ifndef LESSON_MAKER_H
#define LESSON_MAKER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include "Teacher.h"
#include "Class.h"
#include <QtDebug>


class lesson_maker : public QWidget
{
    Q_OBJECT

private:
    QList <Lesson> list_of_lessons;
    QVBoxLayout *vb;
    QHBoxLayout *mainlayout;
    QGroupBox *gb1;
    QGroupBox *gb2;
    QLineEdit *line;


public:
    lesson_maker(QList<Lesson>t){list_of_lessons = t;}
    lesson_maker(QWidget *parent = 0);

public slots:
    void Make_LineEdit();  //to save the content of the last QLineEdit and make a new QLineEdit in the page
    void Open_CPage();     //to open the next page
    };


#endif // LESSON_MAKER_H
