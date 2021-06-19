#include "medium.h"
#include <QString>

medium::medium(QString name, QString type){
    this->name=name;
    this->type=type;
}

QString medium::get_name(){
    return name;
}

QString medium::get_type(){
    return type;
}
