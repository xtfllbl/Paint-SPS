#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QLinearGradient>
#include <QMouseEvent>
#include <stdio.h>
#include <QPointF>
#include <QDebug>
#include <QScrollArea>
#include <QLinearGradient>
#include "qjd_sps_option.h"


typedef qreal* SFile;

class qjdWidget : public QWidget
{
    Q_OBJECT

public:
    qjdWidget(QWidget *parent = 0);
    //~MyWidget();

    bool rubberBandIsShown;
    bool mouseRightZoom;
    bool zoomInAvailable;
    bool foldModeON;
    bool cmpON;

    bool shotPointLineON;
    bool receivePointLineON;
    bool alreadySetShotData;
    bool alreadySetFoldDataZheng;
    bool alreadySetFoldDataXie;
    bool alreadySetCMP;
    QRect rubberBandRect;

    double maxE;
    double minE;
    double maxN;
    double minN;
    double maxDrawE;
    double minDrawE;
    double maxDrawN;
    double minDrawN;
    double wid;
    double hei;
    double drawWid;
    double drawHei;

    int minSN;
    int maxSN;
    int minRN;
    int maxRN;
    double minTE;
    double maxTE;
    double minTN;
    double maxTN;
    double maxDrawTE;
    double minDrawTE;
    double maxDrawTN;
    double minDrawTN;
    double widT;
    double heiT;
    double drawWidT;
    double drawHeiT;


    QVector<qreal> KOFR;
    double KofR;
    bool flagXie;
    bool flagZheng;
    double radian;
    double sinA;
    double cosA;

    /*-----------S File-----------*/
    QVector<qreal> estS;
    QVector<qreal> norS;
    QVector<qreal> slinename;
    QVector<qreal> spointnumber;

    int SNumber;
    /*-----------R File-----------*/
    QVector<qreal> estR;
    QVector<qreal> norR;
    QVector<qreal> rlinename;
    QVector<qreal> rpointnumber;

    int RNumber;
    /*-----------X File-----------*/
    QVector<qreal> xlinename;
    QVector<qreal> xpointnumber;
    QVector<qreal> xreceivelinename;
    QVector<qreal> xfromreceiver;
    QVector<qreal> xtoreceiver;

    int XNumber;
    /*-----------mywidget File-----------*/  
    QVector<qreal> estDrawS;
    QVector<qreal> norDrawS;
    QVector<qreal> estDrawR;
    QVector<qreal> norDrawR;

    QVector<qreal> estR1;
    QVector<qreal> estR2;
    QVector<qreal> norR1;
    QVector<qreal> norR2;
    QVector<QList<qreal> > estS1;
    QVector<QList<qreal> > norS1;
    QVector<QList<qreal> > estS2;
    QVector<QList<qreal> > norS2;

    QVector<qreal> estS0;
    QVector<qreal> norS0;
    QVector<qreal> estR0;
    QVector<qreal> norR0;

    int line;

    QVector<qreal> estSTrans;
    QVector<qreal> norSTrans;
    QVector<qreal> estRTrans;
    QVector<qreal> norRTrans;

    /*---------Transformation-------*/
    qreal estK;
    qreal norK;

    QVector<qreal> estKK;
    QVector<qreal> norKK;

    QVector<qreal> estK0;
    QVector<qreal> norK0;

    qreal estTK;
    qreal norTK;
    qreal estTTK;
    qreal norTTK;

    double mr;
    double miss;
    qreal MrRight;
    qreal MissRight;

    qreal rectWidth;
    qreal rectHeight;

    qreal HIncrease;
    qreal VIncrease;
    qreal HOldIncrease;
    qreal VOldIncrease;

    bool sON;
    bool rON;
    bool shotON;
    bool receiveON;
    int maxFold;
    int maxFoldT;
    qreal singleWid;
    qreal singleHei;
    QString singleWidView;
    QString singleHeiView;
    qreal singleWidT;
    qreal singleHeiT;
    QString singleWidTView;
    QString singleHeiTView;
    QVector<QVector<int> > boxXY;
    QVector<int> boxX;
    QVector<int> boxY;
    QVector<int> boxValue;

    QVector<QVector<int> > boxXYT;
    QVector<QVector<int> > boxXYTT;

    QVector<QRgb> colorTable;

    bool cmpIsChanged;
    bool foldIsChanged;
    QVector<qreal> ax;
    QVector<qreal> ay;
    QVector<qreal> bx;
    QVector<qreal> by;
    QVector<QVector<qreal> > checkA;

    bool zero;
    bool one;
    bool two;
    bool three;
    bool four;
    bool five;
    bool six;
    bool seven;

    QPoint zeroPoint;

public slots:
    void refreshPixmap();
    void decide();
    void updateRubberBandRegion();
    void paintFoldNumbers(QPainter *painter);
    void setFoldNumbers();
    void setFoldTransform();
    void setK();
    void axisTransform();
    void setShotPointLine();
    void setInterpolationTransform();
    void setAxisTransform();
    void setCMP();
    void setColorTable();

    // 更换颜色
    void setShotLineColor(QColor,double);
    void setReceiveLineColor(QColor,double);
    void setMouseClickedColor(QColor,double);
    void setMouseClickedSLColor(QColor,double);
    void setMouseClickedRLColor(QColor,double);
    void setShotLineConColor(QColor,double);
    void setReceiveLineConColor(QColor,double);
    void setCMPColor(QColor,double);

    // 更换形状
    void setShotLineShape(int,int);
    void setReceiveLineShape(int,int);
    void setMouseClickedShape(int,int);
    void setCMPShape(int,int);

    //设置CMP精度
    void setCMPAccuracy(int);
private:

    QPixmap pixmap;

    qreal ESTR;
    qreal NORR;
    qreal ESTS;
    qreal NORS;

    qreal RLINENAME;
    qreal RPOINTNUMBER;
    qreal XFROMRECEIVER;
    qreal XTORECEIVER;
    qreal XLINENAME;
    qreal XPOINTNUMBER;
    qreal XRECEIVELINENAME;
    qreal SLINENAME;
    qreal SPOINTNUMBER;

    qreal ESTSP;
    qreal NORSP;
    qreal ESTST;
    qreal NORST;
    qreal gridX;
    qreal gridY;
    qreal gridXT;
    qreal gridYT;

    QVector<qreal> axisXX;
    QVector<qreal> axisYY;
    qreal axisX;
    qreal axisY;
    qreal axisXT;
    qreal axisYT;


    int eastBoxNumber;
    int northBoxNumber;

    int eastBoxNumberT;
    int northBoxNumberT;

    QVector<QVector<int> > boxAB;
    QVector<QVector<int> > boxAY;

    QVector<QVector<int> > boxCD;
    QVector<QVector<int> > boxCY;

    qreal eastS;
    qreal northS;
    qreal eastR;
    qreal northR;
    qreal returnValue;
    int pixelValue;
    int pixelValueT;

    qreal unitX;
    qreal unitY;
    qreal unitXT;
    qreal unitYT;

    QColor shotLineColor;
    QColor receiveLineColor;
    QColor shotLineConColor;
    QColor receiveLineConColor;
    QColor mouseClickedSLColor;
    QColor mouseClickedRLColor;
    QColor mouseClickedColor;
    QColor CMP_Color;

    double shotLineValue;
    double receiveLineValue;
    double shotLineConValue;
    double receiveLineConValue;
    double mouseClickedSLValue;
    double mouseClickedRLValue;
    double mouseClickedValue;
    double CMP_Value;

    bool flagShotLineAdd;
    bool flagShotLineMul;
    bool flagShotLineBox;
    bool flagReceiveLineAdd;
    bool flagReceiveLineMul;
    bool flagReceiveLineBox;
    bool flagMouseClickedAdd;
    bool flagMouseClickedMul;
    bool flagMouseClickedBox;
    bool flagCMPAdd;
    bool flagCMPMul;
    bool flagCMPBox;

    int shotLineSize;
    int receiveLineSize;
    int mouseClickedSize;
    int CMP_Size;

    int skipNum;
signals:
    void signalMaxSet(int max);
    void signalValueSet(int value);
    void signalHideBar();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void resizeEvent ( QResizeEvent * );
    void paintMrRight(QPainter *painter);
    void paintSfileRelation(QPainter *painter);
    void paintRfileRelation(QPainter *painter);
    void paintShotLine(QPainter *painter);
    void paintReceiveLine(QPainter *painter);
    void paintCMP(QPainter *painter);
    void paintShotPointLine(QPainter *painter);
    void paintReceivePointLine(QPainter *painter);
    void setInterpolation();

};

#endif // MYWIDGET_H
