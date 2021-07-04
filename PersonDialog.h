#ifndef PERSON_DIALOG
#define PERSON_DIALOG

#include <QDialog>
#include "ui_PersonDialog.h"

namespace Ui{
    class PersonDialog;
}

class PersonDialog : public QDialog{
    Q_OBJECT
    private:
        Ui::PersonDialog *ui;
    public:
        explicit PersonDialog(QWidget* parent=nullptr);
        ~PersonDialog();

        QString get_fname();
        QString get_lname();
};


#endif
