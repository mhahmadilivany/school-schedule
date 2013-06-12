#ifndef DAY_H
#define DAY_H

#include <QString>
#include <QList>

class Day
{
private:
    QString name;
    QList<int> hours;

public:
    Day(QString n);//{this->name = n;}
    Day(QList<int>h);//{this->hours = h;}
    Day();




};


#endif // DAY_H
