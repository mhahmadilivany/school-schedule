#include "lesson.h"

lesson::lesson(string title, bool kind) // about the kinds, 1 for special and 0 for general
{
     lesson_name=title;
     lesson_kind=kind;
    //ctor
    
}

lesson::~lesson()
{
    //dtor
}
lesson* math("math",true);
lesson* geo("geometry",true);
lesson* phys("pysics",true);
lesson* farsi("farsi",false);
lesson* arabic("Arabic",false);
lesson* theo("dini",false);
lesson* dif("difrensial",true);
