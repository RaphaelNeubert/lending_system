#include "medium.h"
#include <QString>

medium::medium(QString name, QString type){
    this->name=name;
    this->type=type;
}

medium::medium(QString name, QString type, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    name(name),type(type),id(id),lend(lend),person_id(person_id),lend_date(lend_date){}

QString medium::get_name(){
    return name;
}

QString medium::get_type(){
    return type;
}

bool medium::get_lend(){
    return lend;
}

unsigned int medium::get_id(){
    return id; 
}

unsigned int medium::get_person_id(){
    return person_id;
}

QDate medium::get_lend_date(){
    return lend_date;
}

void medium::set_lend(bool lend){
    this->lend=lend;
}
