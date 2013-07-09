#-------------------------------------------------
#
# Project created by QtCreator 2013-06-06T21:52:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = schedule
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Teacher.cpp \
    Lesson.cpp \
    Day.cpp \
    School.cpp \
    lesson_maker.cpp \
    schoolclass.cpp \
    classes.cpp \
    setter.cpp \
    programming.cpp

HEADERS  += widget.h \
    Teacher.h \
    Lesson.h \
    Day.h \
    School.h \
    lesson_maker.h \
    schoolclass.h \
    classes.h \
    setter.h \
    programming.h
