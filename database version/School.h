#ifndef SCHOOL_H
#define SCHOOL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QList>
#include "Teacher.h"
#include "classes.h"
#include "Day.h"
#include <QGridLayout>
#include <QtDebug>
#include <QtSql>

class School : public QWidget
{
    Q_OBJECT

private:
    QWidget *setter;
    QList <Teacher> list_of_teachers;
    QVBoxLayout *vb;
    QHBoxLayout *mainlayout;
    QGroupBox *gb1;
    QGroupBox *gb2;
    QLineEdit *line;
    QCheckBox *sh1,*sh2,*sh3,*sh4;
    QCheckBox *y1,*y2,*y3,*y4;
    QCheckBox *d1,*d2,*d3,*d4;
    QCheckBox *s1,*s2,*s3,*s4;
    QCheckBox *ch1,*ch2,*ch3,*ch4;
    QGridLayout *gridlayout;
    QHBoxLayout *forteacherline0;
    QHBoxLayout *forteacherline1;
    QHBoxLayout *forteacherline2;
    QHBoxLayout *forteacherline3;
    QHBoxLayout *forteacherline4;
    QHBoxLayout *forteacherline5;
    QHBoxLayout *forteacherline6;
    QHBoxLayout *forteacherline7;
    QLabel *shanbe,*yekshanbe,*doshanbe,*seshanbe,*charshanbe;
    QLabel *zangs;
    QLabel *name;
    QSqlDatabase db;

public:
    School(QList<Teacher>t);
    School(QWidget *parent = 0);
    friend class widget;

public slots:
    void sabte_moallem();
    void Open_info();
};


#endif // SCHOOL_H
