#include "combinefiles.h"
#include "ui_combinefiles.h"
#include <QFileDialog>
#include <QDebug>
#include <QList>
#include <QMessageBox>


CombineFiles::CombineFiles(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::CombineFiles)
{
    m_ui->setupUi(this);
    model=new QStringListModel(this);
    combineSuccess=false;

}

CombineFiles::~CombineFiles()
{
    delete m_ui;
}

void CombineFiles::changeEvent(QEvent *e)
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


void CombineFiles::on_btnCombineFile_clicked()
{
    combineFileName = QFileDialog::getSaveFileName(this,tr("Open Combine File"),"/home/student/Source",
                                                   tr("S Files (*.s *.S *.sps *.SPS);;R Files (*.r *.R *.rps *.RPS);;X Files(*.x *.X *.xps *.XPS)"));
    m_ui->lineCombineFile->setText(combineFileName);
}

void CombineFiles::on_btnOK_clicked()
{
    model->setStringList(fileNames);
    //qDebug()<<model->stringList();
    fileNames=model->stringList();
    fileNumbers=fileNames.count();
    if(fileNumbers>1 && m_ui->lineCombineFile->text()!="")
    {
        combineSuccess=true;

        QMessageBox::information(this,tr("Succes"),tr("Congraduation! The file has been combined in: ")+m_ui->lineCombineFile->text()
                                 +tr("\nIf need more services, please click the Reset button to continue!"));
    }
    else if(fileNumbers==1)
    {
        combineSuccess=false;
        QMessageBox::warning(this,tr("Be Careful"),tr("Combine file need 2 or more files!!"));
    }
    else
    {
        combineSuccess=false;
        QMessageBox::critical(this,tr("Failed"),tr("Are you kidding me !?"));
    }

}

void CombineFiles::on_btnCancel_clicked()
{
    close();
}


void CombineFiles::on_btnDel_clicked()
{
    fileNames.removeAt(m_ui->fileList->currentIndex().row());
    model->removeRows(m_ui->fileList->currentIndex().row(), 1);
}

void CombineFiles::on_btnAdd_clicked()
{
    fileTempNames = QFileDialog::getOpenFileNames(this,tr("Open File"),"/home/student/Source",
                                                  tr("S Files (*.s *.S *.sps *.SPS);;R Files (*.r *.R *.rps *.RPS);;X Files(*.x *.X *.xps *.XPS)"));
    fileNames=fileNames+fileTempNames;
    fileNames.removeDuplicates();       //去除相同字符窜
    model->setStringList(fileNames);
    m_ui->fileList->setModel(model);
    m_ui->fileList->setEditTriggers(QAbstractItemView::AnyKeyPressed
                                    | QAbstractItemView::DoubleClicked);


}

void CombineFiles::on_btnReset_clicked()
{
    fileNames=whiteList;
    m_ui->lineCombineFile->setText("");
    model->setStringList(fileNames);
    m_ui->fileList->setModel(model);
}
