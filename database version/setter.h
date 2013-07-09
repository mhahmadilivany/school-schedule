#ifndef SETTER_H
#define SETTER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QtSql>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QtDebug>
#include "Lesson.h"
#include "lesson_maker.h"
#include "Teacher.h"
#include "School.h"

class Setter : public QWidget
{
    Q_OBJECT

private:
    QPushButton *sabt;
    QPushButton *check;
    QSqlDatabase db4;
    bool b = true;

public:
    QList <Lesson> setinglistlesson;
    QList <Teacher> settinglistteacher;
    explicit Setter(QWidget *parent = 0);
    QComboBox *teacherscombo;
    QComboBox *lessonscombo;
    void updater();
    void teacherupdater();

public slots:
    void sabtedarsforteacher();
    void checker();
    void queryrunner();
};

#endif // SETTER_H
