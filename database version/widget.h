#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include "School.h"
#include "Lesson.h"
#include "classes.h"
#include "lesson_maker.h"


class Widget : public QWidget
{
    Q_OBJECT
private:
    School s;
    lesson_maker j;
    Classes c;


public:

    Widget(QWidget *parent = 0);
    QLabel *wel;
    QPushButton *ok;
    QPushButton *ok2;
    QPushButton *tanzim;
    QPushButton *kelas;
    QPushButton *setemoallemodars;
    QPushButton *quit;
    QVBoxLayout *vb;


    ~Widget();
public slots:
    void open_spage();
    void open_jpage();
    void Quit();
    void Setemoallemodars();
    void Kelas();
    void Tanzim();


};
#endif // WIDGET_H
