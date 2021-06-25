#include "medium.h"
#include <QString>

medium::medium(QString title, QString type){
    this->title=title;
    this->type=type;
}

medium::medium(QString title, QString type, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    title(title),type(type),id(id),lend(lend),person_id(person_id),lend_date(lend_date){}

QString medium::get_title(){
    return title;
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
