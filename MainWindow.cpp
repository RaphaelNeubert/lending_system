#include "MainWindow.h"
#include "LendingSystem.h"
#include "Book.h"
#include "Cd.h"
#include "PersonDialog.h"
#include "MediumDialog.h"
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>


MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    create_person_table();
    //switch table connects on radio state change
    connect(ui->radio_book, &QRadioButton::toggled, this, &MainWindow::create_medium_table);
    connect(ui->radio_lend_true, &QRadioButton::toggled, this, &MainWindow::create_lend_table);
    ui->radio_book->setChecked(true);
    ui->radio_lend_true->setChecked(true);
    connect(ui->lend_button, &QPushButton::clicked, this, &MainWindow::change_lend_status);
    connect(ui->add_person_btn, &QPushButton::clicked, this, &MainWindow::add_person);
    connect(ui->add_medium_btn, &QPushButton::clicked, this, &MainWindow::add_medium);
}

MainWindow::~MainWindow(){
}

void MainWindow::create_person_table(){
    const QList<Person*> plist=lend.get_perlist();
    int n=plist.size();
    ui->person_table->setRowCount(n);
    ui->person_table->verticalHeader()->setVisible(false); //removes row index
    ui->person_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){                    //create rows
        //id
        QTableWidgetItem* tmp = new QTableWidgetItem(QString::number(plist[i]->get_id()));
        tmp->setTextAlignment(Qt::AlignCenter);
        ui->person_table->setItem(i,0, tmp);
        //first name
        ui->person_table->setItem(i,1, new QTableWidgetItem(plist[i]->get_fname()));
        //second name
        ui->person_table->setItem(i,2, new QTableWidgetItem(plist[i]->get_lname()));
        //amount on lended mediums
        tmp = new QTableWidgetItem(QString::number(plist[i]->get_numlend()));
        tmp->setTextAlignment(Qt::AlignCenter);
        ui->person_table->setItem(i,3, tmp);
        //button to delete the person
        QPushButton* btn= new QPushButton("Löschen"); //OPTIONAL TODO Add icon as ctor argument
        //connect buttons using lambda
        connect(btn, &QPushButton::clicked, this, [this,i,plist]() { delete_person(plist[i]->get_id()); });
        ui->person_table->setCellWidget(i,4,btn);
    }
}

void MainWindow::create_medium_table(){
    const QList<Medium*> mlist = lend.get_medlist();
    int n=mlist.size();
    int count=0;
    QStringList colNames;
    QTableWidgetItem* tmp;
    //deletes table contents
    ui->medium_table->setRowCount(0);
    if (ui->radio_book->isChecked()) colNames<<"ID"<<"Titel"<<"Autor"<<"Verlag"<<"";
    else colNames<<"ID"<<"Titel"<<"Künstler"<<"Produzent"<<"";
    ui->medium_table->setColumnCount(5);
    ui->medium_table->setHorizontalHeaderLabels(colNames);
    ui->medium_table->verticalHeader()->setVisible(false); //removes row index
    ui->medium_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing
    for (int i=0; i<n; i++){
        if (mlist[i]->get_type() == "book" && ui->radio_book->isChecked()){
            ui->medium_table->insertRow(ui->medium_table->rowCount()); //Append row
            //id
            tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            ui->medium_table->setItem(count,0, tmp);
            //title
            ui->medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            ui->medium_table->setItem(count,2, new QTableWidgetItem(((Book*)mlist[i])->get_author()));
            //publisher
            ui->medium_table->setItem(count,3, new QTableWidgetItem(((Book*)mlist[i])->get_publisher()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("Löschen");
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { delete_medium(mlist[i]->get_id()); });
            ui->medium_table->setCellWidget(count,4,btn);
            count++;
        }
        else if (mlist[i]->get_type() == "cd" && ui->radio_cd->isChecked()){
            ui->medium_table->insertRow(ui->medium_table->rowCount()); //Append row
            //id
            tmp = new QTableWidgetItem(QString::number(mlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            ui->medium_table->setItem(count,0, tmp);
            //title
            ui->medium_table->setItem(count,1, new QTableWidgetItem(mlist[i]->get_title()));
            //author
            ui->medium_table->setItem(count,2, new QTableWidgetItem(((Cd*)mlist[i])->get_artist()));
            //publisher
            ui->medium_table->setItem(count,3, new QTableWidgetItem(((Cd*)mlist[i])->get_producer()));
            //button to delete the book 
            QPushButton* btn= new QPushButton("Löschen");
            //connect buttons using lambda
            connect(btn, &QPushButton::clicked, this, [this,i,mlist]() { delete_medium(mlist[i]->get_id()); });
            ui->medium_table->setCellWidget(count,4,btn);
            count++;
        }
    }
}

void MainWindow::create_lend_table(){
    const QList<Medium*> vlist = lend.get_medlist();
    int n=vlist.size();
    int count=0;
    QStringList colNames;
    struct checkbox_t checkbox_struct;

    //deletes table contents
    ui->lend_table->setRowCount(0);
    //deletes checkbox_list contents
    checkbox_list.clear();

    if (ui->radio_lend_true->isChecked()){
        colNames<<""<<"ID"<<"Art"<<"Titel"<<"verliehen an Person"<<"verleih Datum";
        ui->lend_table->setColumnCount(6); 
        ui->lend_button->setText("Zurück geben");
    }
    else{
        colNames<<""<<"ID"<<"Art"<<"Titel";
        ui->lend_table->setColumnCount(4); 
        ui->lend_button->setText("Verleihen");
    }
    ui->lend_table->setHorizontalHeaderLabels(colNames);
    ui->lend_table->verticalHeader()->setVisible(false); //removes row index
    ui->lend_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //disable editing

    for (int i=0; i<n; i++){
        if (ui->radio_lend_true->isChecked() && vlist[i]->get_lend()){
            ui->lend_table->insertRow(ui->lend_table->rowCount()); //Append row

            //checkbox
            QTableWidgetItem* tmp = new QTableWidgetItem();
            ui->lend_table->setItem(count,0,tmp);
            tmp->setCheckState(Qt::Unchecked);
            //used to access checkbox states later on
            checkbox_struct.id = vlist[i]->get_id();
            checkbox_struct.checkbox = tmp;
            checkbox_list.append(checkbox_struct);

            //id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            ui->lend_table->setItem(count,1, tmp);
            //type
            ui->lend_table->setItem(count,2, new QTableWidgetItem(vlist[i]->get_type()=="book"?"Buch":"CD"));
            //title
            ui->lend_table->setItem(count,3, new QTableWidgetItem(vlist[i]->get_title()));
            //person id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_person_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            ui->lend_table->setItem(count,4, tmp);
            //date
            ui->lend_table->setItem(count,5, new QTableWidgetItem(vlist[i]->get_lend_date().toString(QString("dd.MM.yyyy"))));
            count++;
        }
        else if (!ui->radio_lend_true->isChecked() && !vlist[i]->get_lend()){
            ui->lend_table->insertRow(ui->lend_table->rowCount()); //Append row
            //checkbox
            QTableWidgetItem* tmp = new QTableWidgetItem();
            ui->lend_table->setItem(count,0,tmp);
            tmp->setCheckState(Qt::Unchecked);
            //used to access checkbox states later on
            checkbox_struct.id = vlist[i]->get_id();
            checkbox_struct.checkbox = tmp;
            checkbox_list.append(checkbox_struct);
            //id
            tmp = new QTableWidgetItem(QString::number(vlist[i]->get_id()));
            tmp->setTextAlignment(Qt::AlignCenter);
            ui->lend_table->setItem(count,1, tmp);
            //type
            ui->lend_table->setItem(count,2, new QTableWidgetItem(vlist[i]->get_type()=="book"?"Buch":"CD"));
            //title
            ui->lend_table->setItem(count,3, new QTableWidgetItem(vlist[i]->get_title()));
            count++;
        }
    }
}

void MainWindow::change_lend_status(){
    QList<unsigned int> ids;
    for (int i=0; i<checkbox_list.size(); i++){
       if (checkbox_list[i].checkbox->checkState() == Qt::Checked){
           ids.append(checkbox_list[i].id);
       }
    }
    if (ui->radio_lend_true->isChecked()){
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

void MainWindow::add_person(){
    PersonDialog pd;
    QString fname;
    QString lname;

    //executes person dialog window
    if (pd.exec() == QDialog::Accepted){
        fname = pd.get_fname();
        lname = pd.get_lname();
    while(lname.length() == 0){
        QMessageBox::warning(this,"Fehler", "Das Feld \"Nachname\" darf nicht leer sein.");
        if (pd.exec() == QDialog::Accepted){
            fname = pd.get_fname();
            lname = pd.get_lname();
        }
        else{
            return;
        }
    }
        lend.add_person(fname,lname);

        create_person_table();
    }
}

void MainWindow::delete_person(unsigned int id){
    if (!lend.delete_person(id)){
        QMessageBox::warning(this,"Fehler", "Personen können nicht gelöcht werden solange sie noch Medien\
                                                Ausgeliehen haben.");
        return;
    }
    create_person_table();
}

void MainWindow::delete_medium(unsigned int id){
    if (!lend.delete_medium(id)){
        QMessageBox::warning(this,"Fehler", "Medien die noch verliehen sind können nicht gelöcht werden");
        return;
    }
    create_medium_table();
}

void MainWindow::add_medium(){
    MediumDialog md;
    QString title;
    QString type;
    QString field1;
    QString field2;

    //executes person dialog window
    if (md.exec() == QDialog::Accepted){
        title = md.get_title();
        while(title.length() == 0){
            QMessageBox::warning(this,"Fehler", "Das Feld \"Titel\" darf nicht leer sein.");
            if (md.exec() == QDialog::Accepted){
                title = md.get_title();
            }
            else{
                return;
            }
        }
        type = md.get_type();
        field1 = md.get_type_field1();
        field2 = md.get_type_field2();

        if (type == "book"){
            lend.add_book(title, field1, field2);
        }
        else{
            lend.add_cd(title, field1, field2);
        }
            create_medium_table();
    }
}
