#ifndef MEDIUM_DIALOG
#define MEDIUM_DIALOG

#include <QDialog>
#include "ui_MediumDialog.h"

namespace Ui{
    class MediumDialog;
}

class MediumDialog : public QDialog{
    Q_OBJECT
    private:
        Ui::MediumDialog* ui;
        void switch_type(int index);
    public:
        MediumDialog(QWidget* parent=nullptr);
        ~MediumDialog();
        QString get_title();
        QString get_type();
        QString get_type_field1();
        QString get_type_field2();
};


#endif
