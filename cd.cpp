#include "cd.h"
#include "medium.h"


cd::cd(QString title, QString artist, QString producer, unsigned int id, bool lend, unsigned int person_id,
        QDate lend_date) :  medium(title,QString("cd"),id,lend,person_id,lend_date){
    this->artist=artist; 
    this->producer=producer;
}


QString cd::get_artist(){
    return artist;
}

QString cd::get_producer(){
    return producer;
}
