#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainlayout1 = new QVBoxLayout;
    QVBoxLayout *mainlayout2 = new QVBoxLayout;
    QGroupBox *maingroup1 = new QGroupBox("first group");
    QGroupBox *maingroup2 = new QGroupBox("second group");
    QHBoxLayout *mainlayout = new QHBoxLayout(this);
    QLineEdit *name = new QLineEdit;
    QLineEdit *family = new QLineEdit;
    QVBoxLayout *vb1 = new QVBoxLayout;
    vb1->addWidget(name);
    vb1->addWidget(family);
    QGroupBox *group1 = new QGroupBox("name");
    group1->setLayout(vb1);
    QCheckBox *check1 = new QCheckBox("feel good");
    QCheckBox *check2 = new QCheckBox("good");
    QCheckBox *check3 = new QCheckBox("well");
    QVBoxLayout *vb2 = new QVBoxLayout;
    vb2->addWidget(check1);
    vb2->addWidget(check2);
    vb2->addWidget(check3);
    QGroupBox *group2 = new QGroupBox("feelings");
    group2->setLayout(vb2);
    mainlayout1->addWidget(group1);
    mainlayout1->addWidget(group2);
    QRadioButton *radio1 = new QRadioButton("go");
    QRadioButton *radio2 = new QRadioButton("not go");
    QRadioButton *radio3 = new QRadioButton("maybe");
    QVBoxLayout *vb3 = new QVBoxLayout;
    vb3->addWidget(radio1);
    vb3->addWidget(radio2);
    vb3->addWidget(radio3);
    QGroupBox *group3 = new QGroupBox("choose one");
    group3->setLayout(vb3);
    mainlayout1->addWidget(group3);
    QComboBox *combo = new QComboBox;
    combo->addItem("this is good");
    combo->addItem("this is not enough");
    combo->addItem("this is efficient");
    QVBoxLayout *vb4 = new QVBoxLayout;
    QPushButton *push1 = new QPushButton("ok");
    QPushButton *push2 = new QPushButton("wrote");
    QGroupBox *group4 = new QGroupBox("about");
    group4->setLayout(vb4);
    QTextEdit *text = new QTextEdit;
    vb4->addWidget(text);
    vb4->addWidget(push2);
    QHBoxLayout *hb1 = new QHBoxLayout;
    hb1->addWidget(combo);
    hb1->addWidget(push1);
    QGroupBox *group5 = new QGroupBox("choose one");
    group5->setLayout(hb1);
    mainlayout2->addWidget(group4);
    mainlayout2->addWidget(group5);
    maingroup1->setLayout(mainlayout1);
    maingroup2->setLayout(mainlayout2);
    mainlayout->addWidget(maingroup1);
    mainlayout->addWidget(maingroup2);

    push1->setStyleSheet("background-color: red;"
                         "border-style: outset;"
                         "border-width: 2px;"
                         "border-radius: 10px;"
                         "border-color: blue;"
                         "font: bold 12px;"
                         "min-width: 4em;"
                         "padding: 4px;"
                         );

    push2->setStyleSheet("QPushButton {"
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                           "stop: 0 #f6f7fa, stop: 1 #dadbde);"
                         "min-width: 80px}"
                         "QPushButton:pressed {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                              "stop: 0 #dadbde, stop: 1 #f6f7fa);}");

    name->setStyleSheet("QLineEdit {"
                        "color:yellow;"
                        "font: bold 10px;"
                        "border: 2px solid gray;"
                        "border-radius: 10px;"
                        "padding: 0 8px;"
                        "background: purple;"
                        "selection-background-color: brown;}"
                    );
    family->setStyleSheet("QLineEdit {"
                          "color: blue;"
                          "font: bold 14px;"
                          "border: 4px solid black;"
                          "border-radius: 13px;"
                          "padding: 2 10px;"
                          "background: green;"
                          "selection-background-color: yellow;}");
    check1->setChecked(true);
    check1->setStyleSheet("QCheckBox::indicator:unchecked {"
                          "image: url(:/images/checkbox_unchecked.png);}");
    check2->setStyleSheet("QCheckBox::indicator:unchecked:hover {"
                          "image: url(:/images/checkbox_unchecked_hover.png);}");
    check3->setStyleSheet("QCheckBox::indicator:unchecked:pressed {"
                           "image: url(:/images/checkbox_unchecked_pressed.png);}");
    combo->setStyleSheet(
                "QComboBox{"
                "border: 2px solid gray;"
                "border-radius: 5px;"
                "padding: 1px 18px 1px 3px;"
                "min-width: 6em;}"
                "QComboBox::drop-down {"
                "subcontrol-origin: padding;"
                "subcontrol-position: top right;"
                "width: 15px;"
                "border-left-width: 3px;"
                "border-left-color: yellow;"
                "border-left-style: solid;"
                "border-top-right-radius: 5px;"
                "border-bottom-right-radius: 5px;}"
                "QComboBox QAbstractItemView {"
                             "border: 4px solid brown;"
                             "selection-background-color: blue;}"
                "QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
                    "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                "stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,"
                                                "stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);}");

    group1->setStyleSheet("QGroupBox {"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                          "stop: 0 #E0E0E0, stop: 1 #FFFFFF);"
                          "border: 2px red;"
                          "border-radius: 5px;"
                          "margin-top: 1ex;}"
                          );
    group2->setStyleSheet("QGroupBox::title {"
                          "subcontrol-position: top center;}");

    radio1->setChecked(true);
    radio1->setStyleSheet("QRadioButton::indicator::unchecked {"
                          "image: url(:/images/radiobutton_unchecked.png);}"
                                             );
    radio2->setStyleSheet("QRadioButton::indicator:unchecked:pressed {"
                           "image: url(:/images/radiobutton_unchecked_pressed.png);}"
                                                                       );
    radio3->setStyleSheet("QRadioButton::indicator:checked:hover {"
                          "image: url(:/images/radiobutton_checked_hover.png);}"
                          );

    text->setPlainText("hello,this is a sample page made by Qt stylesheet codes."
                       "as you see the first group box(on top left)background is made nice:) and there are "
                       "two beautiful LineEdits with their own features that if you click on them "
                       "and write somthing you will see.don't forget to select your writing to see what will "
                       "happen about their selection color ;)"
                       "the next groupbox title is centered..."
                       "there are three checkboxes that each of them has thier own features for chooseing..."
                       "and the radiobuttons are the same..."
                       "the pushbutton 'wrote' bellow is an amazing button that if click on it it is pressed "
                       "in a nice shape...as you are seeing the combobox it is so much different from usual comboboxes.just examine it "
                       "to see it's features.and the last nice button that doesn't need to compliment it:))");
}


Widget::~Widget()
{    
}
