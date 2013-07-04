#include "Lesson.h"

Lesson :: Lesson(QString n, int h, bool k)
{
    this->name = n;
    this->hours = h;
    this->kind = k;
}
Lesson :: Lesson(QString m)
{
    this->name = m;
}
Lesson :: Lesson(){

}
