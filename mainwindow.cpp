#include "mainwindow.h"
#include "lending_system.h"


mainwindow::mainwindow(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);
    lend.read_person();     //from file to QList
    lend.read_medium();
}

mainwindow::~mainwindow(){
    lend.write_person();    //from QList to file
    lend.write_medium();
}
