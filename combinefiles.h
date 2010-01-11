#ifndef COMBINEFILES_H
#define COMBINEFILES_H

#include <QtGui/QDialog>
#include <ui_combinefiles.h>
#include <QStringListModel>


namespace Ui {
    class CombineFiles;
}

class CombineFiles : public QDialog {
    Q_OBJECT
    //  Q_DISABLE_COPY(CombineFiles)
public:
    explicit CombineFiles(QWidget *parent = 0);
    virtual ~CombineFiles();
    Ui::CombineFiles *m_ui;

    QString fileName1;
    QString fileName2;
    QString combineFileName;
    QStringList fileNames;
    QStringList fileTempNames;
    QStringList whiteList;
    bool combineSuccess;

    int fileNumbers;

protected:
    virtual void changeEvent(QEvent *e);

private:
    QStringListModel *model;

private slots:
    void on_btnReset_clicked();
    void on_btnAdd_clicked();
    void on_btnDel_clicked();
    void on_btnCancel_clicked();
    void on_btnOK_clicked();
    void on_btnCombineFile_clicked();

};

#endif // COMBINEFILES_H
