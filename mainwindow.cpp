#include "mainwindow.h"
#include "lending_system.h"
#include "book.h"
#include "cd.h"
#include "person_dialog.h"
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>


mainwindow::mainwindow(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);

    lend.read_person();     //from file to QList
    lend.read_medium();

    create_person_table();
    //switch table connects on radio state change
    connect(radio_book, &QRadioButton::toggled, this, &mainwindow::create_medium_table);
    connect(radio_lend_true, &QRadioButton::toggled, this, &mainwindow::create_lend_table);
    radio_book->setChecked(true);
    radio_lend_true->setChecked(true);
    connect(lend_button, &QPushButton::clicked, this, &mainwindow::change_lend_status);
    connect(add_person_btn, &QPushButton::clicked, this, &mainwindow::add_person);
}

mainwindow::~mainwindow(){
    lend.write_person();    //from QList to file
    lend.write_medium();
}

void mainwindow::create_person_table(){
    const QList<person*> plist=lend.get_perlist();
    int n=plist.size();
    person_table->setRowCount(n);
    person_table->verticalHeader()->setVisible(false); //removes row index
    person_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){                    //create rows
        //id
        QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(plist[i]->get_id()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,0, tmp);
        //first name
        person_table->setItem(i,1, new QTableWidgetItem(plist[i]->get_fname()));
        //second name
        person_table->setItem(i,2, new QTableWidgetItem(plist[i]->get_lname()));
        //amount on lended mediums
        tmp = new QTableWidgetItem(QString::number(plist[i]->get_numlend()));
        tmp->setTextAlignment(Qt::AlignCenter);
        person_table->setItem(i,3, tmp);
        //button to delete the person
        QPushButton* btn= new QPushButton("Löschen"); //OPTIONAL TODO Add icon as ctor argument
        //connect buttons using lambda
        connect(btn, &QPushButton::clicked, this, [this,i,plist]() { lend.delete_person(plist[i]->get_id()); });
        person_table->setCellWidget(i,4,btn);
    }
}

void mainwindow::create_medium_table(){
    const QList<medium*> mlist = lend.get_medlist();
    int n=mlist.size();
    int count=0;
    QStringList colNames;
    //deletes table contents
    medium_table->setRowCount(0);
    if (radio_book->isChecked()) colNames<<"ID"<<"Titel"<<"Autor"<<"Verlag"<<"";
    else colNames<<"ID"<<"Titel"<<"Artist"<<"Producer"<<"";
    medium_table->setColumnCount(5);
    medium_table->setHorizontalHeaderLabels(colNames);
    medium_table->verticalHeader()->setVisible(false); //removes row index
    medium_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing
    for (int i=0; i<n; i++){
        if (mlist[i]->get_type() == "book" && radio_book->isChecked()){
            medium_table->insertRow(medium_table->rowCount()); //Append row
            //id
            QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            medium_table->setItem(i,0, tmp);
            //title
            medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            medium_table->setItem(count,2, new QTableWidgetItem(((book*)mlist[i])->get_author()));
            //publisher
            medium_table->setItem(count,3, new QTableWidgetItem(((book*)mlist[i])->get_publisher()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { lend.delete_medium(mlist[i]->get_id()); });
            medium_table->setCellWidget(count,4,btn);
            count++;
        }
        else if (mlist[i]->get_type() == "cd" && radio_cd->isChecked()){
            medium_table->insertRow(medium_table->rowCount()); //Append row
            //id
            QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            medium_table->setItem(count,0, tmp);
            //title
            medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            medium_table->setItem(count,2, new QTableWidgetItem(((cd*)mlist[i])->get_artist()));
            //publisher
            medium_table->setItem(count,3, new QTableWidgetItem(((cd*)mlist[i])->get_producer()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("delete"); //OPTIONAL TODO Add icon as ctor argument
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { lend.delete_medium(mlist[i]->get_id()); });
            medium_table->setCellWidget(count,4,btn);
            count++;
        }
    }
}

void mainwindow::create_lend_table(){
    const QList<medium*> vlist = lend.get_medlist();
    int n=vlist.size();
    int count=0;
    QStringList colNames;
    struct checkbox_t checkbox_struct;

    //deletes table contents
    lend_table->setRowCount(0);
    //deletes checkbox_list contents
    checkbox_list.clear();

    if (radio_lend_true->isChecked()){
        colNames<<""<<"ID"<<"Art"<<"Titel"<<"verliehen an Person"<<"verleih Datum";
        lend_table->setColumnCount(6); 
        lend_button->setText("Zurück geben");
    }
    else{
        colNames<<""<<"ID"<<"Art"<<"Titel";
        lend_table->setColumnCount(4); 
        lend_button->setText("Verleihen");
    }
    lend_table->setHorizontalHeaderLabels(colNames);
    lend_table->verticalHeader()->setVisible(false); //removes row index
    lend_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){
        if (radio_lend_true->isChecked() && vlist[i]->get_lend()){
            lend_table->insertRow(lend_table->rowCount()); //Append row

            //checkbox
            QTableWidgetItem* tmp = new QTableWidgetItem();
            lend_table->setItem(count,0,tmp);
            tmp->setCheckState(Qt::Unchecked);
            //used to access checkbox states later on
            checkbox_struct.id = vlist[i]->get_id();
            checkbox_struct.checkbox = tmp;
            checkbox_list.append(checkbox_struct);

            //qDebug()<<checkbox_list[count].id;
            //qDebug()<<checkbox_list[count].checkbox->checkState();

            //id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            lend_table->setItem(count,1, tmp);
            //type
            lend_table->setItem(count,2, new QTableWidgetItem(vlist[i]->get_type()=="book"?"Buch":"CD"));
            //title
            lend_table->setItem(count,3, new QTableWidgetItem(vlist[i]->get_title()));
            //person id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_person_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            lend_table->setItem(count,4, tmp);
            //date
            lend_table->setItem(count,5, new QTableWidgetItem(vlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))));
            count++;
        }
        else if (!radio_lend_true->isChecked() && !vlist[i]->get_lend()){
            lend_table->insertRow(lend_table->rowCount()); //Append row
            //checkbox
            QTableWidgetItem* tmp = new QTableWidgetItem();
            lend_table->setItem(count,0,tmp);
            tmp->setCheckState(Qt::Unchecked);
            //used to access checkbox states later on
            checkbox_struct.id = vlist[i]->get_id();
            checkbox_struct.checkbox = tmp;
            checkbox_list.append(checkbox_struct);
            //id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            lend_table->setItem(count,1, tmp);
            //type
            lend_table->setItem(count,2, new QTableWidgetItem(vlist[i]->get_type()=="book"?"Buch":"CD"));
            //title
            lend_table->setItem(count,3, new QTableWidgetItem(vlist[i]->get_title()));
            count++;
        }
    }
}

void mainwindow::change_lend_status(){
    QList<unsigned int> ids;
    for (int i=0; i<checkbox_list.size(); i++){
       if (checkbox_list[i].checkbox->checkState() == Qt::Checked){
           ids.append(checkbox_list[i].id);
       }
    }
    if (radio_lend_true->isChecked()){
        lend.set_lend_false(ids);
        //refresh tables
        create_lend_table();
        create_person_table();
    }
    else {
        int person_id = QInputDialog::getInt(this,"Person ID", "An welche Person sollen die Medien verliehen werden? (ID)",0,1);
        if (!lend.check_person(person_id)){
            QString msg="Die Person mit der ID "+QString::number(person_id)+" konnte nicht gefunden werden.";
            QMessageBox::warning(this,"Person nicht gefunden!", msg); 
            //Optional TODO add person button
            return;
        }
        lend.set_lend_true(ids, person_id);
        //refresh tables
        create_lend_table();
        create_person_table();
    }
}

void mainwindow::add_person(){
    person_dialog pd;
    pd.exec();
}



