#include "classes.h"

Classes::Classes(QWidget *parent) :
    QWidget(parent)
{
    classmainlayout = new QHBoxLayout(this);
    classHB1 = new QHBoxLayout;
    classHB2 = new QHBoxLayout;
    classHB3 = new QHBoxLayout;
    classname = new QLabel("نام کلاس:");
    classnamelineedit = new QLineEdit;
    classVB1 = new QVBoxLayout;
    classVB2 = new QVBoxLayout;
    classVB3 = new QVBoxLayout;
    lessoncombo = new QComboBox;
    classHB1->addWidget(classnamelineedit);
    classHB1->addWidget(classname);
    classVB1->addLayout(classHB1);
    classVB1->addLayout(classHB2);
    back = new QPushButton("بازگشت");
    showinfo = new QPushButton("کلاسهای ذخیره شده");
    showinfolessons = new QPushButton("دروس ثبت شده");
    sabt = new QPushButton("ثبت کلاس");
    sabtedars = new QPushButton("ثبت درس");
    classmainlayout->addLayout(classVB1);
    classmainlayout->addLayout(classVB2);
    classVB2->addWidget(sabt);
    classVB2->addWidget(showinfo);
    classVB2->addWidget(showinfolessons);
    classVB2->addWidget(back);
    classHB2->addWidget(lessoncombo);
    classHB2->addWidget(sabtedars);
    connect(sabt,SIGNAL(clicked()),this,SLOT(sabtekelas()));
    connect(showinfo,SIGNAL(clicked()),this,SLOT(show_info()));
    connect(showinfolessons,SIGNAL(clicked()),this,SLOT(show_info_lessons()));
    connect(sabtedars,SIGNAL(clicked()),this,SLOT(sabte_dars()));
    connect(back,SIGNAL(clicked()),this,SLOT(Quit()));

    QSqlQuery query;
    QList<QString>l;
    query.exec("select name,hour,kind from lessons;");
    while(query.next()){
        QString n = query.value(0).toString();
        int h = query.value(1).toInt();
        int k = query.value(2).toInt();
        bool ki = false;
        if(k == 1)ki = true;
        Lesson q(n,h,ki);
        class_lessons.append(q);
        l.append(n);
    }
    for(int i =0;i<l.size();i++) lessoncombo->addItem(l[i]);

    db2 = QSqlDatabase :: addDatabase("QSQLITE");
    db2.setDatabaseName("Classes.db");
    db2.open();
}

void Classes::sabtekelas(){
        SchoolClass SC(classnamelineedit->text());
        showinfoforclass.append(SC.class_name);
        showinfoforclass.append("\n");
        classnamelineedit->setText("");
        x += 1;
        QSqlQuery query("CREATE TABLE class"+QString::number(x)+" (name text,hour int,kind int);",db2);
}

void Classes::Quit(){
    this->close();
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("class"+QString::number(x));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

void Classes :: show_info()
{
    QMessageBox *classmsgbox = new QMessageBox;
    classmsgbox->setText(showinfoforclass);
    classmsgbox->show();
}

void Classes :: show_info_lessons()
{
    QList<QString>l;
    QSqlQuery query("select name from class"+QString::number(x),db2);
    while(query.next()){
        QString v = query.value(0).toString();
        l.append(v);
    }
    QString s;
    for(int i=0;i<l.size();i++)s += l[i]+"\n";
    QMessageBox *classmsgbox = new QMessageBox;
    classmsgbox->setText(s);
    classmsgbox->show();
}

void Classes :: sabte_dars()
{
    QString c;
    c = lessoncombo->currentText();
    Lesson a;
    for(int i=0;i<class_lessons.size();i++){
        a = class_lessons[i];
        if(c == a.name)break;
    }
    QSqlQuery query;
    QString n = a.name;
    int h = a.hours;
    bool k = a.kind;
    int ki = 0;
    if(k == true)ki = 1;
    query.exec("insert into class"+QString::number(x)+" values('"+n+"','"+QString::number(h)+"','"+QString::number(ki)+"');");
}
