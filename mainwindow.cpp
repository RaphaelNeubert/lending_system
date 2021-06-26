#include "mainwindow.h"
#include "lending_system.h"
#include "book.h"
#include "cd.h"
#include <QDebug>
#include <QPushButton>


mainwindow::mainwindow(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);

    lend.read_person();     //from file to QList
    lend.read_medium();

    create_person_table();
    radio_cd->setChecked(true);
    create_medium_table();

    connect(radio_book, &QRadioButton::toggled, this, &mainwindow::create_medium_table);
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

    for (int i=0; i<n; i++){                    //create rows
        //id
        QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(plist[i]->get_id()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,0, tmp);
        //first name
        person_table->setItem(i,1, new QTableWidgetItem(plist[i]->get_fname()));
        //second name
        person_table->setItem(i,2, new QTableWidgetItem(plist[i]->get_lname()));
        //amount on lended mediums
        tmp = new QTableWidgetItem(QString::number(plist[i]->get_numlend()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,3, tmp);
        //button to delete the person
        QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
        //connect buttons using lambda
        connect(btn, &QPushButton::clicked, this, [this,i,plist]() { lend.delete_person(plist[i]->get_id()); });
        person_table->setCellWidget(i,4,btn);
    }
}

void mainwindow::create_medium_table(){
    const QList<medium*> mlist = lend.get_medlist();
    int n=mlist.size();
    int count=0;
    QStringList colNames;
    //deletes table contents
    medium_table->setRowCount(0);
    if (radio_book->isChecked()) colNames<<"ID"<<"Titel"<<"Autor"<<"Verlag"<<"";
    else colNames<<"ID"<<"Titel"<<"Artist"<<"Producer"<<"";
    medium_table->setColumnCount(5);
    medium_table->setHorizontalHeaderLabels(colNames);
    medium_table->verticalHeader()->setVisible(false); //removes row index
    medium_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing
    for (int i=0; i<n; i++){
        if (mlist[i]->get_type() == "book" && radio_book->isChecked()){
            medium_table->insertRow(medium_table->rowCount()); //Append row
            //id
            QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            medium_table->setItem(i,0, tmp);
            //title
            medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            medium_table->setItem(count,2, new QTableWidgetItem(((book*)mlist[i])->get_author()));
            //publisher
            medium_table->setItem(count,3, new QTableWidgetItem(((book*)mlist[i])->get_publisher()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { lend.delete_medium(mlist[i]->get_id()); });
            medium_table->setCellWidget(count,4,btn);
            count++;
        }
        else if (mlist[i]->get_type() == "cd" && radio_cd->isChecked()){
            medium_table->insertRow(medium_table->rowCount()); //Append row
            //id
            QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            medium_table->setItem(count,0, tmp);
            //title
            medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            medium_table->setItem(count,2, new QTableWidgetItem(((cd*)mlist[i])->get_artist()));
            //publisher
            medium_table->setItem(count,3, new QTableWidgetItem(((cd*)mlist[i])->get_producer()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { lend.delete_medium(mlist[i]->get_id()); });
            medium_table->setCellWidget(count,4,btn);
            count++;
        }
    }
}

