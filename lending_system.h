#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H

#include <QList>
#include "medium.h"
#include "person.h"

class lending_system{
    protected:
        QList<medium*> medlist; //saves all medium objects
        QList<person*> perlist; //saves all person objects
    
        void read_medium();     //loads mediums from file into QList
        void read_person();     //loads persons from file into QList
        void write_medium();    //saves mediums from QList into file
        void write_person();    //saves persons from QList into file
    public:
        lending_system();
    protected slots:
        void delete_person(unsigned int id);       //deletes person from list
};


#endif
