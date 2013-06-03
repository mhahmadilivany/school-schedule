#include "teacher.h"
#include "lesson.h"
#include "time.h"

teacher::teacher(string name,lesson lessons[5],mtime freetime[4])
{                  
                   teacher_name=name;
                   for (int i=0;i<5;i++)
                   teacher_lessons[i]=lessons[i];
                   for (int j=0;j<4;j++)
                   teacher_freetime[j]=freetime[j];    

    //ctor
}

teacher::~teacher()
{
    //dtor
}
lesson math("math",true);
lesson geo("geometry",true);
lesson phys("pysics",true);
lesson farsi("farsi",false);
lesson arabic("Arabic",false);
lesson theo("dini",false);
lesson dif("difrensial",true);
//teacher ziaeinejad("soroush",[math,geo,phys,farsi,theo],[1,2,3,4]);
