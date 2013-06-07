#-------------------------------------------------
#
# Project created by QtCreator 2013-06-06T21:52:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = schedule
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Teacher.cpp \
    Lesson.cpp \
    Day.cpp \
    Class.cpp

HEADERS  += widget.h \
    Teacher.h \
    Lesson.h \
    Day.h \
    Class.h
