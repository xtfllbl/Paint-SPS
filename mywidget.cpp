#include "mywidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRubberBand>
#include <QtGui>
#include <math.h>
#define PAI 3.1415926


MyWidget::MyWidget(QWidget *)
{
    setPalette(Qt::white);
    sON=false;
    rON=false;
    foldModeON=false;
    singleWid=25;
    singleHei=100;
    singleWidT=40;
    singleHeiT=40;

    zero=0;
    one =1;
    two=0;
    three=0;
    four=0;
    five=0;
    six=0;
    seven=0;

    skipNum=0;
    flagXie=false;
    flagZheng=false;
    zeroPoint.setX(0);
    zeroPoint.setY(0);

     flagShotLineAdd=true;
     flagShotLineMul=false;
     flagShotLineBox=false;
     flagReceiveLineAdd=true;
     flagReceiveLineMul=false;
     flagReceiveLineBox=false;
     flagMouseClickedAdd=true;
     flagMouseClickedMul=false;
     flagMouseClickedBox=false;
     flagCMPAdd=true;
     flagCMPMul=false;
     flagCMPBox=false;

     shotLineSize=6;
     receiveLineSize=2;
     mouseClickedSize=6;
     CMP_Size=2;
}

void MyWidget::resizeEvent (QResizeEvent * )
{
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pixmap);

    if(shotON==true)
        paintShotLine(&painter);
    if(receiveON==true)
        paintReceiveLine(&painter);
    if(shotPointLineON==true)
        paintShotPointLine(&painter);
    if(receivePointLineON==true)
        paintReceivePointLine(&painter);

    if(rON==true)
    {
        paintRfileRelation(&painter);
        paintMrRight(&painter);
    }

    if(sON==true)
    {
        paintSfileRelation(&painter);
        paintMrRight(&painter);
    }

    if (rubberBandIsShown)
    {
        painter.setPen(Qt::magenta);
        painter.drawRect(rubberBandRect.normalized().adjusted(0, 0, -1, -1));
    }
}

void MyWidget::refreshPixmap()
{
    QTime time;
    pixmap = QPixmap(size());
    pixmap.fill(this, 0, 0);
    
    QPainter painter(&pixmap);
    painter.initFrom(this);

    if(foldModeON==true)
    {
        paintFoldNumbers(&painter);
    }
    if(cmpON==true)
    {
        paintCMP(&painter);
    }
    update();       //作为立即生效使用，不写的话只是不立即显示，拖动之后仍然正常显示
}

void MyWidget::paintMrRight(QPainter *painter)
{
    for(int a=0;a<SNumber;a++)
    {
        if(mr<estS[a]+50 && mr>estS[a]-50 && miss<norS[a]+50 && miss>norS[a]-50)
        {
            MrRight=(estS[a]-minDrawE)/drawWid*(width());
            MissRight=(norS[a]-minDrawN)/drawHei*(height());
            MissRight=height()-MissRight;
        }
    }
    for(int a=0;a<RNumber;a++)
    {
        if (mr<estR[a]+20 && mr>estR[a]-20 && miss<norR[a]+20 && miss>norR[a]-20)
        {
            MrRight=(estR[a]-minDrawE)/drawWid*(width());
            MissRight=(norR[a]-minDrawN)/drawHei*(height());
            MissRight=height()-MissRight;
        }        
    }
    
    painter->setPen(QPen(Qt::green,2));
    if(mouseClickedColor.isValid())
    {
        painter->setPen(QPen(mouseClickedColor,mouseClickedValue));
    }
    if(flagMouseClickedAdd==true)
    {
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight,(int)MrRight+mouseClickedSize,(int)MissRight);
        painter->drawLine((int)MrRight,(int)MissRight-mouseClickedSize,(int)MrRight,(int)MissRight+mouseClickedSize);
    }
    if(flagMouseClickedMul==true)
    {
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight+mouseClickedSize,(int)MrRight+mouseClickedSize,(int)MissRight-mouseClickedSize);
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight-mouseClickedSize,(int)MrRight+mouseClickedSize,(int)MissRight+mouseClickedSize);
    }
    if(flagMouseClickedBox==true)
    {
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight+mouseClickedSize,(int)MrRight+mouseClickedSize,(int)MissRight+mouseClickedSize);
        painter->drawLine((int)MrRight+mouseClickedSize,(int)MissRight-mouseClickedSize,(int)MrRight+mouseClickedSize,(int)MissRight+mouseClickedSize);
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight-mouseClickedSize,(int)MrRight+mouseClickedSize,(int)MissRight-mouseClickedSize);
        painter->drawLine((int)MrRight-mouseClickedSize,(int)MissRight+mouseClickedSize,(int)MrRight-mouseClickedSize,(int)MissRight-mouseClickedSize);
    }
}

void MyWidget::paintSfileRelation(QPainter *painter)
{
    
    painter->setPen(QPen(Qt::yellow,1));
    if(mouseClickedSLColor.isValid())
    {
        painter->setPen(QPen(mouseClickedSLColor,mouseClickedSLValue));
    }
    for(int a=0;a<SNumber;a++)
    {
        if(mr<estS[a]+50 && mr>estS[a]-50
           && miss<norS[a]+50 && miss>norS[a]-50)
        {
            SLINENAME=slinename[a];
            SPOINTNUMBER=spointnumber[a];
        }
    }
    
    for(int b=0;b<XNumber;b++)
    {
        if(SLINENAME==xlinename[b] && SPOINTNUMBER==xpointnumber[b])
        {
            XRECEIVELINENAME=xreceivelinename[b];
            XLINENAME=xlinename[b];
            XPOINTNUMBER=xpointnumber[b];
            XFROMRECEIVER=xfromreceiver[b];
            XTORECEIVER=xtoreceiver[b];
            
            for(int c=0;c<RNumber;c++)
            {
                if(XRECEIVELINENAME==rlinename[c] && XFROMRECEIVER==rpointnumber[c])
                {
                    int d=(int)(XTORECEIVER-XFROMRECEIVER);   //注意d少一个，循环要加上
                    for (int e=0;e<=d;e++)
                    {
                        ESTR=estDrawR[c+e];
                        NORR=norDrawR[c+e];
                        if(flagReceiveLineAdd==true)        //+
                        {
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR,(int)ESTR+receiveLineSize,(int)NORR);
                            painter->drawLine((int)ESTR,(int)NORR-receiveLineSize,(int)ESTR,(int)NORR+receiveLineSize);
                        }
                        if(flagReceiveLineMul==true)        //*
                        {
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR+receiveLineSize,(int)ESTR+receiveLineSize,(int)NORR-receiveLineSize);
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR-receiveLineSize,(int)ESTR+receiveLineSize,(int)NORR+receiveLineSize);
                        }
                        if(flagReceiveLineBox==true)        //方块
                        {
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR+receiveLineSize,(int)ESTR+receiveLineSize,(int)NORR+receiveLineSize);
                            painter->drawLine((int)ESTR+receiveLineSize,(int)NORR-receiveLineSize,(int)ESTR+receiveLineSize,(int)NORR+receiveLineSize);
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR-receiveLineSize,(int)ESTR+receiveLineSize,(int)NORR-receiveLineSize);
                            painter->drawLine((int)ESTR-receiveLineSize,(int)NORR-receiveLineSize,(int)ESTR-receiveLineSize,(int)NORR+receiveLineSize);
                        }
                    }
                }
            }
        }        
    }
}

void MyWidget::paintRfileRelation(QPainter *painter)
{
    painter->setPen(QPen(Qt::black,2));
    if(mouseClickedRLColor.isValid())
    {
        painter->setPen(QPen(mouseClickedRLColor,mouseClickedRLValue));
    }
    for(int a=0;a<RNumber;a++)
    {
        if(mr<estR[a]+20 && mr>estR[a]-20
           && miss<norR[a]+20 && miss>norR[a]-20)
        {
            RLINENAME=rlinename[a];
            RPOINTNUMBER=rpointnumber[a];
        }
    }
    
    for(int b=0;b<XNumber;b++)
    {
        if(RLINENAME==xreceivelinename[b] && RPOINTNUMBER<xtoreceiver[b] && RPOINTNUMBER>xfromreceiver[b])
        {
            XLINENAME=xlinename[b];
            XPOINTNUMBER=xpointnumber[b];
            
            for(int c=0;c<SNumber;c++)
            {
                if(XLINENAME==slinename[c] && XPOINTNUMBER==spointnumber[c])
                {
                    ESTS=estDrawS[c];
                    NORS=norDrawS[c];
                    
                    if(flagShotLineAdd==true)
                    {
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS,(int)ESTS+shotLineSize,(int)NORS);
                        painter->drawLine((int)ESTS,(int)NORS-shotLineSize,(int)ESTS,(int)NORS+shotLineSize);
                    }
                    if(flagShotLineMul==true)
                    {
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS+shotLineSize,(int)ESTS+shotLineSize,(int)NORS-shotLineSize);
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS-shotLineSize,(int)ESTS+shotLineSize,(int)NORS+shotLineSize);
                    }
                    if(flagShotLineBox==true)
                    {
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS+shotLineSize,(int)ESTS+shotLineSize,(int)NORS+shotLineSize);
                        painter->drawLine((int)ESTS+shotLineSize,(int)NORS-shotLineSize,(int)ESTS+shotLineSize,(int)NORS+shotLineSize);
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS-shotLineSize,(int)ESTS+shotLineSize,(int)NORS-shotLineSize);
                        painter->drawLine((int)ESTS-shotLineSize,(int)NORS-shotLineSize,(int)ESTS-shotLineSize,(int)NORS+shotLineSize);
                    }
                }
            }
        }
    }
}

void MyWidget::decide()
{
    for(int a=0;a<SNumber;a++)
    {
        if(mr<estS[a]+50 && mr>estS[a]-50 &&
           miss<norS[a]+50 && miss>norS[a]-50)
        {
            sON=true;
            rON=false;
        }
    }
    for(int b=0;b<RNumber;b++)
    {
        if(mr<estR[b]+20 && mr>estR[b]-20
           && miss<norR[b]+20 && miss>norR[b]-20)
        {
            sON=false;
            rON=true;
        }
    }
}

void MyWidget::updateRubberBandRegion()
{
    QRect rect = rubberBandRect.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);
    update(rect.left(), rect.top(), 1, rect.height());
    update(rect.left(), rect.bottom(), rect.width(), 1);
    update(rect.right(), rect.top(), 1, rect.height());
}

void MyWidget::paintShotLine(QPainter *painter)     //炮线
{
    painter->setPen(QPen(Qt::blue,1));
    if(shotLineColor.isValid())
    {
        painter->setPen(QPen(shotLineColor,shotLineValue));
    }
    for(int i=0;i<SNumber;i++)                              //画.S文件
    {
        estDrawS[i]=(estS[i]-minDrawE)/drawWid*(width());
        norDrawS[i]=(norS[i]-minDrawN)/drawHei*(height());
        norDrawS[i]=height()-norDrawS[i];

        if(flagShotLineAdd==true)
        {
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i],(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]);
            painter->drawLine((int)estDrawS[i],(int)norDrawS[i]-shotLineSize,(int)estDrawS[i],(int)norDrawS[i]+shotLineSize);
        }
        if(flagShotLineMul==true)
        {
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i]+shotLineSize,(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]-shotLineSize);
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i]-shotLineSize,(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]+shotLineSize);
        }
        if(flagShotLineBox==true)
        {
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i]+shotLineSize,(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]+shotLineSize);
            painter->drawLine((int)estDrawS[i]+shotLineSize,(int)norDrawS[i]+shotLineSize,(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]-shotLineSize);
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i]-shotLineSize,(int)estDrawS[i]+shotLineSize,(int)norDrawS[i]-shotLineSize);
            painter->drawLine((int)estDrawS[i]-shotLineSize,(int)norDrawS[i]-shotLineSize,(int)estDrawS[i]-shotLineSize,(int)norDrawS[i]+shotLineSize);
        }
    }
}

void MyWidget::paintReceiveLine(QPainter *painter)      //检波线
{
    painter->setPen(QPen(Qt::red,0.5,Qt::SolidLine,Qt::RoundCap));
    if(receiveLineColor.isValid())
    {
        painter->setPen(QPen(receiveLineColor,receiveLineValue));
    }
    for(int j=0;j<RNumber;j++)                              //画.R文件
    {
        estDrawR[j]=(estR[j]-minDrawE)/drawWid*(width());
        norDrawR[j]=(norR[j]-minDrawN)/drawHei*(height());
        norDrawR[j]=height()-norDrawR[j];

        if(flagReceiveLineAdd==true)
        {
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j],(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]);
            painter->drawLine((int)estDrawR[j],(int)norDrawR[j]-receiveLineSize,(int)estDrawR[j],(int)norDrawR[j]+receiveLineSize);
        }
        if(flagReceiveLineMul==true)
        {
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]+receiveLineSize,(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]-receiveLineSize);
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]-receiveLineSize,(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]+receiveLineSize);
        }
        if(flagReceiveLineBox==true)
        {
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]+receiveLineSize,(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]+receiveLineSize);
            painter->drawLine((int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]-receiveLineSize,(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]+receiveLineSize);
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]-receiveLineSize,(int)estDrawR[j]+receiveLineSize,(int)norDrawR[j]-receiveLineSize);
            painter->drawLine((int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]-receiveLineSize,(int)estDrawR[j]-receiveLineSize,(int)norDrawR[j]+receiveLineSize);
        }
    }
}

void MyWidget::setCMP()  //设置覆盖次数像素点    //一次性设置
{
    qDebug()<<"setCMP";
    axisXX.clear();
    axisYY.clear();

    emit signalMaxSet(SNumber-1);
    for(int a=0;a<SNumber;a++)
    {
        SLINENAME=slinename[a];
        SPOINTNUMBER=spointnumber[a];
        ESTSP=estS[a];
        NORSP=norS[a];
        for(int b=0;b<XNumber;b++)
        {
            if(SLINENAME==xlinename[b] && SPOINTNUMBER==xpointnumber[b])
            {
                XRECEIVELINENAME=xreceivelinename[b];
                XFROMRECEIVER=xfromreceiver[b];
                XTORECEIVER=xtoreceiver[b];

                for(int c=0;c<RNumber;c++)
                {
                    if(XRECEIVELINENAME==rlinename[c] && XFROMRECEIVER==rpointnumber[c])
                    {
                        int d=(int)(XTORECEIVER-XFROMRECEIVER);   //注意d少一个，循环要加上
                        for (int e=0;e<=d;e++)
                        {
                            qreal ab=estR[c+e];
                            qreal cd=norR[c+e];
                            axisXX<<(ab+ESTSP)/2;                  //计算出来的大地坐标的中点坐标值
                            axisYY<<(cd+NORSP)/2;

                            e+=skipNum;       //省略点的控制,也可做成控制
                        }
                    }
                }
            }
        }
        emit signalValueSet(a);
    }
    emit signalHideBar();
}

void MyWidget::paintCMP(QPainter *painter)  //画覆盖次数像素点
{
    painter->setPen(QPen(Qt::green,0.1));
    if(CMP_Color.isValid())
    {
        painter->setPen(QPen(CMP_Color,CMP_Value));
    }

    if(cmpIsChanged==true)
    {
        cmpIsChanged=false;      //cmp画完，一定要设false
        ax.clear();
        ay.clear();
        for(int i=0;i<axisXX.size();i++)
        {
            ax<<(axisXX[i]-minDrawE)/drawWid*(width());                      //原始数据加上增加量，可以空出左边和下边
            ay<<(axisYY[i]-minDrawN)/drawHei*(height());                   //paintHei是数据长度减去数据长度*0.1的产物，用于空出右边和上边
            ay[i]=height()-ay[i];

            if(flagCMPAdd==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i],(int)ax[i]+CMP_Size,(int)ay[i]);
                painter->drawLine((int)ax[i],(int)ay[i]-CMP_Size,(int)ax[i],(int)ay[i]+CMP_Size);
            }
            if(flagCMPMul==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
            }
            if(flagCMPBox==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
                painter->drawLine((int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size);
            }
        }
    }
    if(cmpIsChanged==false)
    {
        for(int i=0;i<axisXX.size();i++)
        {
            if(flagCMPAdd==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i],(int)ax[i]+CMP_Size,(int)ay[i]);
                painter->drawLine((int)ax[i],(int)ay[i]-CMP_Size,(int)ax[i],(int)ay[i]+CMP_Size);
            }
            if(flagCMPMul==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
            }
            if(flagCMPBox==true)
            {
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
                painter->drawLine((int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]+CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]+CMP_Size,(int)ay[i]-CMP_Size);
                painter->drawLine((int)ax[i]-CMP_Size,(int)ay[i]-CMP_Size,(int)ax[i]-CMP_Size,(int)ay[i]+CMP_Size);
            }
        }
    }
}


void MyWidget::setFoldNumbers()
{
    singleWidView=QString::number(singleWid);
    singleHeiView=QString::number(singleHei);

    maxFold=0;
    gridX=0;
    gridY=0;

    eastBoxNumber=(int)(drawWid/singleWid);       //总共有多少网格
    northBoxNumber=(int)(drawHei/singleHei);

    boxAB.clear();
    boxAB.resize(eastBoxNumber);    //初始化动态二维数组
    for(int i=0;i<eastBoxNumber;i++)
        boxAB[i].resize(northBoxNumber);

    for(int a=0;a<SNumber;a++)
    {
        SLINENAME=slinename[a];
        SPOINTNUMBER=spointnumber[a];
        ESTSP=estS[a];
        NORSP=norS[a];

        for(int b=0;b<XNumber;b++)
        {
            if(SLINENAME==xlinename[b] && SPOINTNUMBER==xpointnumber[b])
            {
                XRECEIVELINENAME=xreceivelinename[b];
                XFROMRECEIVER=xfromreceiver[b];
                XTORECEIVER=xtoreceiver[b];

                for(int c=0;c<RNumber;c++)
                {
                    if(XRECEIVELINENAME==rlinename[c] && XFROMRECEIVER==rpointnumber[c])
                    {
                        int d=(int)(XTORECEIVER-XFROMRECEIVER);       //注意d少一个，循环要加上
                        for (int e=0;e<=d;e++)
                        {
                            qreal ab=estR[c+e];
                            qreal cd=norR[c+e];
                            axisX=(ab+ESTSP)/2;                       //计算出来的大地坐标的中点坐标值
                            axisY=(cd+NORSP)/2;

                            gridX=(axisX-minDrawE)/singleWid;         //覆盖次数落在横轴第几个盒子里
                            gridY=(axisY-minDrawN)/singleHei;         //覆盖次数落在竖轴第几个盒子里
                            gridY=northBoxNumber-gridY;

                            boxAB[(int)gridX][(int)gridY]++;            //对应的网格覆盖次数+1
                            if(maxFold<boxAB[(int)gridX][(int)gridY])
                                maxFold=boxAB[(int)gridX][(int)gridY];  //求出最大覆盖次数
                        }
                    }
                }
            }
        }
    }
    //    QFile file("fold.data");
    //    file.open(QIODevice::WriteOnly);
    //    QDataStream out(&file);               //输出文件
    //    for(int i=0;i<eastBoxNumber;i++)
    //    {
    //        for(int j=0;j<northBoxNumber;j++)
    //        {
    //            out << (float)boxAB[i][j];
    //        }
    //    }
}

void MyWidget::setInterpolation()
{
    boxAY.clear();
    boxAY.resize(eastBoxNumber);            //初始化AY数组
    for(int j=0;j<eastBoxNumber;j++)
        boxAY[j].resize(height());

    boxXY.clear();
    boxXY.resize(width());            //初始化XY数组
    for(int j=0;j<width();j++)
        boxXY[j].resize(height());

    /*-------------------------------双线插值显示覆盖次数-------------------------------------*/
    unitX=(eastBoxNumber-1)*1./(width()-1);
    unitY=(northBoxNumber-1)*1./(height()-1);         //注意：这里的northBoxNumber不能大于width（）,否则会引起错误

    for(int a=0;a<eastBoxNumber;a++)                    //纵向插值,[a][b]-->[a][height()]
    {
        int xyz=0;
        for(int y=0;y<height()-1;y++)
        {
            if(y*unitY<xyz+1 && y*unitY>=xyz)
            {
                //qDebug()<<"y"<<b<<b*unitY<<xyz;
            }
            else
                xyz++;

            pixelValue=(int)(boxAB[a][xyz]+(y*unitY-(int)(y*unitY))*(boxAB[a][xyz+1]-boxAB[a][xyz]));
            boxAY[a][y]=pixelValue;
        }
    }

    int ABC;                                  //横向插值,[a][height()]-->[width()][height()]
//    boxX.clear();
//    boxY.clear();
//    boxValue.clear();
    emit signalMaxSet(height()-1);
    for(int Y=0;Y<height();Y++)
    {
        ABC=0;
        for(int X=0;X<width()-1;X++)
        {

            if(X*unitX<ABC+1 && X*unitX>=ABC)
            {
                //qDebug()<<"y"<<b<<b*unitY<<xyz;
            }
            else
                ABC++;

            pixelValue=(int)(boxAY[ABC][Y]+(X*unitX-ABC)*(boxAY[ABC+1][Y]-boxAY[ABC][Y]));
//            if(pixelValue!=0)
//            {
//                boxX<<X;
//                boxY<<Y;
//                boxValue<<pixelValue;
//            }
            boxXY[X][Y]=pixelValue;

        }
        emit signalValueSet(Y);
    }
    emit signalHideBar();

}

void MyWidget::paintFoldNumbers(QPainter *painter)
{
    QImage image(width(),height(),QImage::Format_ARGB32);    
    int colorValue;
    setColorTable();                    //设置眼色表
    image.setColorTable(colorTable);    //将颜色表附上

    if(flagZheng==true)
    {
        if(foldIsChanged==true)
        {
            setInterpolation();             //设置像素插值
            foldIsChanged=false;

        }

        for(int i=0;i<width();i++)          //给每个像素上色
        {
            for(int j=0;j<height();j++)
            {
                colorValue=(int)(boxXY[i][j]*255/maxFold);
                image.setPixel(i,j,colorTable[colorValue]);
            }
        }
//        for(int i=0;i<boxX.size();i++)        //去除空白部分后的上色，但会出现由于有没上色的地区，显示在没setPixel的区域会出现混乱
//        {
//            colorValue=(int)(boxValue[i]*255/maxFold);
//            image.setPixel(boxX[i],boxY[i],colorTable[colorValue]);
//        }

        painter->drawImage(0,0,image);
    }


    if(flagXie==true)
    {        
        if(foldIsChanged==true)
        {
            setInterpolationTransform();
            setAxisTransform();
            foldIsChanged=false;

        }
        for(int i=0;i<width();i++)          //给每个像素上色
        {
            for(int j=0;j<height();j++)
            {
                colorValue=(int)(boxXYTT[i][j]*255/maxFoldT);
                image.setPixel(i,j,colorTable[colorValue]);
            }
        }
        painter->drawImage(0,0,image);
    }
}

void MyWidget::setShotPointLine()
{
    qreal tempX;
    qreal tempY;

    line=maxSN-minSN+1;
    /*-------------初始化数组--------------*/
    estS1.resize(line);
    norS1.resize(line);
    for(int i=0;i<line;i++)
        estS1[i].clear();
    for(int j=0;j<line;j++)
        norS1[j].clear();

    /*------------------数组赋值和排序-------------------*/
    for(int x=minSN;x<=maxSN;x++)
    {
        for(int i=0;i<SNumber;i++)                              //画.S文件的连线
        {
            if(slinename[i]==x)
            {
                estS1[x-minSN] << estS[i];
                norS1[x-minSN] << norS[i];
            }
        }

        for(int i=0;i<estS1[x-minSN].size();i++)          //横向排序
        {
            for(int j=i+1;j<estS1[x-minSN].size();j++)
            {
                if(estS1[x-minSN][i]>estS1[x-minSN][j])
                {
                    tempY=norS1[x-minSN][i];
                    norS1[x-minSN][i]=norS1[x-minSN][j];
                    norS1[x-minSN][j]=tempY;

                    tempX=estS1[x-minSN][i];
                    estS1[x-minSN][i]=estS1[x-minSN][j];
                    estS1[x-minSN][j]=tempX;
                }
            }
        }
    }
}


void MyWidget::paintShotPointLine(QPainter *painter)    //炮点连线
{
    painter->setPen(QPen(Qt::blue,1));
    if(shotLineConColor.isValid())
    {
        painter->setPen(QPen(shotLineConColor,shotLineConValue));
    }
    qreal ests1;
    qreal nors1;
    qreal ests2;
    qreal nors2;
    estS2.resize(line);
    norS2.resize(line);
    
    for(int i=0;i<line;i++)
        estS2[i].clear();
    for(int j=0;j<line;j++)
        norS2[j].clear();

    /*--------坐标转换---------*/
    for(int x=0;x<line;x++)
    {
        for(int i=0;i<estS1[x].size();i++)
        {
            estS2[x]<<(estS1[x][i]-minDrawE)/drawWid*(width());
            norS2[x]<<(norS1[x][i]-minDrawN)/drawHei*(height());
            norS2[x][i]=height()-norS2[x][i];
            
        }
    }

    /*--------开始画图---------*/

    for(int x=0;x<line;x++)
    {
        for(int i=0;i<estS1[x].size();i++)
        {
            ests1=estS2[x][i];
            nors1=norS2[x][i];
            for(int j=i+1;j<estS1[x].size();j++)
            {
                ests2=estS2[x][j];
                nors2=norS2[x][j];
                painter->drawLine((int)ests1,(int)nors1,(int)ests2,(int)nors2);
                break;
            }
        }
    }
}

void MyWidget::paintReceivePointLine(QPainter *painter)     //检波点连线
{
    estR1.resize(RNumber);
    estR2.resize(RNumber);
    norR1.resize(RNumber);
    norR2.resize(RNumber);

    painter->setPen(QPen(Qt::red,0.5,Qt::SolidLine,Qt::RoundCap));
    if(receiveLineConColor.isValid())
    {
        painter->setPen(QPen(receiveLineConColor,receiveLineConValue));
    }
    for(int j=0;j<RNumber-1;j++)                              //画.R文件的连线
    {
        if(rlinename[j+1]==rlinename[j])
        {
            estR1[j]=(estR[j]-minDrawE)/drawWid*(width());
            norR1[j]=(norR[j]-minDrawN)/drawHei*(height());
            norR1[j]=height()-norR1[j];

            estR2[j+1]=(estR[j+1]-minDrawE)/drawWid*(width());
            norR2[j+1]=(norR[j+1]-minDrawN)/drawHei*(height());
            norR2[j+1]=height()-norR2[j+1];
            painter->drawLine((int)estR1[j],(int)norR1[j],(int)estR2[j+1],(int)norR2[j+1]);
        }
    }
}

/*--------------求出文件中检波点的斜率-----------*/
void MyWidget::setK()
{
    int countR;
    KofR=0;

    KOFR.resize(RNumber);   //注意清零，数组不清零极易出现问题

    for(int i=0;i<RNumber;i++)
    {
        KOFR[i]=0;
    }

    int zheng=0;
    for(int j=0;j<RNumber-1;j++)        //求检波点的斜率
    {
        if(rlinename[j]==minRN)
        {
            if(estR[j+1]-estR[j]!=0)
            {
                KOFR[j]=(norR[j+1]-norR[j])/(estR[j+1]-estR[j]);
            }
            if(estR[j+1]-estR[j]==0)
            {
                zheng++;
            }
        }
    }

    countR=0;
    for(int j=0;j<RNumber;j++)
    {
        if(KOFR[j]!=0)
        {
            KofR=KofR+KOFR[j];
            countR++;
        }
    }
    KofR=KofR/countR;       //求出斜率
    if(KofR<100 && KofR>-100)
    {
        flagXie=true;
        flagZheng=false;
    }
    if(KofR>100 || KofR<-100)
    {
        flagXie=false;
        flagZheng=true;
    }
    if(zheng>10)
    {
        flagXie=false;
        flagZheng=true;
    }
    //qDebug()<<flagXie<<flagZheng;
}

/*--------------坐标变换，由斜的坐标系至竖直的坐标系-----------*/
void MyWidget::axisTransform()
{
    minTE=10000000;
    maxTE=0;
    minTN=10000000;
    maxTN=0;

    estS0.resize(SNumber);
    norS0.resize(SNumber);
    estSTrans.resize(SNumber);
    norSTrans.resize(SNumber);

    estR0.resize(RNumber);
    norR0.resize(RNumber);
    estRTrans.resize(RNumber);
    norRTrans.resize(RNumber);

    /*----用检波点的斜率比较准确----*/
    radian=atan(KofR);       //这个求出来的是斜率对应的弧度
    radian=(PAI/2)-radian;

    sinA=sin(-radian);        //求出对应的三角关系
    cosA=cos(-radian);

    /*---------------对大地坐标进行 "归零"-----------*/
    for(int i=0;i<SNumber;i++)
    {
        estS0[i]=estS[i]-minDrawE;
        norS0[i]=norS[i]-minDrawN;
    }

    for(int j=0;j<RNumber;j++)
    {
        estR0[j]=estR[j]-minDrawE;
        norR0[j]=norR[j]-minDrawN;
    }
    /*---------------大地坐标规零后进行 "坐标变换"------------*/         //坐标变化之前记得认准坐标系
    for(int i=0;i<SNumber;i++)
    {
        estSTrans[i]=estS0[i]*cosA+norS0[i]*sinA;
        norSTrans[i]=(-estS0[i]*sinA)+norS0[i]*cosA;

        if(estSTrans[i]<minTE)
            minTE=estSTrans[i];
        else if(estSTrans[i]>maxTE)
            maxTE=estSTrans[i];

        if(norSTrans[i]<minTN)
            minTN=norSTrans[i];
        else if(norSTrans[i]>maxTN)
            maxTN=norSTrans[i];
    }
    for(int j=0;j<RNumber;j++)
    {
        estRTrans[j]=estR0[j]*cosA+norR0[j]*sinA;
        norRTrans[j]=norR0[j]*cosA-estR0[j]*sinA;

        if(estRTrans[j]<minTE)
            minTE=(int)estRTrans[j];
        else if(estRTrans[j]>maxTE)
            maxTE=(int)estRTrans[j];

        if(norRTrans[j]<minTN)
            minTN=norRTrans[j];
        else if(norRTrans[j]>maxTN)
            maxTN=norRTrans[j];
    }

    widT=(int)(maxTE-minTE);
    heiT=(int)(maxTN-minTN);

    minDrawTE=minTE-widT*0.1;
    maxDrawTE=maxTE+widT*0.1;
    minDrawTN=minTN-heiT*0.1;
    maxDrawTN=maxTN+heiT*0.1;
    drawWidT=maxDrawTE-minDrawTE;
    drawHeiT=maxDrawTN-minDrawTN;
}

/*--------------对竖直坐标系求覆盖次数------------*/
void MyWidget::setFoldTransform()
{
    singleWidTView=QString::number(singleWidT);
    singleHeiTView=QString::number(singleHeiT);

    eastBoxNumberT=(int)(drawWidT/singleWidT);
    northBoxNumberT=(int)(drawHeiT/singleHeiT);

    boxCD.clear();
    boxCD.resize(eastBoxNumberT);       //初始化动态二维数组
    for(int i=0;i<eastBoxNumberT;i++)
        boxCD[i].resize(northBoxNumberT);


    maxFoldT=0;
    gridXT=0;
    gridYT=0;

    for(int a=0;a<SNumber;a++)
    {
        SLINENAME=slinename[a];
        SPOINTNUMBER=spointnumber[a];

        ESTST=estSTrans[a];
        NORST=norSTrans[a];

        for(int b=0;b<XNumber;b++)
        {
            if(SLINENAME==xlinename[b] && SPOINTNUMBER==xpointnumber[b])
            {
                XRECEIVELINENAME=xreceivelinename[b];
                XFROMRECEIVER=xfromreceiver[b];
                XTORECEIVER=xtoreceiver[b];

                for(int c=0;c<RNumber;c++)
                {
                    if(XRECEIVELINENAME==rlinename[c] && XFROMRECEIVER==rpointnumber[c])
                    {
                        int d=(int)(XTORECEIVER-XFROMRECEIVER);   //注意d少一个，循环要加上
                        for (int e=0;e<=d;e++)
                        {
                            qreal ab=estRTrans[c+e];
                            qreal cd=norRTrans[c+e];
                            axisXT=(ab+ESTST)/2;                  //计算出来的大地坐标的中点坐标值
                            axisYT=(cd+NORST)/2;

                            gridXT=(axisXT-minDrawTE)/singleWidT;         //覆盖次数落在横轴第几个盒子里
                            gridYT=(axisYT-minDrawTN)/singleHeiT;       //覆盖次数落在竖轴第几个盒子里
                            gridYT=northBoxNumberT-gridYT;

                            boxCD[(int)gridXT][(int)gridYT]++;                  //对应的网格覆盖次数+1
                            if(maxFoldT<boxCD[(int)gridXT][(int)gridYT])
                                maxFoldT=boxCD[(int)gridXT][(int)gridYT];       //求出最大覆盖次数
                        }
                    }
                }
            }
        }
    }
    //    QFile file("fold1.data");
    //    file.open(QIODevice::WriteOnly);
    //    QDataStream out(&file);               //输出文件
    //    for(int i=0;i<eastBoxNumberT;i++)
    //    {
    //        for(int j=0;j<northBoxNumberT;j++)
    //        {
    //            out << (float)boxCD[i][j];
    //        }
    //    }
}

/*--------------在垂直坐标系中进行插值-----------*/
void MyWidget::setInterpolationTransform()
{
    boxCY.clear();
    boxCY.resize(eastBoxNumberT);            //初始化CY数组
    for(int j=0;j<eastBoxNumberT;j++)
        boxCY[j].resize(height());

    boxXYT.clear();
    boxXYT.resize(width());            //初始化XYT数组
    for(int j=0;j<width();j++)
        boxXYT[j].resize(height());

    /*-------------------------------双线插值显示覆盖次数-------------------------------------*/

    unitXT=(eastBoxNumberT-1)*1./(width()-1);
    unitYT=(northBoxNumberT-1)*1./(height()-1);         //注意：这里的northBoxNumber不能大于width（）,否则会引起错误---->这个想法是错误的

    for(int c=0;c<eastBoxNumberT;c++)                    //纵向插值,[c][d]-->[c][height()]
    {
        int xyz=0;
        for(int y=0;y<height()-1;y++)
        {
            if(y*unitYT<xyz+1 && y*unitYT>=xyz)
            {
                //qDebug()<<"y"<<b<<b*unitY<<xyz;
            }
            else
                xyz++;

            pixelValueT=(int)(boxCD[c][xyz]+(y*unitYT-(int)(y*unitYT))*(boxCD[c][xyz+1]-boxCD[c][xyz]));
            boxCY[c][y]=pixelValueT;
        }
    }

    int ABC;                                  //横向插值,[c][height()]-->[width()][height()]
    int count=0;
    for(int Y=0;Y<height();Y++)
    {
        ABC=0;
        for(int X=0;X<width()-1;X++)
        {

            if(X*unitXT<ABC+1 && X*unitXT>=ABC)
            {
                //qDebug()<<"y"<<b<<b*unitY<<xyz;
            }
            else
                ABC++;

            pixelValueT=(int)(boxCY[ABC][Y]+(X*unitXT-ABC)*(boxCY[ABC+1][Y]-boxCY[ABC][Y]));
            boxXYT[X][Y]=pixelValueT;
            if(pixelValueT!=0)
            {
            count++;
            }
        }
    }
}


/*--------------将原始坐标于垂直坐标的像素对应起来-----------*/
void MyWidget::setAxisTransform()
{
    estK0.resize(width());
    norK0.resize(height());

    boxXYTT.clear();
    boxXYTT.resize(width());
    for(int i=0;i<width();i++)
        boxXYTT[i].resize(height());

    /*------------坐标算回大地坐标,并且规零----------*/
    for(int i=0;i<width();i++)
    {
        estK=minDrawE+i*drawWid/width();        //换算回大地坐标的公式
        estK0[i]=estK-minDrawE;                 //对大地坐标进行规零
    }

    for(int j=0;j<height();j++)
    {
        norK=minDrawN+j*drawHei/height();
        norK0[j]=norK-minDrawN;
    }

    /*---------------对坐标系进行转换------------*/         //坐标变化之前记得认准坐标系
    emit signalMaxSet(width()-1);
    for(int i=0;i<width();i++)
    {
        for(int j=0;j<height();j++)
        {
            estTK=estK0[i]*cosA+norK0[j]*sinA;
            norTK=norK0[j]*cosA-estK0[i]*sinA;

            if(estTK>minDrawTE && estTK<maxDrawTE && norTK>minDrawTN && norTK<maxDrawTN)
            {
                estTTK=(estTK-minDrawTE)/drawWidT*(width());
                norTTK=(norTK-minDrawTN)/drawHeiT*(height());

                returnValue=boxXYT[(int)estTTK][height()-1-(int)norTTK];              //覆盖次数坐标系点坐标对应的值
                boxXYTT[i][height()-1-j]=(int)returnValue;
            }
        }
        emit signalValueSet(i);
    }
    emit signalHideBar();

}

/*--------------设置颜色表-------------*/
void MyWidget::setColorTable()
{
    colorTable.clear();
    int  i, r, g, b;
    if(zero==1)
    {
        /*----------黑白色表----------*/
        for (i = 0; i <= 255; i++)
        {
            r = 255 - i;
            g = 255 - i;
            b = 255 - i;
            colorTable<<qRgb(r,g,b);
        }
    }

    if(one==1)
    {
        /*----------彩色色表----------*/
        for (i = 0; i < 32; i++)
        {
            r = 0;
            g = 0;
            b = 131 + i * 4;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 0; i < 32; i++)
        {
            r = 0;
            g = 4 + i * 4;
            b = 255;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 1; i < 32; i++)
        {
            r = 0;
            g = 127 + i * 4;
            b = 255;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 0; i < 32; i++)
        {
            r = i * 4;
            g = 255;
            b = 255 - i * 4;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 0; i < 32; i++)
        {
            r = 128 + i * 4;
            g = 255;
            b = 128 - i * 4;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 0; i < 64; i++)
        {
            r = 255;
            g = 255 - i * 4;
            b = 0;
            colorTable<<qRgb(r,g,b);
        }
        for (i = 0; i < 33; i++)
        {
            r = 255 - i * 4;
            g = 0;
            b = 0;
            colorTable<<qRgb(r,g,b);
        }
    }

    if(two==1)
    {
        /*----------颠倒黑白色表----------*/
        for (i = 0; i <= 255; i++)
        {
            r = i;
            g = i;
            b = i;
            colorTable<<qRgb(r,g,b);
        }
    }

    if(three==1)
    {
        /*----------蓝白红----------*/
        for(i=0;i<128;i++)
        {
            r = 2 * i;
            g = 2 * i;
            b = 255;
            colorTable<<qRgb(r,g,b);
        }
        for(i=0;i<128;i++)
        {
            r = 255;
            g = 255 - 2*i;
            b = 255 - 2*i;
            colorTable<<qRgb(r,g,b);
        }
    }
    if(four==1)
    {
        /*----------蓝黄天蓝----------*/
        for(i=0;i<128;i++)
        {
            r = 2*i;
            g = 2*i;
            b = 255 - 2*i;
            colorTable<<qRgb(r,g,b);
        }
        for(i=0;i<128;i++)
        {
            r = 255 - 2*i;
            g = 255;
            b = 2*i;
            colorTable<<qRgb(r,g,b);
        }
    }
    if(five==1)
    {
        /*----------白深绿黄----------*/
        for(i=0;i<128;i++)
        {
            r = 255 - 2*i;
            g = 255 - i;
            b = 255 - 2*i;
            colorTable<<qRgb(r,g,b);
        }
        for(i=0;i<128;i++)
        {
            r = 2*i;
            g = 128 + i;
            b = 0;
            colorTable<<qRgb(r,g,b);
        }
    }
    if(six==1)
    {
        /*----------黑黄红----------*/
        for(i=0;i<128;i++)
        {
            r = 2*i;
            g = 2*i;
            b = 0;
            colorTable<<qRgb(r,g,b);
        }
        for(i=0;i<128;i++)
        {
            r = 255;
            g = 255 - 2*i;
            b = 0;
            colorTable<<qRgb(r,g,b);
        }
    }
    if(seven==1)
    {
        /*----------绿天蓝红----------*/
        for(i=0;i<128;i++)
        {
            r = 0;
            g = 128 + i;
            b = 2*i;
            colorTable<<qRgb(r,g,b);
        }
        for(i=0;i<128;i++)
        {
            r = 2*i;
            g = 255-2*i;
            b = 255-2*i;
            colorTable<<qRgb(r,g,b);
        }
    }
}

/// 颜色
void MyWidget::setShotLineColor(QColor color,double s)
{
    shotLineColor=color;
    shotLineValue=s;
}
void MyWidget::setReceiveLineColor(QColor color,double s)
{
    receiveLineColor=color;
    receiveLineValue=s;
}
void MyWidget::setMouseClickedColor(QColor color,double s)
{
    mouseClickedColor=color;
    mouseClickedValue=s;
}
void MyWidget::setMouseClickedSLColor(QColor color,double s)
{
    mouseClickedSLColor=color;
    mouseClickedSLValue=s;
}
void MyWidget::setMouseClickedRLColor(QColor color,double s)
{
    mouseClickedRLColor=color;
    mouseClickedRLValue=s;
}
void MyWidget::setShotLineConColor(QColor color,double s)
{
    shotLineConColor=color;
    shotLineConValue=s;
}
void MyWidget::setReceiveLineConColor(QColor color,double s)
{
    receiveLineConColor=color;
    receiveLineConValue=s;
}
void MyWidget::setCMPColor(QColor color,double s)
{
    CMP_Color=color;
    CMP_Value=s;
}

/// 形状
void MyWidget::setShotLineShape(int n,int x)
{
    switch(n)
    {
    case 1:
        flagShotLineAdd=true;
        flagShotLineMul=false;
        flagShotLineBox=false;
        break;
    case 2:
        flagShotLineAdd=false;
        flagShotLineMul=true;
        flagShotLineBox=false;
        break;
    case 3:
        flagShotLineAdd=false;
        flagShotLineMul=false;
        flagShotLineBox=true;
        break;
    }
    shotLineSize=x;
}
void MyWidget::setReceiveLineShape(int n,int x)
{
    switch(n)
    {
    case 1:
        flagReceiveLineAdd=true;
        flagReceiveLineMul=false;
        flagReceiveLineBox=false;
        break;
    case 2:
        flagReceiveLineAdd=false;
        flagReceiveLineMul=true;
        flagReceiveLineBox=false;
        break;
    case 3:
        flagReceiveLineAdd=false;
        flagReceiveLineMul=false;
        flagReceiveLineBox=true;
        break;
    }
    receiveLineSize=x;
}
void MyWidget::setMouseClickedShape(int n,int x)
{
    switch(n)
    {
    case 1:
        flagMouseClickedAdd=true;
        flagMouseClickedMul=false;
        flagMouseClickedBox=false;
        break;
    case 2:
        flagMouseClickedAdd=false;
        flagMouseClickedMul=true;
        flagMouseClickedBox=false;
        break;
    case 3:
        flagMouseClickedAdd=false;
        flagMouseClickedMul=false;
        flagMouseClickedBox=true;
        break;
    }
    mouseClickedSize=x;
}
void MyWidget::setCMPShape(int n,int x)
{
    switch(n)
    {
    case 1:
        flagCMPAdd=true;
        flagCMPMul=false;
        flagCMPBox=false;
        break;
    case 2:
        flagCMPAdd=false;
        flagCMPMul=true;
        flagCMPBox=false;
        break;
    case 3:
        flagCMPAdd=false;
        flagCMPMul=false;
        flagCMPBox=true;
        break;
    }
    CMP_Size=x;
}

void MyWidget::setCMPAccuracy(int acc)
{
    switch(acc)
    {
    case 0:
        skipNum=0;break;
    case 1:
        skipNum=1;break;
    case 2:
        skipNum=3;break;
    case 3:
        skipNum=8;break;
    default:
        break;
    }
    setCMP();       //先行设置
    cmpIsChanged=true;
}
