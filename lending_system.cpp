#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QDate>
#include <iostream>
#include "lending_system.h"
#include "book.h"

lending_system::lending_system(){
}

void lending_system::read_medium(){
    QFile f("medien.csv");
    if(!f.open(QIODevice::ReadOnly)){
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if(fields[2]=="book"){
            book m1(fields[0],fields[2],fields[3].toUInt(),fields[4].toInt(),fields[5].toUInt(),
                    QDate::fromString(fields[6]));
            std::cout<<m1.get_name().toStdString()<<std::endl;
            std::cout<<m1.get_author().toStdString()<<std::endl;
            std::cout<<m1.get_lend()<<std::endl;
            medlist.append((medium*)&m1);
        }
    }
}
