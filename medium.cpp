#include "medium.h"
#include <QString>

medium::medium(QString name, QString type){
    this->name=name;
    this->type=type;
}

QString medium::getName(){
    return name;
}

QString medium::getType(){
    return type;
}
