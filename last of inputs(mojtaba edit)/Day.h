#ifndef DAY_H
#define DAY_H

#include <QString>
#include <QList>
#include "hours.h"

class Day
{
private:
    //QString name;
    //hours hourses;


public:
    bool z1;
    bool z2;
    bool z3;
    bool z4;
    Day(QString n);//{this->name = n;}
    Day(QList<int>h);//{this->hours = h;}
    Day();




};


#endif // DAY_H
