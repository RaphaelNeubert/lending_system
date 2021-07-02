#include "person_dialog.h"
#include "ui_person_dialog.h"


person_dialog::person_dialog(QWidget *parent) : QDialog(parent){
    setupUi(this);
}

person_dialog::~person_dialog(){
}

QString person_dialog::get_fname(){
    return input_fname->text();
}

QString person_dialog::get_lname(){
    return input_lname->text();
}
