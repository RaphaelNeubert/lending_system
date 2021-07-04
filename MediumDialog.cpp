#include "MediumDialog.h"
#include <QDebug>


MediumDialog::MediumDialog(QWidget *parent) : QDialog(parent){
    ui->setupUi(this);
    //connect QComboBox using lambda
    connect(ui->type_select, QOverload<int>::of(&QComboBox::activated),
            [=](int index){ switch_type(index); });
}

MediumDialog::~MediumDialog(){
    delete ui;
}

void MediumDialog::switch_type(int index){
    //Book
    if (index == 0){
        ui->label_typ1->setText("Autor");
        ui->label_typ2->setText("Verlag");
    }
    //CD
    else{
        ui->label_typ1->setText("Künstler");
        ui->label_typ2->setText("Produzent");
    }
}


QString MediumDialog::get_title(){
    return ui->input_title->text();
}
QString MediumDialog::get_type(){
    return ui->type_select->currentIndex() == 0? "book": "cd";
}
QString MediumDialog::get_type_field1(){
    return ui->input_type1->text();
}
QString MediumDialog::get_type_field2(){
    return ui->input_type2->text();
}
