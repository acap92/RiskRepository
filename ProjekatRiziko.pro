#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T17:47:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT += widgets

QT += multimedia

TARGET = ProjekatRiziko
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    territory.cpp \
    turn.cpp \
    global.cpp \
    functions.cpp \
    mainwindow.cpp \
    startingwindow.cpp \
    gamesetup.cpp \
    playerwidget.cpp \
    continent.cpp \
    world.cpp

HEADERS += \
    player.h \
    territory.h \
    turn.h \
    global.h \
    functions.h \
    mainwindow.h \
    startingwindow.h \
    gamesetup.h \
    playerwidget.h \
    continent.h \
    world.h


FORMS += \
    mainwindow.ui \
    startingwindow.ui \
    gamesetup.ui \
    playerwidget.ui

RESOURCES +=
