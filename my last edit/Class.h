#ifndef CLASS_H
#define CLASS_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "Teacher.h"
#include "Day.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QList>

class Class : public QWidget
{
private:
    QComboBox * combo_teachers;
    QLabel * label;
    QList<Teacher> list_of_class_teachers;
    //QVector <Teacher> class_teachers;
    QVector <Day> class_times;
public:
    Class(QWidget *parent = 0);

};


#endif // CLASS_H
