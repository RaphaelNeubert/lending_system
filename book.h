#ifndef BOOK_H
#define BOOK_H

#include "medium.h"
#include <QString>

class book : public medium{
    private:
        QString author;
    
    public:
        book(QString name);
        book(QString name, QString author);
        book(QString name, QString author, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_author();
};


#endif

