#include "setter.h"

Setter::Setter(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("set teachers and lessons");
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    QHBoxLayout *H1 = new QHBoxLayout;
    QHBoxLayout *H2 = new QHBoxLayout;
    sabt = new QPushButton("ثبت این درس برای معلم");
    teacherscombo = new QComboBox(this);
    lessonscombo = new QComboBox(this);
    //check = new QPushButton("check");
    QLabel *thislabel = new QLabel("در این قسمت نام معلم و درس مربوط به وی را انتخاب کرده و بر روی دکمه ثبت کلیک کنید");
    mainlayout->addLayout(H1);
    mainlayout->addLayout(H2);
    H1->addWidget(thislabel);
    H2->addWidget(sabt);
    //H2->addWidget(check);
    H2->addWidget(teacherscombo);
    H2->addWidget(lessonscombo);

    //queryrunner();
    QSqlQuery nquery;
    nquery.exec("select name,hour,kind from lessons;");
    while(nquery.next()){
        QString n = nquery.value(0).toString();
        int h = nquery.value(1).toInt();
        int k = nquery.value(2).toInt();
        bool ki = false;
        if(k == 1)ki = true;
        Lesson q(n,h,ki);
        setinglistlesson.append(q);
    }

    QSqlQuery query;
    query.exec("select name,hours from teachers;");
    while(query.next()){
        QString n = query.value(0).toString();
        QString h = query.value(1).toString();
        qDebug() << h.length();
        QList<Day>d;
        Day Shanbeh;
        Day Yekshanbeh;
        Day Doshanbeh;
        Day Seshanbeh;
        Day Charshanbeh;
        d.append(Shanbeh);
        d.append(Yekshanbeh);
        d.append(Doshanbeh);
        d.append(Seshanbeh);
        d.append(Charshanbeh);
        int i = 1;
        int j = 0;
        bool kind;
        for(int k = 0;k < h.length();k++){
            if(h[k] == '0')kind = false;
            else{kind = true;}
            if(i==1){
                d[j].z1 = b;
                i += 1;
            }
            else if(i == 2){
                d[j].z2 = b;
                i += 1;
            }
            else if(i == 3){
                d[j].z3 = b;
                i += 1;
            }
            else if(i == 4){
                d[j].z4 = b;
                i = 1;
                j += 1;
            }
        }
        //for(int e=0;e<3;e++)qDebug() << "list" << d[e].z1 << d[e].z2;
        Teacher q(n,d);
        settinglistteacher.append(q);
    }

    connect(sabt,SIGNAL(clicked()),this,SLOT(sabtedarsforteacher()));
    //connect(check,SIGNAL(clicked()),this,SLOT(checker()));
}

void Setter::sabtedarsforteacher()
{
    QString tn = teacherscombo->currentText();
    int si = 0;
    for(int i = 0;i < settinglistteacher.size();i++){
        if(settinglistteacher[i].name == tn){
            si = i;
            break;
        }
    }
    QString s = "";
//    for(int j = 0; j < 5;j++){
//        if(settinglistteacher[si].day[j].z1 == true)s+='1';
//        else{s += '0';}
//        if(settinglistteacher[si].day[j].z2 == true)s+='1';
//        else{s += '0';}
//        if(settinglistteacher[si].day[j].z3 == true)s+='1';
//        else{s += '0';}
//        if(settinglistteacher[si].day[j].z4 == true)s+='1';
//        else{s += '0';}
//    }
    QString ln = lessonscombo->currentText();
    int sp = 0;
    for(int p = 0; p < setinglistlesson.size();p++){
        if(setinglistlesson[p].name == ln){
            sp = p;
            break;
        }
    }
    int lh = setinglistlesson[sp].hours;
    bool lb = setinglistlesson[sp].kind;
    int ilb=0;
    if(lb == true)ilb = 1;
    else{ilb = 0;}

    QSqlQuery query;
    query.exec("INSERT INTO setter VALUES('"+tn+"','"+s+"','"+ln+"','"+QString::number(lh)+"','"+QString::number(ilb)+"');");
}

void Setter::checker()
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("setter");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

void Setter::queryrunner(){
    settinglistteacher.clear();
    setinglistlesson.clear();
    QSqlQuery nquery;
    nquery.exec("select name,hour,kind from lessons;");
    while(nquery.next()){
        QString n = nquery.value(0).toString();
        int h = nquery.value(1).toInt();
        int k = nquery.value(2).toInt();
        bool ki = false;
        if(k == 1)ki = true;
        Lesson q(n,h,ki);
        setinglistlesson.append(q);
    }

    QSqlQuery query;
    query.exec("select name,hours from teachers;");
    while(query.next()){
        qDebug() << "h";
        QString n = query.value(0).toString();
        QString h = query.value(1).toString();
        QList<Day>d;
        int i = 0;
        bool kind;
        for(int k = 0;k < h.size();k++){
            if(h[k] == '0')kind = false;
            else{kind = true;}
            if(i==1){
                d[k].z1 = b;
                i += 1;
            }
            else if(i == 2){
                d[k].z2 = b;
                i += 1;
            }
            else if(i == 3){
                d[k].z3 = b;
                i += 1;
            }
            else if(i == 4){
                d[k].z4 = b;
                i = 1;
                k += 1;
            }
        }
        Teacher q(n,d);
        settinglistteacher.append(q);
    }
}
