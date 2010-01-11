#ifndef OPENFILE_H
#define OPENFILE_H

#include <QtGui/QWidget>
#include <QFile>
#include "ui_openfile.h"

namespace Ui {
    class OpenFile;
}

class OpenFile : public QWidget {
    Q_OBJECT
    //  Q_DISABLE_COPY(OpenFile)
public:
    explicit OpenFile(QWidget *parent = 0);
    virtual ~OpenFile();

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
