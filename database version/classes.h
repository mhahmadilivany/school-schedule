#ifndef CLASSES_H
#define CLASSES_H

#include <QWidget>
#include <QWidget>
#include <QVector>
#include <QString>
#include "Day.h"
#include "lessons.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QList>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "schoolclass.h"
#include "lesson_maker.h"
#include <QtSql>
#include <QSqlTableModel>
#include <QTableView>

class Classes : public QWidget
{
    Q_OBJECT
private:
    QComboBox * combo_teachers;
    QLabel * label;
    QList <Day> class_times;
    QList <Lesson> class_lessons;
    QString showinfoforclass;
    QLabel *classname;
    QHBoxLayout *classHB1;
    QHBoxLayout *classHB2;
    QHBoxLayout *classHB3;
    QHBoxLayout *classmainlayout;
    QVBoxLayout *classVB1;
    QVBoxLayout *classVB2;
    QVBoxLayout *classVB3;
    QComboBox *lessoncombo;
    QLineEdit *classnamelineedit;
    QPushButton *sabt;
    QPushButton *showinfo;
    QPushButton *showinfolessons;
    QPushButton *sabtedars;
    QPushButton *back;
    int x = 0;
    QSqlDatabase db2;

public:
    explicit Classes(QWidget *parent = 0);
    
signals:
    
public slots:
    void sabtekelas();
    void show_info();
    void show_info_lessons();
    void sabte_dars();
    void Quit();
    
};

#endif // CLASSES_H
