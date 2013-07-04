#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    lesson_maker LM;
    w.show();

    return a.exec();
}
