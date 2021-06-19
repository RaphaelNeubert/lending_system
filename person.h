#ifndef PERSON_h
#define PERSON_h
#include <QString>

class person{
    private:
        unsigned int id;
        QString fname;
        QString lname;
        unsigned int numlend;

    public:
        person(QString lname);
        person(QString fname, QString lname);
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
