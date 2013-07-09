#include "widget.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QSqlDatabase db;
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("Database.db");
    db.open();
    QSqlQuery newquery("CREATE TABLE setter(teacher_name text,teacher_freetime int,lesson_name text,lesson_hour int,lesson_kind int);",db);
    QSqlQuery query("CREATE TABLE lessons (name text,hour int,kind int);",db);
    QSqlQuery query1("CREATE TABLE teachers (name TEXT, hours TEXT);",db);
    lesson_maker LM;
    w.show();

    return a.exec();
}
