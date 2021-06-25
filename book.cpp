#include <QString>
#include "book.h"

book::book(QString name) : medium(name, QString("book")){
    //this->author="";
}

book::book(QString name, QString author) : medium(name, QString("book")){
    this->author=author;
    this->publisher=publisher;
}

book::book(QString name, QString author, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    medium(name, QString("book"),id,lend,person_id,lend_date){
    this->author=author;
    this->publisher=publisher;
}

QString book::get_author(){
    return author;
}

QString book::get_publisher(){
    return publisher;
}

