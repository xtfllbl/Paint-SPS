#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Help)
{
    m_ui->setupUi(this);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

Help::~Help()
{
    delete m_ui;
}

void Help::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
