#include "medium.h"
#include <QString>

medium::medium(QString name, QString type){
    this->name=name;
    this->type=type;
}

medium::medium(QString name, QString type, unsigned int id, bool lend) : name(name),type(type),id(id),lend(lend){}

QString medium::get_name(){
    return name;
}

QString medium::get_type(){
    return type;
}

void medium::set_lend(bool lend){
    this->lend=lend;
}
