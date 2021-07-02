#ifndef MEDIUM_DIALOG
#define MEDIUM_DIALOG

#include <QDialog>
#include "ui_medium_dialog.h"

class medium_dialog : public QDialog, public Ui::Dialog2{
    Q_OBJECT
    private:
        void switch_type(int index);
    public:
        medium_dialog(QWidget* parent=nullptr);
        ~medium_dialog();
        QString get_title();
        QString get_type();
        QString get_type_field1();
        QString get_type_field2();
};


#endif
