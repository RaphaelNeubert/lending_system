#include "PersonDialog.h"
#include "ui_PersonDialog.h"


PersonDialog::PersonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PersonDialog){
    ui->setupUi(this);
}

PersonDialog::~PersonDialog(){
    delete ui;
}

QString PersonDialog::get_fname(){
    return ui->input_fname->text();
}

QString PersonDialog::get_lname(){
    return ui->input_lname->text();
}
