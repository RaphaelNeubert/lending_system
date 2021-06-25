#ifndef BOOK_H
#define BOOK_H

#include "medium.h"
#include <QString>

class book : public medium{
    private:
        QString author;
        QString publisher;
    
    public:
        book(QString title);
        book(QString title, QString author);
        book(QString title, QString author, QString publisher);
        book(QString title, QString author, QString publisher, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_author();
        QString get_publisher();
};


#endif

