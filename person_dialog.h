#ifndef PERSON_DIALOG
#define PERSON_DIALOG

#include <QDialog>
#include "ui_person_dialog.h"

class person_dialog : public QDialog, public Ui::Dialog{
    Q_OBJECT
    private:
//Ui::person_dialog *ui;
    public:
        person_dialog(QWidget* parent=nullptr);
        ~person_dialog();
};


#endif
