#include <QString>
#include "book.h"

book::book(QString name) : medium(name, QString("book")){
    this->author="";
}

book::book(QString name, QString author) : medium(name, QString("book")){
    this->author=author;
}

book::book(QString name, QString author, unsigned int id, bool lend) : medium(name, QString("book"),id,lend){
    this->author=author;
}

