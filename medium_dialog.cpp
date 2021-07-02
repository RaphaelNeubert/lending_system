#include "medium_dialog.h"
#include <QDebug>


medium_dialog::medium_dialog(QWidget *parent) : QDialog(parent){
    setupUi(this);
    //connect QComboBox using lambda
    connect(type_select, QOverload<int>::of(&QComboBox::activated),
            [=](int index){ switch_type(index); });
}

medium_dialog::~medium_dialog(){
}

void medium_dialog::switch_type(int index){
    //Book
    if (index == 0){
        label_typ1->setText("Autor");
        label_typ2->setText("Verlag");
    }
    //CD
    else{
        label_typ1->setText("Künstler");
        label_typ2->setText("Produzent");
    }
}


QString medium_dialog::get_title(){
    return input_title->text();
}
QString medium_dialog::get_type(){
    return type_select->currentIndex() == 0? "book": "cd";
}
QString medium_dialog::get_type_field1(){
    return input_type1->text();
}
QString medium_dialog::get_type_field2(){
    return input_type2->text();
}
