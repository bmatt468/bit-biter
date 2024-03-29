#-------------------------------------------------
#
# Project created by QtCreator 2012-03-12T20:21:33
#
#-------------------------------------------------

QT       += core gui

TARGET = bit-biter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameform.cpp \
    gameboard.cpp \
    snake.cpp \
    options.cpp

HEADERS  += mainwindow.h \
    gameform.h \
    gameboard.h \
    snake.h \
    options.h

FORMS    += mainwindow.ui \
    gameform.ui \
    options.ui

RESOURCES += \
    fonts.qrc
