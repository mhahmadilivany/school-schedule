#ifndef MTIME_H
#define MTIME_H
#include<iostream>
#include <string>
using namespace std;

class mtime
{
    public:
        mtime(string day[5],int zang[4]);
        virtual ~mtime();
    protected:
    private:
            string day[6];
            int zang[4];
};

#endif
