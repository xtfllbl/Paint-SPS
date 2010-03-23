#include "qjd_sps_openfile.h"
#include "ui_qjd_sps_openfile.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

qjdOpenFile::qjdOpenFile(QWidget *parent) :
        QWidget(parent),
        m_ui(new Ui::OpenFile)
{
    m_ui->setupUi(this);
    whiteString="";
    filedialog=new QFileDialog();
    m_ui->groupUnit->hide();
    connect(m_ui->btnSFile,SIGNAL(clicked()),this,SLOT(btnSPress()));
    connect(m_ui->btnRFile,SIGNAL(clicked()),this,SLOT(btnRPress()));
    connect(m_ui->btnXFile,SIGNAL(clicked()),this,SLOT(btnXPress()));
    connect(m_ui->btnOK,SIGNAL(clicked()),this,SLOT(btnOKPress()));
    layout()->setSizeConstraint(QLayout::SetFixedSize);     //设一下layout，窗口伸缩轻松自如
}

qjdOpenFile::~qjdOpenFile()
{
    delete m_ui;
}

void qjdOpenFile::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void qjdOpenFile::btnSPress()
{
    SfileName = filedialog->getOpenFileName(this,tr("Open S File"),"/home/student/Source/SPS",tr("SPS S Files (*.s *.S *.sps *.SPS)"));
    m_ui->lineSFile->setText(SfileName);

    QString str1 = SfileName;
    if(str1.contains(".S", Qt::CaseSensitive))    // returns true
    {
        str1.replace(QString(".S"), QString(".R"));
        m_ui->lineRFile->setText(str1);
        str1.replace(QString(".R"), QString(".X"));
        m_ui->lineXFile->setText(str1);
    }
    else if(str1.contains(".s", Qt::CaseSensitive))
    {
        str1.replace(QString(".s"), QString(".r"));
        m_ui->lineRFile->setText(str1);
        str1.replace(QString(".r"), QString(".x"));
        m_ui->lineXFile->setText(str1);
    }
    else if(str1.contains(".SPS", Qt::CaseSensitive))
    {
        str1.replace(QString(".SPS"), QString(".RPS"));
        m_ui->lineRFile->setText(str1);
        str1.replace(QString(".RPS"), QString(".XPS"));
        m_ui->lineXFile->setText(str1);
    }
    else if(str1.contains(".sps", Qt::CaseSensitive))
    {
        str1.replace(QString(".sps"), QString(".rps"));
        m_ui->lineRFile->setText(str1);
        str1.replace(QString(".rps"), QString(".xps"));
        m_ui->lineXFile->setText(str1);
    }

}

void qjdOpenFile::btnRPress()
{
    RfileName = QFileDialog::getOpenFileName(this,tr("Open R File"),"/home/student/Source",tr("SPS R Files (*.r *.R *.rps *.RPS)"));
    m_ui->lineRFile->setText(RfileName);

    QString str2 = RfileName;
    if(str2.contains(".R", Qt::CaseSensitive))    // returns true
    {
        str2.replace(QString(".R"), QString(".S"));
        m_ui->lineSFile->setText(str2);
        str2.replace(QString(".S"), QString(".X"));
        m_ui->lineXFile->setText(str2);
    }
    else if(str2.contains(".r", Qt::CaseSensitive))
    {
        str2.replace(QString(".r"), QString(".s"));
        m_ui->lineSFile->setText(str2);
        str2.replace(QString(".s"), QString(".x"));
        m_ui->lineXFile->setText(str2);
    }
    else if(str2.contains(".RPS", Qt::CaseSensitive))
    {
        str2.replace(QString(".RPS"), QString(".SPS"));
        m_ui->lineSFile->setText(str2);
        str2.replace(QString(".SPS"), QString(".XPS"));
        m_ui->lineXFile->setText(str2);
    }
    else if(str2.contains(".rps", Qt::CaseSensitive))
    {
        str2.replace(QString(".rps"), QString(".sps"));
        m_ui->lineSFile->setText(str2);
        str2.replace(QString(".sps"), QString(".xps"));
        m_ui->lineXFile->setText(str2);
    }
}

void qjdOpenFile::btnXPress()
{
    XfileName = QFileDialog::getOpenFileName(this,tr("Open X File"),"/home/student/Source",tr("SPS S Files (*.x *.X *.xps *.XPS)"));
    m_ui->lineXFile->setText(XfileName);

    QString str3 = XfileName;
    if(str3.contains(".X", Qt::CaseSensitive))    // returns true
    {
        str3.replace(QString(".X"), QString(".S"));
        m_ui->lineSFile->setText(str3);
        str3.replace(QString(".S"), QString(".R"));
        m_ui->lineRFile->setText(str3);
    }
    else if(str3.contains(".x", Qt::CaseSensitive))
    {
        str3.replace(QString(".x"), QString(".s"));
        m_ui->lineSFile->setText(str3);
        str3.replace(QString(".s"), QString(".r"));
        m_ui->lineRFile->setText(str3);
    }
    else if(str3.contains(".XPS", Qt::CaseSensitive))
    {
        str3.replace(QString(".XPS"), QString(".SPS"));
        m_ui->lineSFile->setText(str3);
        str3.replace(QString(".SPS"), QString(".RPS"));
        m_ui->lineRFile->setText(str3);
    }
    else if(str3.contains(".sps", Qt::CaseSensitive))
    {
        str3.replace(QString(".xps"), QString(".sps"));
        m_ui->lineSFile->setText(str3);
        str3.replace(QString(".sps"), QString(".rps"));
        m_ui->lineRFile->setText(str3);
    }
}

void qjdOpenFile::btnOKPress()
{
    openSuccess=true;
    close();
}

void qjdOpenFile::on_pushButton_clicked()
{
    close();
}
