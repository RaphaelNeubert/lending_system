#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QDate>
#include <iostream>
#include "LendingSystem.h"
#include "Book.h"
#include "Person.h"
#include "Cd.h"

LendingSystem::LendingSystem(){
}

void LendingSystem::read_medium(){
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
            Book* b = new Book(fields[1],fields[2],fields[3],fields[4].toUInt(),fields[5].toInt(),
                               fields[6].toUInt(),QDate::fromString(fields[7], QString("dd.MM.yyyy")));
            //adds book to list
            medlist.append((Medium*)b);
        }
        else if (fields[0]=="cd"){
            Cd* c = new Cd(fields[1],fields[2],fields[3],fields[4].toUInt(),fields[5].toInt(),fields[6].toUInt(),
                           QDate::fromString(fields[7]));
            medlist.append((Medium*)c);

        }
    }
    f.close();
}

void LendingSystem::read_person(){
    QFile f("person.csv");
    if (!f.open(QIODevice::ReadOnly)){
        //TODO error message
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        Person* p = new Person(fields[0], fields[1], fields[2].toUInt(), fields[3].toUInt());
        perlist.append(p);
    }
    f.close();
}

void LendingSystem::write_person(){
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

void LendingSystem::write_medium(){
    QFile f("medium.csv");
    QString line;

    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        //TODO error message
        return;
    }
    for (int i=0; i<medlist.size(); i++){
        //creates one line for the csv file
        if (medlist[i]->get_type()=="book"){
            line = medlist[i]->get_type()+';'+medlist[i]->get_title()+';'+((Book*)medlist[i])->get_author()+';'
                +((Book*)medlist[i])->get_publisher()+';'+QString::number(medlist[i]->get_id())+';'
                +QString::number(medlist[i]->get_lend())+';'+QString::number(medlist[i]->get_person_id())+';'
                +medlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))+'\n';
        }

        else if (medlist[i]->get_type()=="cd"){
            line = medlist[i]->get_type()+';'+medlist[i]->get_title()+';'+((Cd*)medlist[i])->get_artist()+';'
                +((Cd*)medlist[i])->get_producer()+';'+QString::number(medlist[i]->get_id())+';'
                +QString::number(medlist[i]->get_lend())+';'+QString::number(medlist[i]->get_person_id())+';'
                +medlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))+'\n';
        }
        f.write(line.toUtf8()); //ASCCI
    }
    f.close();
}


QList<Person*> const& LendingSystem::get_perlist() const{
    return perlist;
}

QList<Medium*> const& LendingSystem::get_medlist() const{
    return medlist;
}

//returns false in case person is still lending mediums
bool LendingSystem::delete_person(unsigned int id){
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

//returns false in case medium is still lended
bool LendingSystem::delete_medium(unsigned int id){
    for (int i=0; i<medlist.size(); i++){
        if (id == medlist[i]->get_id()){
            if (!medlist[i]->get_lend()){
                delete medlist[i];
                medlist.removeAt(i);
                return true;
            }
        }
    }
    return false;
}

void LendingSystem::set_lend_true(const QList<unsigned int> &ids, unsigned int person_id){
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
void LendingSystem::set_lend_false(const QList<unsigned int> &ids){
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


bool LendingSystem::check_person(unsigned int id){
    for (int i=0; i<perlist.size(); i++){
        if (perlist[i]->get_id() == id) return true;
    }
    return false;
}


void LendingSystem::add_person(QString fname, QString lname){
    unsigned int maxId=0;
    unsigned int tmpId=0;
    Person* newperson;

    //get max occuring id 
    for (int i=0; i<perlist.size(); i++){
        tmpId=perlist[i]->get_id();
        maxId = maxId<tmpId?tmpId:maxId;
    }
    //Id of new person is highest + 1
    maxId++;
    
    newperson = new Person(fname, lname, maxId, 0);
    perlist.append(newperson);
}

void LendingSystem::add_book(QString title, QString author, QString publisher){
    unsigned int maxId=0;
    unsigned int tmpId=0;
    Book* newbook;

    //get max occuring id 
    for (int i=0; i<medlist.size(); i++){
        tmpId=medlist[i]->get_id();
        maxId = maxId<tmpId?tmpId:maxId;
    }
    //new ID
    maxId++;

    newbook = new Book(title, author, publisher, maxId, false, 0, QDate());
    medlist.append((Medium*)newbook);
}
void LendingSystem::add_cd(QString title, QString artist, QString producer){
    unsigned int maxId=0;
    unsigned int tmpId=0;
    Cd* newcd;

    //get max occuring id 
    for (int i=0; i<medlist.size(); i++){
        tmpId=medlist[i]->get_id();
        maxId = maxId<tmpId?tmpId:maxId;
    }
    //new ID
    maxId++;

    newcd = new Cd(title, artist, producer, maxId, false, 0, QDate());
    medlist.append((Medium*)newcd);
}
