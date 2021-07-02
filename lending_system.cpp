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

//returns false in case person is still lending mediums
bool lending_system::delete_person(unsigned int id){
    for (int i=0; i<perlist.size(); i++){
        if (id == perlist[i]->get_id()){
            if (perlist[i]->get_numlend() == 0){
                delete perlist[i];
                perlist.removeAt(i);
                return true;
            }
        }
    }
    return false;
}

void lending_system::delete_medium(unsigned int id){
    qDebug()<<id;
}

void lending_system::set_lend_true(const QList<unsigned int> &ids, unsigned int person_id){
    int count=0;
    int j;

    for (j=0; j<perlist.size(); j++){
        if (perlist[j]->get_id() == person_id) break;
    }
    for (int i=0; i<medlist.size(); i++){
        if (medlist[i]->get_id() == ids[count]){
            medlist[i]->set_lend(true);
            perlist[j]->inc_numlend();
            medlist[i]->set_person_id(person_id);
            medlist[i]->set_lend_date(QDate::currentDate());
            count++;
        }
    }
}
void lending_system::set_lend_false(const QList<unsigned int> &ids){
    int count=0;
    int j;

    for (int i=0; i<medlist.size(); i++){
        if (medlist[i]->get_id() == ids[count]){
            medlist[i]->set_lend(false);
            //gets person object index once
            if (count == 0){
                for (j=0; j<perlist.size(); j++){
                    if (perlist[j]->get_id() == medlist[i]->get_person_id()) break;
                }
            }
            perlist[j]->dec_numlend();
            medlist[i]->set_person_id(0);
            //nulldate
            medlist[i]->set_lend_date(QDate());
            count++;
        }
    }
}


bool lending_system::check_person(unsigned int id){
    for (int i=0; i<perlist.size(); i++){
        if (perlist[i]->get_id() == id) return true;
    }
    return false;
}


void lending_system::add_person(QString fname, QString lname){
    unsigned int maxId=0;
    unsigned int tmpId=0;
    person* newperson;

    //get max occuring id 
    for (int i=0; i<perlist.size(); i++){
        tmpId=perlist[i]->get_id();
        maxId = maxId<tmpId?tmpId:maxId;
    }
    //Id of new person is highest + 1
    maxId++;
    
    newperson = new person(fname, lname, maxId, 0);
    perlist.append(newperson);
}
