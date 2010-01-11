#ifndef HELP_H
#define HELP_H

#include <QtGui/QDialog>
#include "ui_help.h"

namespace Ui {
    class Help;
}

class Help : public QDialog {
    Q_OBJECT
public:
    Help(QWidget *parent = 0);
    ~Help();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Help *m_ui;
};

#endif // HELP_H
