#ifndef OPENFILE_H
#define OPENFILE_H

#include <QtGui/QWidget>
#include <QFile>
#include "ui_qjd_sps_openfile.h"
#include <QFileDialog>

namespace Ui {
    class OpenFile;
}

class qjdOpenFile : public QWidget
{
    Q_OBJECT
public:
    explicit qjdOpenFile(QWidget *parent = 0);
    virtual ~qjdOpenFile();

    QFileDialog *filedialog;
    QString SfileName;
    QString XfileName;
    QString RfileName;
    bool openSuccess;

    Ui::OpenFile *m_ui;

protected:
    virtual void changeEvent(QEvent *e);

private:
    QString whiteString;
private slots:
    void on_pushButton_clicked();
    void btnSPress();
    void btnRPress();
    void btnXPress();
    void btnOKPress();

};

#endif // OPENFILE_H
