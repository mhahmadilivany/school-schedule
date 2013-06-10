#ifndef SCHOOL_H
#define SCHOOL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include "Teacher.h"
#include "Class.h"


class School : public QWidget
{
    Q_OBJECT

private:
    //QVector<Teacher>teachers;
    QList <Teacher> list_of_teachers;
    QVBoxLayout *vb;
    QHBoxLayout *mainlayout;
    QGroupBox *gb1;
    QGroupBox *gb2;
    QLineEdit *line;
    Class c;

public:
    School(QList<Teacher>t){list_of_teachers = t;} //sets the vector entered as the member function
    School(QWidget *parent = 0);  //to make a widget that the names of the school teacher will be entered

public slots:
    void Make_LineEdit();  //to save the content of the last QLineEdit and make a new QLineEdit in the page
    void Open_CPage();     //to open the next page
    };


#endif // SCHOOL_H
