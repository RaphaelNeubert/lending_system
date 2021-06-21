#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H

#include <QList>
#include "medium.h"
#include "person.h"

class lending_system{
    private:
        QList<medium*> medlist; //saves all medium objects
        QList<person*> perlist; //saves all person objects
    public:
        lending_system();
        void read_medium();     //loads mediums from file into QList
        void read_person();     //loads persons from file into QList
};


#endif
