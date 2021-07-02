#ifndef PERSON_DIALOG
#define PERSON_DIALOG

#include <QDialog>
#include "ui_person_dialog.h"

class person_dialog : public QDialog, public Ui::Dialog{
    Q_OBJECT
    private:
    public:
        person_dialog(QWidget* parent=nullptr);
        ~person_dialog();

        QString get_fname();
        QString get_lname();
};


#endif
