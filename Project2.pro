#-------------------------------------------------
#
# Project created by QtCreator 2021-07-13T14:14:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    page2.cpp \
    page3.cpp \
    nowins.cpp \
    settings.cpp \
    page2easy.cpp \
    commonvars.cpp \
    enemychoice.cpp \
    pvp.cpp

HEADERS += \
        mainwindow.h \
    page3.h \
    commonvars.h \
    nowins.h \
    settings.h \
    page2.h \
    page2easy.h \
    enemychoice.h \
    pvp.h

FORMS += \
        mainwindow.ui \
    page2.ui \
    page3.ui \
    nowins.ui \
    settings.ui \
    page2easy.ui \
    enemychoice.ui \
    pvp.ui

LIBS += \
    -L/usr/local/lib -lwiringPi

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
