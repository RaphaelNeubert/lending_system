######################################################################
# Automatically generated by qmake (3.1) Sun Jul 4 20:59:46 2021
######################################################################

TEMPLATE = app
TARGET = lending_system
INCLUDEPATH += .
QT += widgets
CONFIG += debug

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Book.h \
           Cd.h \
           LendingSystem.h \
           MainWindow.h \
           Medium.h \
           MediumDialog.h \
           Person.h \
           PersonDialog.h
FORMS += MainWindow.ui MediumDialog.ui PersonDialog.ui
SOURCES += Book.cpp \
           Cd.cpp \
           LendingSystem.cpp \
           main.cpp \
           MainWindow.cpp \
           Medium.cpp \
           MediumDialog.cpp \
           Person.cpp \
           PersonDialog.cpp
