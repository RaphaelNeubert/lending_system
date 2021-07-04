#ifndef BOOK_H
#define BOOK_H

#include "Medium.h"
#include <QString>

class Book : public Medium{
    private:
        QString author;
        QString publisher;
    
    public:
        Book(QString title);
        Book(QString title, QString author);
        Book(QString title, QString author, QString publisher);
        Book(QString title, QString author, QString publisher, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_author();
        QString get_publisher();
};


#endif

