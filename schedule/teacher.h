#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "teacher.h"
#include "lesson.h"
#include "time.h"


class teacher
{
    public:
        teacher(string name,lesson lessons[5],mtime freetime[4]);
        virtual ~teacher();
    protected:
    private:
    string teacher_name;
    lesson teacher_lessons[5];
    mtime teacher_freetime[4];
};

#endif // TEACHER_H
