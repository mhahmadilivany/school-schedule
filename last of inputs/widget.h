#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include "School.h"
#include "Lesson.h"
#include "lesson_maker.h"
#include "saved_lessons.h"


class Widget : public QWidget
{
    Q_OBJECT
private:
    School s;
    lesson_maker j;


public:

    Widget(QWidget *parent = 0);
    QLabel *wel;
    QPushButton *ok;
    QPushButton *ok2;
    QVBoxLayout *vb;
    ~Widget();
public slots:
    void open_spage();
    void open_jpage();
};
#endif // WIDGET_H
