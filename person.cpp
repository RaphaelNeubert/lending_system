#include "person.h"
#include <QString>

person::person(QString lname){
    this->lname=lname;
    numlend=0;
}
person::person(QString fname, QString lname){
    this->lname=lname;
    this->fname=fname;
    numlend=0;
}

QString person::get_fname(){
    return fname;
}
QString person::get_lname(){
    return lname;
}
unsigned int person::get_id(){
    return id;
}
unsigned int person::get_numlend(){
    return numlend;
}

void person::inc_numlend(){
    numlend++;
}
void person::dec_numlend(){
    numlend--;
}


