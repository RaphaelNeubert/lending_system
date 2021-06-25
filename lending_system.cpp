#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QDate>
#include <iostream>
#include "lending_system.h"
#include "book.h"
#include "person.h"

lending_system::lending_system(){
}

void lending_system::read_medium(){
    QFile f("medium.csv");
    if(!f.open(QIODevice::ReadOnly)){
//TODO error message
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if(fields[1]=="book"){
            book* b = new book(fields[0],fields[2],fields[3],fields[4].toUInt(),fields[5].toInt(),fields[6].toUInt(),
                    QDate::fromString(fields[7]));
            medlist.append((medium*)b);

            /* 
            std::cout<<medlist[0]->get_name().toStdString()<<std::endl;
            std::cout<<((book*)medlist[0])->get_author().toStdString()<<std::endl;
            std::cout<<medlist[0]->get_lend()<<std::endl;
            */
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
        line = medlist[i]->get_name()+';'+medlist[i]->get_type()+';'+QString::number(medlist[i]->get_id())+';'
            +QString::number(medlist[i]->get_lend())+';'+QString::number(medlist[i]->get_person_id())+';'
            +medlist[i]->get_lend_date().toString()+'\n';
        f.write(line.toUtf8());
    }
    f.close();

}
