#ifndef DAY_H
#define DAY_H

#include <QString>
#include <QList>

class Day
{
public:
    bool z1;
    bool z2;
    bool z3;
    bool z4;
    Day(QString n);
    Day(QList<int>h);
    Day();
};

#endif // DAY_H
