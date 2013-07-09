#include "programming.h"

Programming::Programming(QWidget *parent) :
    QWidget(parent)
{
    for(int i=0;i<20;i++){
    ClassTimes.append(true);}
    mainbutton = new QPushButton("ساخت برنامه");
    mainlayout = new QHBoxLayout(this);
    mainlayout->addWidget(mainbutton);
    connect(mainbutton,SIGNAL(clicked()),this,SLOT(ReadFromDatabase()));
}
void Programming::creator(){
    for (int f=0;f<ThisClassLessons.size();f++){
        if (ThisClassLessons[f].hours!=0){
            FinalList.append(ThisClassLessons[f]);
            FinalListPrinter.append(ThisClassLessons[f].name);
            ThisClassLessons[f].hours-=2;}

    }
    for (int t=0;t<ThisClassLessons.size();t++){
        if (ThisClassLessons[t].hours!=0)
            creator();
     }
}

void Programming :: ReadFromDatabase(){
    QSqlQuery query5;
    query5.exec("select name,hour,kind FROM lessons;");
    while(query5.next()){
        QString thisname = query5.value(0).toString();
        int thishour = query5.value(1).toInt();
        int thiskind = query5.value(2).toInt();
        bool ki = false;
        if(thiskind == 1)ki = true;
        Lesson q(thisname,thishour,ki);
        ThisClassLessons.append(q);
}

        QSqlQuery query6;
        query6.exec("select name,hours FROM teachers;");
        while(query6.next()){
            QString hisname = query6.value(0).toString();
            QString hishour = query6.value(1).toString();}
            qDebug() << "lenght=" << ThisClassLessons.length();
        creator();
        for (int y=0 ; y<FinalListPrinter.length();y++){
            qDebug() << FinalListPrinter[y];
        }
}
