#ifndef LESSON_H
#define LESSON_H
#include <string>


class lesson
{
    public:
        lesson(string title, bool kind);
        virtual ~lesson();
    protected:
    private:
        string lesson_name;
        bool lesson_kind;
};
#endif // LESSON_H
