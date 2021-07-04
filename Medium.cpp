#include "Medium.h"
#include <QString>

Medium::Medium(QString title, QString type){
    this->title=title;
    this->type=type;
}

Medium::Medium(QString title, QString type, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    title(title),type(type),id(id),lend(lend),person_id(person_id),lend_date(lend_date){}

QString Medium::get_title(){
    return title;
}

QString Medium::get_type(){
    return type;
}

bool Medium::get_lend(){
    return lend;
}

unsigned int Medium::get_id(){
    return id; 
}

unsigned int Medium::get_person_id(){
    return person_id;
}

QDate Medium::get_lend_date(){
    return lend_date;
}

void Medium::set_lend(bool lend){
    this->lend=lend;
}

void Medium::set_person_id(unsigned int person_id){
    this->person_id=person_id;
}

void Medium::set_lend_date(QDate lend_date){
    this->lend_date=lend_date;
}
