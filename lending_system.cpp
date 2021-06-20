#include "lending_system.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

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
        QStringList fields = line.split(",");

    }
}
