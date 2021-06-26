#include "mainwindow.h"
#include "lending_system.h"
#include <QDebug>
#include <QPushButton>


mainwindow::mainwindow(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);

    lend.read_person();     //from file to QList
    lend.read_medium();

    create_person_table();
}

mainwindow::~mainwindow(){
    lend.write_person();    //from QList to file
    lend.write_medium();
}

void mainwindow::create_person_table(){
    const QList<person*> plist=lend.get_perlist();
    int n=plist.size();
    person_table->setRowCount(n);
    person_table->verticalHeader()->setVisible(false); //removes row index
    person_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){
        QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(plist[i]->get_id()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,0, tmp);
        person_table->setItem(i,1, new QTableWidgetItem(plist[i]->get_fname()));
        person_table->setItem(i,2, new QTableWidgetItem(plist[i]->get_lname()));
        tmp = new QTableWidgetItem(QString::number(plist[i]->get_numlend()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,3, tmp);

        QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
        //connect buttons using lambda
        connect(btn, &QPushButton::clicked, this, [this,i,plist]() { lend.delete_person(plist[i]->get_id()); });
        person_table->setCellWidget(i,4,btn);
    }
}
