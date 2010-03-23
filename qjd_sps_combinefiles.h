#ifndef COMBINEFILES_H
#define COMBINEFILES_H

#include <QtGui/QDialog>
#include <ui_qjd_sps_combinefiles.h>
#include <QStringListModel>


namespace Ui {
    class CombineFiles;
}

class qjdCombineFiles : public QDialog {
    Q_OBJECT
public:
    explicit qjdCombineFiles(QWidget *parent = 0);
    virtual ~qjdCombineFiles();
    Ui::CombineFiles *m_ui;
    void reset();       // 合并结束后清空

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
