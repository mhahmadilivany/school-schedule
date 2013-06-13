#ifndef LESSON_MAKER_H
#define LESSON_MAKER_H
#include "saved_lessons.h"
#include "Lesson.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include "Teacher.h"
#include "Class.h"
#include <QtDebug>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <QList>
#include <QMessageBox>



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
    QRadioButton *ekhorom;
    QRadioButton *ekhorom2;
    QGroupBox *gforekhorom;
    QHBoxLayout *hforekhorom;
    QLabel *kindoflesson;
    QVBoxLayout *foreachlessonv;
    QHBoxLayout *foreachlessonh1;
    QHBoxLayout *foreachlessonh2;
    QHBoxLayout *foreachlessonh3;
    QLabel *nameoflesson;
    QPushButton *push1;
    QPushButton *push2;
    QPushButton *push3;
    QLineEdit *line2;
    QLabel *hoursofteachin;
    QMessageBox *msgbox2;
    QString NameOfLessons;

public:

    lesson_maker(QList<Lesson>t);//{list_of_lessons = t;}
    lesson_maker(QWidget *parent = 0);

public slots:
    void New_Lesson();      //checks if any of widgets is empty,saves the name of the lesson,its kind and hour of teaching
    void Go_Back();
    void Open_infopage();
    };


#endif // LESSON_MAKER_H
