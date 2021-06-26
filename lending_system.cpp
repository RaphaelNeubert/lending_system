#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QDate>
#include <iostream>
#include "lending_system.h"
#include "book.h"
#include "person.h"
#include "cd.h"

lending_system::lending_system(){
}

void lending_system::read_medium(){
    QFile f("medium.csv");
    if (!f.open(QIODevice::ReadOnly)){
        //TODO error message
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (fields[0]=="book"){
            //creates new book instance on heap
            book* b = new book(fields[1],fields[2],fields[3],fields[4].toUInt(),fields[5].toInt(),
                               fields[6].toUInt(),QDate::fromString(fields[7], QString("dd.MM.yyyy")));
            //adds book to list
            medlist.append((medium*)b);
        }
        else if (fields[0]=="cd"){
            cd* c = new cd(fields[1],fields[2],fields[3],fields[4].toUInt(),fields[5].toInt(),fields[6].toUInt(),
                           QDate::fromString(fields[7]));
            medlist.append((medium*)c);

        }
    }
    f.close();
}

void lending_system::read_person(){
    QFile f("person.csv");
    if (!f.open(QIODevice::ReadOnly)){
        //TODO error message
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        person* p = new person(fields[0], fields[1], fields[2].toUInt(), fields[3].toUInt());
        perlist.append(p);
    }
    f.close();
}

void lending_system::write_person(){
    QFile f("person.csv");
    QString line;

    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        //TODO error message
        return;
    }
    for (int i=0; i<perlist.size(); i++){
        line = perlist[i]->get_fname()+";"+perlist[i]->get_lname()+';'+QString::number(perlist[i]->get_id())
                                      +';'+QString::number(perlist[i]->get_numlend())+'\n';
        f.write(line.toUtf8());
    }
    f.close();
}

void lending_system::write_medium(){
    QFile f("medium.csv");
    QString line;

    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        //TODO error message
        return;
    }
    for (int i=0; i<medlist.size(); i++){
        //creates one line for the csv file
        if (medlist[i]->get_type()=="book"){
            line = medlist[i]->get_type()+';'+medlist[i]->get_title()+';'+((book*)medlist[i])->get_author()+';'
                +((book*)medlist[i])->get_publisher()+';'+QString::number(medlist[i]->get_id())+';'
                +QString::number(medlist[i]->get_lend())+';'+QString::number(medlist[i]->get_person_id())+';'
                +medlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))+'\n';
        }

        else if (medlist[i]->get_type()=="cd"){
            line = medlist[i]->get_type()+';'+medlist[i]->get_title()+';'+((cd*)medlist[i])->get_artist()+';'
                +((cd*)medlist[i])->get_producer()+';'+QString::number(medlist[i]->get_id())+';'
                +QString::number(medlist[i]->get_lend())+';'+QString::number(medlist[i]->get_person_id())+';'
                +medlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))+'\n';
        }
        f.write(line.toUtf8()); //ASCCI
    }
    f.close();
}


QList<person*> const& lending_system::get_perlist() const{
    return perlist;
}

QList<medium*> const& lending_system::get_medlist() const{
    return medlist;
}

void lending_system::delete_person(unsigned int id){
    qDebug()<<id;
}

void lending_system::delete_medium(unsigned int id){
    qDebug()<<id;
}
