#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include <QLinearGradient>
#include <QMouseEvent>
#include <stdio.h>
#include <QPointF>
#include <QDebug>
#include <QScrollArea>
#include <QLabel>
#include <QFile>
#include "mywidget.h"
#include "openfile.h"
#include "combinefiles.h"
#include "option.h"
#include "help.h"
#include <QProgressBar>

namespace Ui
{
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    QVector<QVector<int> > testAB;


    bool openS;

    // QRect rubberBandRect;
    int i;
    int j;
    int k;

    int countCMP;
    int countFold;

    char *EstS;
    char *NorS;
    char *EstR;
    char *NorR;

    char *Slinename;
    char *Spointnumber;
    char *Xlinename;
    char *Xpointnumber;
    char *Xreceivelinename;
    char *XFromreceiver;
    char *XToreceiver;

    char *Rlinename;
    char *Rpointnumber;

private:
    int HBarValue;
    int VBarValue;
    int HBarMax;
    int VBarMax;
    QFile fp;
    QFile fb;
    QFile fx;
    QFile f1;
    QFile f2;
    QFile f3;
    QFile fAfterCombine;

    QScrollArea *scrollarea;
    QScrollBar *VScrollBar;
    QScrollBar *HScrollBar;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *statusLabel1;
    QLabel *statusLabel2;
    QLabel *statusLabel3;
    QLabel *statusLabel4;
    QLabel *statusLabel5;
    QProgressBar *pBar;

    QPoint point;

    int finalLine;
    int file2FinalLine;
    bool isWindowsEnter;
    bool file2IsWindowsEnter;
    int plusEnter;

    MyWidget *my;
    OpenFile *openfile;
    Option *option;
    CombineFiles *combinefiles;
    Help *help;

    QColor shotColor;
    QColor receiveColor;
    QColor CMPColor;
    double shotValue;
    double receiveValue;
    double CMPValue;

    bool flagSLAdd;
    bool flagSLMul;
    bool flagSLBox;

    bool flagRLAdd;
    bool flagRLMul;
    bool flagRLBox;

    bool flagCMPAdd;
    bool flagCMPMul;
    bool flagCMPBox;

    int SLSize;
    int RLSize;
    int CMPSize;

private slots:
    void on_actionHelp_triggered();
    void on_actionOption_triggered();
    void on_actionCMP_triggered();
    void on_actionReceivePointLine_triggered();
    void on_actionShotPointLine_triggered();
    void on_actionFoldNumbers_triggered();
    void on_actionReceiveLine_triggered();
    void on_actionShotLine_triggered();
    void on_actionClose_triggered();
    void on_actionAbout_QT_triggered();
    void on_actionCombineFiles_triggered();
    void on_actionRelation_triggered();
    void on_actionReset_triggered();
    void on_actionOpen_triggered();
    void setData();
    void mouseMoveEvent ( QMouseEvent *);
    void mouseReleaseEvent ( QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void mousePressEvent( QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void paintCor(QPainter *painter);
    void resizeEvent (QResizeEvent * );
    void setFileLocation();
    void frontOpen();
    void combineFilesIntoOne();
    void applyChange();
    void setProgressBar(int);
    void setProgressBarValue(int);
    void hideBar();
    
    void setShotLineColorMain(QColor,double);
    void setShotLineShapeMain(int,int);
    void setReceiveLineColorMain(QColor,double);
    void setReceiveLineShapeMain(int,int);
    void setCMPColorMain(QColor,double);
    void setCMPShapeMain(int,int);

};


#endif // MAINWINDOW_H
