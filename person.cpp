#include "person.h"
#include <QString>

person::person(QString fname, QString lname, unsigned int id, unsigned int numlend) : fname(fname), lname(lname),
                                                                                      id(id), numlend(numlend) {
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


