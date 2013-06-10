#ifndef DAY_H
#define DAY_H

#include <QString>
#include <QVector>

class Day
{
private:
    QString name;
    QVector<int> hours;

public:
    Day(QString n){this->name = n;}
    Day(QVector<int>h){this->hours = h;}




};


#endif // DAY_H
