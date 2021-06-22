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
    QFile f("medien.csv");
    if(!f.open(QIODevice::ReadOnly)){
//TODO error message
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if(fields[1]=="book"){
            book* b = new book(fields[0],fields[2],fields[3].toUInt(),fields[4].toInt(),fields[5].toUInt(),
                    QDate::fromString(fields[6]));
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
        std::cout<<perlist[0]->get_fname().toStdString()<<std::endl;
        std::cout<<perlist[0]->get_fname().toStdString()<<std::endl;
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
    std::cout<<"test"<<std::endl;
    //f.seek(0);
    for (int i=0; i<perlist.size(); i++){
        line=perlist[i]->get_fname()+";"+perlist[i]->get_lname()+';'+QString::number(perlist[i]->get_id())
                                    +';'+QString::number(perlist[i]->get_numlend())+'\n';
        f.write(line.toUtf8());
    }
    f.close();

}
