#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H

#include <QList>
#include <QTableWidgetItem>
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
        void write_medium();    //saves mediums from QList into file
        void write_person();    //saves persons from QList into file

        //gives save access to lists
        QList<person*> const& get_perlist() const;
        QList<medium*> const& get_medlist() const;

        void add_person(QString fname, QString lname); //adds person to perlist
        void add_book(QString title, QString author, QString publisher); //adds book to medlist
        void add_cd(QString title, QString artist, QString producer); //adds cd to medlist
        bool delete_person(unsigned int id);       //deletes person from perlist
        bool delete_medium(unsigned int id);       //deletes medium from perlist

        //change lend status
        void set_lend_true(const QList<unsigned int> &ids, unsigned int person_id);
        void set_lend_false(const QList<unsigned int> &ids);

        //checks if person exists
        bool check_person(unsigned int id);
};


#endif
