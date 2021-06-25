#include "mainwindow.h"
#include "lending_system.h"
#include <QDebug>
#include <QPushButton>


mainwindow::mainwindow(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);

    read_person();     //from file to QList
    read_medium();

    create_person_table();
}

mainwindow::~mainwindow(){
    write_person();    //from QList to file
    write_medium();
}

void mainwindow::create_person_table(){
    int n=perlist.size();
    person_table->setRowCount(n);
    person_table->verticalHeader()->setVisible(false); //removes row index
    person_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){
        QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(perlist[i]->get_id()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,0, tmp);
        person_table->setItem(i,1, new QTableWidgetItem(perlist[i]->get_fname()));
        person_table->setItem(i,2, new QTableWidgetItem(perlist[i]->get_lname()));
        tmp = new QTableWidgetItem(QString::number(perlist[i]->get_numlend()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,3, tmp);

        QPushButton* btn= new QPushButton("delete"); //TODO Add icon as ctor argument
        connect(btn, SIGNAL(clicked()), this, SLOT(delete_person(perlist[i]->get_id())));
        person_table->setCellWidget(i,4,btn);
    }
}
