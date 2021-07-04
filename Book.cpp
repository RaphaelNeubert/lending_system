#include <QString>
#include "Book.h"

Book::Book(QString title) : Medium(title, QString("book")){
    //this->author="";
}

Book::Book(QString title, QString author) : Medium(title, QString("book")){
    this->author=author;
}

Book::Book(QString title, QString author, QString publisher) : Medium(title, QString("book")){
    this->author=author;
    this->publisher=publisher;

}

Book::Book(QString title, QString author, QString publisher, unsigned int id, bool lend, unsigned int person_id, QDate lend_date) :
    Medium(title, QString("book"),id,lend,person_id,lend_date){
    this->author=author;
    this->publisher=publisher;
}

QString Book::get_author(){
    return author;
}

QString Book::get_publisher(){
    return publisher;
}

