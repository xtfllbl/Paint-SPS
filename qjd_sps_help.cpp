#include "qjd_sps_help.h"
#include "ui_qjd_sps_help.h"

qjdHelp::qjdHelp(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Help)
{
    m_ui->setupUi(this);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

qjdHelp::~qjdHelp()
{
    delete m_ui;
}

void qjdHelp::changeEvent(QEvent *e)
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
