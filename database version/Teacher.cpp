#include "Teacher.h"

Teacher :: Teacher(QString n)
{
    name = n;
}

Teacher :: Teacher(QString n, QList<Day>d)
{
    name = n;
    for(int i = 0;i < d.size();i++){
        day[i] = d[i];
    }
}
