#include "setter.h"

Setter::Setter(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    QHBoxLayout *H1 = new QHBoxLayout;
    QHBoxLayout *H2 = new QHBoxLayout;
    sabt = new QPushButton("ثبت این درس برای معلم");
    teacherscombo = new QComboBox(this);
    lessonscombo = new QComboBox(this);
    check = new QPushButton("check");
    QLabel *thislabel = new QLabel("در این قسمت نام معلم و درس مربوط به وی را انتخاب کرده و بر روی دکمه ثبت کلیک کنید");
    mainlayout->addLayout(H1);
    mainlayout->addLayout(H2);
    H1->addWidget(thislabel);
    H2->addWidget(sabt);
    H2->addWidget(check);
    H2->addWidget(teacherscombo);
    H2->addWidget(lessonscombo);

    QSqlQuery query;
    query.exec("select name,hours from teachers;");
    while(query.next()){
        QString n = query.value(0).toString();
        int h = query.value(1).toInt();
        Teacher q(n);
        settinglistteacher.append(q);}



    QSqlQuery myquery;
    myquery.exec("select name,hour,kind from lessons;");
    while(myquery.next()){
        QString n = myquery.value(0).toString();
        int h = myquery.value(1).toInt();
        int k = myquery.value(2).toInt();
        bool ki = false;
        if(k == 1)ki = true;
        Lesson q(n,h,ki);
        setinglistlesson.append(q);

}


    db4 = QSqlDatabase :: addDatabase("QSQLITE");
    db4.setDatabaseName("setting.db");
    db4.open();

    QSqlQuery newquery("CREATE TABLE setter(teacher text,lesson text);",db4);



    connect(sabt,SIGNAL(clicked()),this,SLOT(sabtedarsforteacher()));
    connect(check,SIGNAL(clicked()),this,SLOT(checker()));
}
void Setter::sabtedarsforteacher(){
    QSqlQuery query;
    query.exec("INSERT INTO setter VALUES('"+teacherscombo->currentText()+"','"+lessonscombo->currentText()+"');");
}

void Setter::checker(){
    Ctable();
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("setter");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();

    //this->close();
}
void Setter::Ctable(){
        QSqlQuery query("CREATE TABLE setter(teacher text,lesson text);",db4);
}
