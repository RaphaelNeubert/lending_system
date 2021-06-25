#include <QString>
#include "book.h"

book::book(QString title) : medium(title, QString("book")){
    //this->author="";
}

book::book(QString title, QString author) : medium(title, QString("book")){
    this->author=author;
}

book::book(QString title, QString author, QString publisher) : medium(title, QString("book")){
    this->author=author;
    this->publisher=publisher;

}

book::book(QString title, QString author, QString publisher, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    medium(title, QString("book"),id,lend,person_id,lend_date){
    this->author=author;
    this->publisher=publisher;
}

QString book::get_author(){
    return author;
}

QString book::get_publisher(){
    return publisher;
}

