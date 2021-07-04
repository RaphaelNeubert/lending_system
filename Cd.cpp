#include "Cd.h"
#include "Medium.h"


Cd::Cd(QString title, QString artist, QString producer, unsigned int id, bool lend, unsigned int person_id,
        QDate lend_date) :  Medium(title,QString("cd"),id,lend,person_id,lend_date){
    this->artist=artist; 
    this->producer=producer;
}


QString Cd::get_artist(){
    return artist;
}

QString Cd::get_producer(){
    return producer;
}
