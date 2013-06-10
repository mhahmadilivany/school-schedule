#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include "School.h"


class Widget : public QWidget
{
    Q_OBJECT
    
private:
    School s;
public:
    Widget(QWidget *parent = 0);
    QLabel *wel;
    QPushButton *ok;
    QVBoxLayout *vb;
    ~Widget();
public slots:
    void open_spage();
};

#endif // WIDGET_H
