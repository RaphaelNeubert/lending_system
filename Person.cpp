#include "Person.h"
#include <QString>

Person::Person(QString fname, QString lname, unsigned int id, unsigned int numlend) : fname(fname), lname(lname),
                                                                                      id(id), numlend(numlend) {
}

QString Person::get_fname(){
    return fname;
}
QString Person::get_lname(){
    return lname;
}
unsigned int Person::get_id(){
    return id;
}
unsigned int Person::get_numlend(){
    return numlend;
}

void Person::inc_numlend(){
    numlend++;
}
void Person::dec_numlend(){
    numlend--;
}


