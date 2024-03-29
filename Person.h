#ifndef PERSON_h
#define PERSON_h
#include <QString>

class Person{
    private:
        QString fname;
        QString lname;
        unsigned int id;
        unsigned int numlend;

    public:
        Person(QString fname, QString lname, unsigned int id, unsigned int numlend);
        QString get_fname();
        QString get_lname();
        unsigned int get_id();
        unsigned int get_numlend();
        //increases numlend by one
        void inc_numlend();
        //decreases numlend by one
        void dec_numlend();
};


#endif
