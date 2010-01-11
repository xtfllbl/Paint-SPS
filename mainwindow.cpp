#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRubberBand>
#include <QtGui>
#include <QGridLayout>
#include <stdlib.h>
#include <stdio.h>
#define Num 100

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    my = new MyWidget();
    openS=false;
    my->rectWidth=0;
    my->rubberBandIsShown = false;
    my->mouseRightZoom=false;
    my->shotON=false;
    my->receiveON=false;
    my->cmpON=false;
    my->shotPointLineON=false;
    my->receivePointLineON=false;
    my->alreadySetShotData=false;
    my->alreadySetFoldDataA=false;
    my->alreadySetFoldDataB=false;
    my->alreadySetCMP=false;
    my->zoomInAvailable=true;
    my->cmpIsChanged=false;
    my->foldIsChanged=false;

    my->HOldIncrease=1;
    my->VOldIncrease=1;

    ui->setupUi(this);
    ui->mainToolBar->setMovable(false);

    ui->actionReset->setEnabled(false);
    ui->actionRelation->setEnabled(false);
    ui->actionShotLine->setEnabled(false);
    ui->actionReceiveLine->setEnabled(false);
    ui->actionFoldNumbers->setEnabled(false);
    ui->actionShotPointLine->setEnabled(false);
    ui->actionReceivePointLine->setEnabled(false);
    ui->actionCMP->setEnabled(false);
    ui->actionOption->setEnabled(false);

    scrollarea=new QScrollArea();
    VScrollBar=new QScrollBar();
    HScrollBar=new QScrollBar();

    label1 = new QLabel();
    label2 = new QLabel();
    label3 = new QLabel();
    label4 = new QLabel();
    statusLabel1=new QLabel();
    statusLabel2=new QLabel();
    statusLabel3=new QLabel();
    statusLabel4=new QLabel();
    statusLabel5=new QLabel();

    pBar=new QProgressBar();
    pBar->hide();

    statusLabel1->setFixedWidth(200);
    statusLabel2->setFixedWidth(130);
    statusLabel3->setFixedWidth(50);
    statusLabel5->setFixedWidth(50);

    statusBar()->addWidget(statusLabel1);
    statusBar()->addWidget(statusLabel2);
    statusBar()->addWidget(statusLabel3);
    statusBar()->addWidget(statusLabel4);
    statusBar()->addWidget(statusLabel5);
    statusBar()->addWidget(pBar);

    label1->setFixedHeight(25); //空出上面
    label2->setFixedWidth(70);  //左面
    label3->setFixedWidth(80);  //右面
    label4->setFixedHeight(40); //下面

    scrollarea->setWidget(my);

    scrollarea->setVerticalScrollBar(VScrollBar);
    scrollarea->setHorizontalScrollBar(HScrollBar);

    QGridLayout *layout = new QGridLayout( );
    layout->addWidget(label1,0,0);
    layout->addWidget(label2,1,0);
    layout->addWidget(scrollarea,1,1);
    layout->addWidget(label3,1,2);
    layout->addWidget(label4,2,0);
    ui->mainw->setLayout(layout);
    setCentralWidget(ui->mainw);

    scrollarea->resize(640,613);

    scrollarea->setMouseTracking(true);
    my->setMouseTracking(true);
    setMouseTracking(true);
    ui->mainw->setMouseTracking(true);
    pBar->setValue(0);

    openfile= new OpenFile();               //其他类的对象的创建
    combinefiles= new CombineFiles();
    option= new Option();
    help = new Help();

    connect(openfile->m_ui->btnOK,SIGNAL(clicked()),this,SLOT(frontOpen()));
    connect(combinefiles->m_ui->btnOK,SIGNAL(clicked()),this,SLOT(combineFilesIntoOne()));
    connect(option->m_ui->btnApply,SIGNAL(clicked()),this,SLOT(applyChange()));

    connect(my,SIGNAL(signalMaxSet(int)),this,SLOT(setProgressBar(int)));
    connect(my,SIGNAL(signalValueSet(int)),this,SLOT(setProgressBarValue(int)));
    connect(my,SIGNAL(signalHideBar()),this,SLOT(hideBar()));

    /// 接受发送各线的颜色
    //my
    connect(option,SIGNAL(signalShotLineColor(QColor,double)),my,SLOT(setShotLineColor(QColor,double)));
    connect(option,SIGNAL(signalReceiveLineColor(QColor,double)),my,SLOT(setReceiveLineColor(QColor,double)));
    connect(option,SIGNAL(signalMouseClickedColor(QColor,double)),my,SLOT(setMouseClickedColor(QColor,double)));
    connect(option,SIGNAL(signalMouseClickedSLColor(QColor,double)),my,SLOT(setMouseClickedSLColor(QColor,double)));
    connect(option,SIGNAL(signalMouseClickedRLColor(QColor,double)),my,SLOT(setMouseClickedRLColor(QColor,double)));
    connect(option,SIGNAL(signalShotLineConColor(QColor,double)),my,SLOT(setShotLineConColor(QColor,double)));
    connect(option,SIGNAL(signalReceiveLineConColor(QColor,double)),my,SLOT(setReceiveLineConColor(QColor,double)));
    connect(option,SIGNAL(signalCMP(QColor,double)),my,SLOT(setCMPColor(QColor,double)));
    //main
    connect(option,SIGNAL(signalShotLineColor(QColor,double)),this,SLOT(setShotLineColorMain(QColor,double)));
    connect(option,SIGNAL(signalReceiveLineColor(QColor,double)),this,SLOT(setReceiveLineColorMain(QColor,double)));
    connect(option,SIGNAL(signalCMP(QColor,double)),this,SLOT(setCMPColorMain(QColor,double)));

    /// 更改点的形状
    // my
    connect(option,SIGNAL(signalShotLineShape(int,int)),my,SLOT(setShotLineShape(int,int)));
    connect(option,SIGNAL(signalReceiveLineShape(int,int)),my,SLOT(setReceiveLineShape(int,int)));
    connect(option,SIGNAL(signalMouseClickedShape(int,int)),my,SLOT(setMouseClickedShape(int,int)));
    connect(option,SIGNAL(signalCMPShape(int,int)),my,SLOT(setCMPShape(int,int)));
    //main
    connect(option,SIGNAL(signalShotLineShape(int,int)),this,SLOT(setShotLineShapeMain(int,int)));
    connect(option,SIGNAL(signalReceiveLineShape(int,int)),this,SLOT(setReceiveLineShapeMain(int,int)));
    connect(option,SIGNAL(signalCMPShape(int,int)),this,SLOT(setCMPShapeMain(int,int)));

    /// 设置初始值
    flagSLAdd=true;
    flagSLMul=false;
    flagSLBox=false;
    flagRLAdd=true;
    flagRLMul=false;
    flagRLBox=false;
    flagCMPAdd=true;
    flagCMPMul=false;
    flagCMPBox=false;

    SLSize=6;
    RLSize=2;
    CMPSize=2;

    /// 设置CMP精度
    connect(option,SIGNAL(signalCMPAccuracy(int)),my,SLOT(setCMPAccuracy(int)));
    int width=QApplication::desktop()->width();         //获取屏幕的分辨率
    int height=QApplication::desktop()->height();
    this->move((width/2)-250,(height/2)-300);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::frontOpen()
{
    if(openfile->openSuccess==true)
    {
        openfile->SfileName = openfile->m_ui->lineSFile->text();
        openfile->RfileName = openfile->m_ui->lineRFile->text();
        openfile->XfileName = openfile->m_ui->lineXFile->text();

        fp.setFileName(openfile->SfileName);
        fb.setFileName(openfile->RfileName);
        fx.setFileName(openfile->XfileName);
        if (!fp.open(QIODevice::ReadOnly))
            fp.close();
        if (!fb.open(QIODevice::ReadOnly))
            fb.close();
        if (!fx.open(QIODevice::ReadOnly))
            fx.close();

        setWindowTitle(tr("SPS File Show ---- ")+fp.fileName());
        openS=true;
        ui->actionRelation->setEnabled(true);
        ui->actionRelation->setChecked(false);

        ui->actionShotLine->setEnabled(true);
        ui->actionShotLine->setChecked(true);
        my->shotON=true;

        ui->actionReceiveLine->setEnabled(true);
        ui->actionReceiveLine->setChecked(true);
        my->receiveON=true;

        ui->actionFoldNumbers->setEnabled(true);
        ui->actionFoldNumbers->setChecked(false);
        my->foldModeON=false;

        ui->actionShotPointLine->setEnabled(true);
        ui->actionShotPointLine->setChecked(false);
        my->shotPointLineON=false;

        ui->actionReceivePointLine->setEnabled(true);
        ui->actionReceivePointLine->setChecked(false);
        my->receivePointLineON=false;

        ui->actionCMP->setEnabled(true);
        ui->actionCMP->setChecked(false);
        my->cmpON=false;

        ui->actionOption->setEnabled(true);
        ui->actionOption->setChecked(false);

        my->alreadySetFoldDataA=false;
        my->alreadySetFoldDataB=false;
        my->alreadySetShotData=false;
        my->alreadySetCMP=false;

        my->maxFold=0;
        my->maxFoldT=0;

        countCMP=0;
        countFold=0;

        my->singleWid=25;
        my->singleHei=100;
        my->singleWidT=40;
        my->singleHeiT=40;

        setFileLocation();
        setData();
        my->setK();

        if(openfile->m_ui->lineSingleWid->text()!="" && openfile->m_ui->lineSingleHei->text()!="")
        {
            if(my->flagZheng==true)
            {
                my->singleWidView=openfile->m_ui->lineSingleWid->text();
                my->singleHeiView=openfile->m_ui->lineSingleHei->text();
                my->singleWid=my->singleWidView.toInt();
                my->singleHei=my->singleHeiView.toInt();
                my->setFoldNumbers();
            }
            if(my->flagXie==true)
            {
                my->singleWidTView=openfile->m_ui->lineSingleWid->text();
                my->singleHeiTView=openfile->m_ui->lineSingleHei->text();
                my->singleWidT=my->singleWidTView.toInt();
                my->singleHeiT=my->singleHeiTView.toInt();
                my->axisTransform();
                my->setFoldTransform();
            }
        }


        my->HOldIncrease=1;
        my->VOldIncrease=1;
        ui->actionReset->setEnabled(false);

        my->resize(scrollarea->width(),scrollarea->height());

        my->mouseRightZoom=false;
        HScrollBar->setValue(0);
        VScrollBar->setValue(0);

        my->refreshPixmap();
    }
    else if(openfile->openSuccess==false)
    {
        return;
    }
}

void MainWindow::on_actionOpen_triggered()
{
    openfile->show();
    int width=QApplication::desktop()->width();         //获取屏幕的分辨率
    int height=QApplication::desktop()->height();
    openfile->move(width/2-100,height/2-100);
}

void MainWindow::setFileLocation()
{
    isWindowsEnter=0;
    QByteArray str;
    QByteArray rn;

    //判断fp文件回车字符的字节数
    fp.seek(80);
    rn=fp.read(2);
    if(rn=="\r\n")
    {
        isWindowsEnter=1;
    }
    //找到fp文件的数据起始位置
    fp.seek(0);
    for(finalLine=1;finalLine<200;finalLine++)
    {
        str=fp.read(1);
        if(str=="S"||str=="X"||str=="R")
        {
            break;
        }
        fp.seek(fp.pos()+80+isWindowsEnter);
    }
    finalLine=finalLine-1;
}



void MainWindow::mouseMoveEvent ( QMouseEvent *event )
{
    QPoint point =  my->mapFromGlobal(event->globalPos());
    if (my->rubberBandIsShown)      //画框框
    {
        my->updateRubberBandRegion();
        if(point.x() <1){                               //只能确保不落在mywidget的外面
            point.setX(1);;
        }
        else if(point.x() > my->width() - 1){
            point.setX(my->width() - 1);
        }
        if(point.y() <1){
            point.setY(1);;
        }
        else if(point.y() > my->height() - 1){
            point.setY(my->height() - 1);
        }
        my->rubberBandRect.setBottomRight(point);
        my->updateRubberBandRegion();
    }

    if(openS==true)
    {
        QString X= QString::number(my->minDrawE+(point.x())*my->drawWid/(my->width()));
        int YY=(int)(my->minDrawN+ ((my->height())-(point.y())) *my->drawHei/(my->height()));
        QString Y= QString::number(YY);
        //        QString X= QString::number(point.x());
        //        QString Y= QString::number(point.y());
        statusLabel1->setText(tr("East=")+X+"  "+tr("North=")+Y);

        int x=X.toInt();
        int y=Y.toInt();  //注意Y的坐标的长度超出了int的范围

        QString lineName;
        QString fold;
        if(my->shotON==false && my->receiveON==true)
        {
            for(int a=0;a<my->RNumber;a++)
            {
                if(x<my->estR[a]+20 && x>my->estR[a]-20
                   && y<my->norR[a]+20 && y>my->norR[a]-20)
                {
                    statusLabel2->setText(tr("Receive Line Number:"));
                    lineName=QString::number(my->rlinename[a]);
                    statusLabel3->setText(lineName);
                }
            }
        }
        if(my->shotON==true && my->receiveON==false)
        {
            for(int b=0;b<my->SNumber;b++)
            {
                if(x<my->estS[b]+30 && x>my->estS[b]-30
                   && y<my->norS[b]+30 && y>my->norS[b]-30)
                {
                    statusLabel2->setText(tr("Shot Line Number:"));
                    lineName=QString::number(my->slinename[b]);
                    statusLabel3->setText(lineName);
                }

            }
        }
        if(my->shotON==true && my->receiveON==true)
        {
            for(int a=0;a<my->RNumber;a++)
            {
                if(x<my->estR[a]+20 && x>my->estR[a]-20
                   && y<my->norR[a]+20 && y>my->norR[a]-20)
                {
                    statusLabel2->setText(tr("Receive Line Number:"));
                    lineName=QString::number(my->rlinename[a]);
                    statusLabel3->setText(lineName);
                }
            }
            for(int b=0;b<my->SNumber;b++)
            {
                if(x<my->estS[b]+30 && x>my->estS[b]-30
                   && y<my->norS[b]+30 && y>my->norS[b]-30)
                {
                    statusLabel2->setText(tr("Shoot Line Number:"));
                    lineName=QString::number(my->slinename[b]);
                    statusLabel3->setText(lineName);
                }
            }
        }
        if(my->shotON==false && my->receiveON==false)
        {
            statusLabel2->setText("");
            statusLabel3->setText("");
        }

        if(my->foldModeON==true)
        {
            if(my->flagZheng==true)
            {
                statusLabel4->setText(tr("The fold number is:"));
                if(point.x()>0 && point.y()>0 && point.x()<my->width() && point.y()<my->height())
                {
                    fold=QString::number(my->boxXY[point.x()][point.y()]);
                    statusLabel5->setText(fold);
                }
            }
            else if(my->flagXie==true)
            {
                statusLabel4->setText(tr("The fold number is:"));
                if(point.x()>0 && point.y()>0 && point.x()<my->width() && point.y()<my->height())
                {
                    fold=QString::number(my->boxXYTT[point.x()][point.y()]);
                    statusLabel5->setText(fold);
                }
            }
        }
    }
}

void MainWindow::mousePressEvent( QMouseEvent *event)
{
    my->MrRight=0;
    my->MissRight=0;

    if(openS && ui->actionRelation->isChecked())
    {
        if(event->button()==Qt::LeftButton)
        {
            my->rubberBandIsShown=false;
            QPoint point =  my->mapFromGlobal(event->globalPos());
            my->mr=my->minDrawE+(point.x())*my->drawWid/(my->width());
            my->miss=my->minDrawN+ ((my->height())-(point.y()))   *my->drawHei/(my->height());
            my->decide();
            my->update();
        }
    }
    if(openS)
    {
        if(event->button()==Qt::LeftButton)
        {
            my->rubberBandIsShown=false;
        }
        if(event->button()==Qt::RightButton)
        {
            my->rubberBandIsShown=true;
            my->mouseRightZoom=true;
            setCursor(Qt::CrossCursor);
            QPoint point =  my->mapFromGlobal(event->globalPos());
            my->rubberBandRect.setTopLeft(point);
            my->rubberBandRect.setBottomRight(point);
            my->updateRubberBandRegion();
            //my->refreshPixmap();      //单击不要刷新,可减少一次插值
        }
    }

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    my->HOldIncrease=1;
    my->VOldIncrease=1;
    ui->actionReset->setEnabled(false);

    my->resize(scrollarea->width(),scrollarea->height());

    my->mouseRightZoom=false;
    HScrollBar->setValue(0);
    VScrollBar->setValue(0);

    my->oldW=my->width();
    my->oldH=my->height();
    my->cmpIsChanged=true;
    my->foldIsChanged=true;
    my->refreshPixmap();
}

void MainWindow::mouseReleaseEvent ( QMouseEvent *event )
{
    if ((event->button() == Qt::RightButton) && my->rubberBandIsShown )  //鼠标右键缩放
    {
        my->rubberBandIsShown = false;
        my->updateRubberBandRegion();
        ui->actionReset->setEnabled(true);
        if(ui->actionRelation->isChecked()==false)
            unsetCursor();
        else if(ui->actionRelation->isChecked())
            setCursor(Qt::PointingHandCursor);


        QRect rect = my->rubberBandRect.normalized();
        double RealWidth;
        double RealHeight;

        my->rectWidth=rect.width();
        my->rectHeight=rect.height();

        RealWidth=rect.topRight().x()*my->drawWid/my->width()-rect.topLeft().x()*my->drawWid/my->width();
        RealHeight=rect.bottomLeft().y()*my->drawHei/my->height()-rect.topLeft().y()*my->drawHei/my->height();

        my->HIncrease=scrollarea->width()*1./rect.width();        //不要按照全局的来，按照局部的来
        my->VIncrease=scrollarea->height()*1./rect.height();
        if(my->width()*my->HIncrease>10000 ||my->height()*my->VIncrease>10000)
            return;
        else
            my->resize((int)(my->width()*my->HIncrease),(int)(my->height()*my->VIncrease));

        int HValue = (int)(rect.x()*my->HIncrease);
        int VValue = (int)(rect.y()*my->VIncrease);

        HScrollBar->setValue(HValue);
        VScrollBar->setValue(VValue);

        my->HOldIncrease=my->HIncrease;
        my->VOldIncrease=my->VIncrease;

        my->cmpIsChanged=true;
        my->foldIsChanged=true;
        my->oldW=my->width();
        my->oldH=my->height();

        my->refreshPixmap();
    }


}

void MainWindow::setData()
{
    i=0;
    j=0;
    k=0;

    my->maxE=0;
    my->minE=1000000;
    my->maxN=0;
    my->minN=100000000;
    my->maxSN=0;
    my->minSN=1000000;
    my->maxRN=0;
    my->minRN=1000000;

    EstS=(char *)calloc(1,8);
    NorS=(char *)calloc(1,10);
    Slinename=(char *)calloc(1,16);
    Spointnumber=(char *)calloc(1,8);
    Rlinename=(char *)calloc(1,16);
    Rpointnumber=(char *)calloc(1,8);
    Xlinename=(char *)calloc(1,16);
    Xpointnumber=(char *)calloc(1,8);
    Xreceivelinename=(char *)calloc(1,16);
    XFromreceiver=(char *)calloc(1,8);
    XToreceiver=(char *)calloc(1,8);
    EstR=(char *)calloc(1,8);
    NorR=(char *)calloc(1,10);

    if(isWindowsEnter==false)            //判断回车占用几个字符
        plusEnter=0;
    else if(isWindowsEnter==true)
        plusEnter=1;

    //----------------------S文件数据处理---------------------//
    my->SNumber=0;
    fp.seek(finalLine*(81+plusEnter));

    while(!fp.atEnd())
    {
        my->SNumber++;
        fp.seek(fp.pos()+81+plusEnter);
    }
    my->slinename.resize(my->SNumber);
    my->spointnumber.resize(my->SNumber);
    my->estS.resize(my->SNumber);
    my->norS.resize(my->SNumber);
    my->estDrawS.resize(my->SNumber);
    my->norDrawS.resize(my->SNumber);

    fp.seek(finalLine*(81+plusEnter)+1);
    while(!fp.atEnd())
    {

        fp.readLine(Slinename,17);
        my->slinename[i]=atof(Slinename);
        fp.readLine(Spointnumber,9);
        my->spointnumber[i]=atof(Spointnumber);

        fp.seek(fp.pos()+21);
        fp.readLine(EstS,10);
        my->estS[i]=atof(EstS);
        fp.readLine(NorS,11);
        my->norS[i]=atof(NorS);
        //qDebug()<<my->slinename[i]<<my->spointnumber[i]<<my->estS[i]<<my->norS[i];

        if(my->estS[i]>my->maxE)        //判断.S文件中东北的最大最小值
            my->maxE=(int)my->estS[i];
        else if(my->estS[i]<my->minE)
            my->minE=(int)my->estS[i];

        if(my->norS[i]>my->maxN)
            my->maxN=(int)my->norS[i];
        else if(my->norS[i]<my->minN)
            my->minN=(int)my->norS[i];

        if(my->slinename[i]<my->minSN)
            my->minSN=(int)my->slinename[i];
        else if(my->slinename[i]>my->maxSN)
            my->maxSN=(int)my->slinename[i];

        i++;

        fp.seek(fp.pos()+17+plusEnter);
    }
    ////------------------------R文件数据处理---------------------------//
    my->RNumber=0;
    fb.seek(finalLine*(81+plusEnter));

    while(!fb.atEnd())
    {
        my->RNumber++;
        fb.seek(fb.pos()+81+plusEnter);
    }
    my->rlinename.resize(my->RNumber);
    my->rpointnumber.resize(my->RNumber);
    my->estR.resize(my->RNumber);
    my->norR.resize(my->RNumber);
    my->estDrawR.resize(my->RNumber);
    my->norDrawR.resize(my->RNumber);

    fb.seek(finalLine*(81+plusEnter)+1);
    while(!fb.atEnd())
    {
        fb.readLine(Rlinename,17);
        my->rlinename[j]=atof(Rlinename);
        fb.readLine(Rpointnumber,9);
        my->rpointnumber[j]=atof(Rpointnumber);

        fb.seek(fb.pos()+21);
        fb.readLine(EstR,10);
        my->estR[j]=atof(EstR);
        fb.readLine(NorR,11);
        my->norR[j]=atof(NorR);
        //qDebug()<<my->rlinename[j]<<my->rpointnumber[j]<<my->estR[j]<<my->norR[j];

        if(my->estR[j]>my->maxE)        //判断.S文件中东北的最大最小值
            my->maxE=my->estR[j];
        else if(my->estR[j]<my->minE)
            my->minE=my->estR[j];

        if(my->norR[j]>my->maxN)
            my->maxN=my->norR[j];
        else if(my->norR[j]<my->minN)
            my->minN=my->norR[j];

        if(my->rlinename[j]<my->minRN)
            my->minRN=(int)my->rlinename[j];
        else if(my->rlinename[j]>my->maxRN)
            my->maxRN=(int)my->rlinename[j];
        //qDebug()<<"max"<<my->maxN<<"min"<<my->minN;
        j++;

        fb.seek(fb.pos()+17+plusEnter);
    }
    my->wid=my->maxE-my->minE;
    my->hei=my->maxN-my->minN;

    my->minDrawE=my->minE-my->wid*0.1;
    my->maxDrawE=my->maxE+my->wid*0.1;
    my->minDrawN=my->minN-my->hei*0.1;
    my->maxDrawN=my->maxN+my->hei*0.1;

    my->drawWid=my->maxDrawE-my->minDrawE;
    my->drawHei=my->maxDrawN-my->minDrawN;

    ////------------------------X文件数据处理----------------------//
    my->XNumber=0;
    fx.seek(finalLine*(81+plusEnter));

    while(!fx.atEnd())
    {
        my->XNumber++;
        fx.seek(fx.pos()+81+plusEnter);
    }
    my->xlinename.resize(my->XNumber);
    my->xpointnumber.resize(my->XNumber);
    my->xreceivelinename.resize(my->XNumber);
    my->xfromreceiver.resize(my->XNumber);
    my->xtoreceiver.resize(my->XNumber);

    fx.seek(finalLine*(81+plusEnter)+13);
    while(!fx.atEnd())
    {
        fx.readLine(Xlinename,17);
        my->xlinename[k]=atof(Xlinename);

        fx.readLine(Xpointnumber,9);
        my->xpointnumber[k]=atof(Xpointnumber);

        fx.seek(fx.pos()+10);

        fx.readLine(Xreceivelinename,17);
        my->xreceivelinename[k]=atof(Xreceivelinename);

        fx.readLine(XFromreceiver,9);
        my->xfromreceiver[k]=atof(XFromreceiver);

        fx.readLine(XToreceiver,9);
        my->xtoreceiver[k]=atof(XToreceiver);
        //qDebug()<<my->xlinename[k]<<my->xpointnumber[k]<<my->xreceivelinename[k]<<my->xfromreceiver[k]<<my->xtoreceiver[k];
        k++;

        fx.seek(fx.pos()+15+plusEnter);
    }
    //  qDebug()<<my->SNumber<<my->RNumber<<my->XNumber;
    fp.close();
    fb.close();
    fx.close();

}

void MainWindow::on_actionReset_triggered()
{
    my->HOldIncrease=1;
    my->VOldIncrease=1;
    ui->actionReset->setEnabled(false);

    my->resize(scrollarea->width(),scrollarea->height());

    my->mouseRightZoom=false;
    HScrollBar->setValue(0);
    VScrollBar->setValue(0);

    my->oldW=my->width();
    my->oldH=my->height();
    my->cmpIsChanged=true;
    my->foldIsChanged=true;
    my->refreshPixmap();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    HBarValue=HScrollBar->value();
    VBarValue=VScrollBar->value();
    HBarMax=HScrollBar->maximum();
    VBarMax=VScrollBar->maximum();

    QPainter painter(this);
    paintCor(&painter);
}

void MainWindow::paintCor(QPainter *painter)
{
    if(point.isNull())      //保证这个值不变
    {
        point=my->mapTo(centralWidget(),my->zeroPoint);
    }
    int more=20;
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap));

    /*----------------------------------------------------------------------------------*/
    /*                           画坐标轴                          */
    /*----------------------------------------------------------------------------------*/

    painter->drawLine(point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height(),
                      scrollarea->width()+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height());  //Axis X
    for(int x=0;x<=(scrollarea->width()/100);x++)
    {
        painter->drawLine(100*x+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height(),
                          100*x+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more-6+ui->menuBar->height());
    }
    for(int x=0;x<(scrollarea->width()/20);x++)
    {
        painter->drawLine(20*x+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height(),
                          20*x+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more-3+ui->menuBar->height());
    }

    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+ui->menuBar->height());     //Axis Y
    // 画个N
    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x()-2,40+ui->mainToolBar->height()+ui->menuBar->height()+5);
    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x()+2,40+ui->mainToolBar->height()+ui->menuBar->height()+5);
    painter->drawText(scrollarea->width()+more+point.x()-4,40+ui->mainToolBar->height()+ui->menuBar->height()-7,"N");
    for(int y=0;y<=(scrollarea->height()/100);y++)
    {
        painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+scrollarea->height()-y*100+ui->menuBar->height(),
                          scrollarea->width()+more+point.x()-6,40+ui->mainToolBar->height()+scrollarea->height()-y*100+ui->menuBar->height());
    }
    for(int y=0;y<(scrollarea->height()/20);y++)
    {
        painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+scrollarea->height()-y*20+ui->menuBar->height(),
                          scrollarea->width()+more+point.x()-3,40+ui->mainToolBar->height()+scrollarea->height()-y*20+ui->menuBar->height());
    }

    //包围
    painter->drawRect(40,40+ui->mainToolBar->height()+ui->menuBar->height(),30,scrollarea->height());

    /*----------------------------------------------------------------------------------*/
    /*                           写坐标值                          */
    /*----------------------------------------------------------------------------------*/

    if(openS==true)
    {
        for(int x=0;x<=(scrollarea->width()/100);x++)        //set Axis X text
        {
            qreal Hplus;
            QString a;
            Hplus=my->drawWid*HScrollBar->value()/my->width();            
            a=QString::number(my->minDrawE+Hplus+(my->drawWid*100*x/my->width()));
            painter->drawText(100*x+point.x()-more,
                              scrollarea->height()+40+ui->mainToolBar->height()+2*more+ui->menuBar->height(),
                              a);
        }

        for(int y=0;y<=(scrollarea->height())/100;y++)        //set Axis Y text
        {
            qreal Vplus;            
            QString b;
            int a;

            Vplus=my->drawHei*(VScrollBar->maximum()-VScrollBar->value())/my->height();          
            a=(int)(my->minDrawN+Vplus+(my->drawHei*100*y/my->height()));
            b=QString::number(a);
            //qDebug()<<y<<b[y]<<(my->drawHei*100*y/my->height())<<Vplus;

            painter->drawText(scrollarea->width()+more+point.x()+10,
                              40+ui->mainToolBar->height()+scrollarea->height()-100*y+5+ui->menuBar->height(),
                              b);
        }
    }

    /*----------------------------------------------------------------------------------*/
    /*                           画色表                             */
    /*---------------------------------------------------------------------------------*/
    if(my->foldModeON==true)
    {
        QImage imageTable(30,scrollarea->height(),QImage::Format_ARGB32);
        int colorValue;
        my->setColorTable();                    //设置眼色表
        imageTable.setColorTable(my->colorTable);    //将颜色表附上

        for(int j=0;j<scrollarea->height();j++)          //给每个像素上色
        {
            for(int i=0;i<30;i++)
            {
                colorValue=255*j/scrollarea->height();
                imageTable.setPixel(i,j,my->colorTable[colorValue]);
            }
        }
        //色表
        painter->drawImage(40,40+ui->mainToolBar->height()+ui->menuBar->height(),imageTable);

        //包围
        painter->drawRect(40,40+ui->mainToolBar->height()+ui->menuBar->height(),30,scrollarea->height());
        //刻度
        for(int i=0;i<9;i++)
        {
            painter->drawLine(40,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height()/9*i,
                              50,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height()/9*i);
        }

        //刻度值
        if(my->flagZheng==true)
        {
            for(int i=0;i<9;i++)
            {
                int fold=my->maxFold/9*i;
                QString text=QString::number(fold);
                painter->drawText(15,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height()/9*i+5,text);
            }
            QString text=QString::number(my->maxFold);
            painter->drawText(15,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height(),text);

        }
        if(my->flagXie==true)
        {
            for(int i=0;i<9;i++)
            {
                int fold=my->maxFoldT/9*i;
                QString text=QString::number(fold);
                painter->drawText(13,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height()/9*i+5,text);
            }
            QString text=QString::number(my->maxFoldT);
            painter->drawText(13,40+ui->mainToolBar->height()+ui->menuBar->height()+scrollarea->height(),text);
        }
    }
    /*----------------------------------------------------------------------------------*/
    /*                           画图例                             */
    /*---------------------------------------------------------------------------------*/
    /// Shot Point
    painter->save();
    painter->drawText(point.x(),90,tr("Shot Point:"));
    painter->setPen(QPen(Qt::blue,1));
    if(shotColor.isValid())
        painter->setPen(QPen(shotColor,1));
    if(flagSLAdd==true)
    {
        painter->drawLine(point.x()+80-SLSize,85,point.x()+80+SLSize,85);
        painter->drawLine(point.x()+80,85-SLSize,point.x()+80,85+SLSize);
    }
    if(flagSLMul==true)
    {
        painter->drawLine(point.x()+80-SLSize,85+SLSize,point.x()+80+SLSize,85-SLSize);
        painter->drawLine(point.x()+80-SLSize,85-SLSize,point.x()+80+SLSize,85+SLSize);
    }
    if(flagSLBox==true)
    {
        painter->drawLine(point.x()+80-SLSize,85+SLSize,point.x()+80+SLSize,85+SLSize);
        painter->drawLine(point.x()+80+SLSize,85+SLSize,point.x()+80+SLSize,85-SLSize);
        painter->drawLine(point.x()+80-SLSize,85-SLSize,point.x()+80+SLSize,85-SLSize);
        painter->drawLine(point.x()+80-SLSize,85-SLSize,point.x()+80-SLSize,85+SLSize);
    }

    /// Receive Point
    painter->restore();
    painter->drawText(point.x()+100,90,tr("Receive Point:"));
    painter->save();
    painter->setPen(QPen(Qt::red,1));
    if(receiveColor.isValid())
        painter->setPen(QPen(receiveColor,1));
    if(flagRLAdd==true)
    {
        painter->drawLine(point.x()+200-SLSize,85,point.x()+200+SLSize,85);
        painter->drawLine(point.x()+200,85-SLSize,point.x()+200,85+SLSize);
    }
    if(flagRLMul==true)
    {
        painter->drawLine(point.x()+200-SLSize,85+SLSize,point.x()+200+SLSize,85-SLSize);
        painter->drawLine(point.x()+200-SLSize,85-SLSize,point.x()+200+SLSize,85+SLSize);
    }
    if(flagRLBox==true)
    {
        painter->drawLine(point.x()+200-SLSize,85+SLSize,point.x()+200+SLSize,85+SLSize);
        painter->drawLine(point.x()+200+SLSize,85+SLSize,point.x()+200+SLSize,85-SLSize);
        painter->drawLine(point.x()+200-SLSize,85-SLSize,point.x()+200+SLSize,85-SLSize);
        painter->drawLine(point.x()+200-SLSize,85-SLSize,point.x()+200-SLSize,85+SLSize);
    }
    painter->restore();

    /// CMP Point
    painter->drawText(point.x()+220,90,tr("CMP Point:"));
    painter->setPen(QPen(Qt::green,1));
    if(CMPColor.isValid())
        painter->setPen(QPen(CMPColor,1));
    if(flagCMPAdd==true)
    {
        painter->drawLine(point.x()+300-SLSize,85,point.x()+300+SLSize,85);
        painter->drawLine(point.x()+300,85-SLSize,point.x()+300,85+SLSize);
    }
    if(flagCMPMul==true)
    {
        painter->drawLine(point.x()+300-SLSize,85+SLSize,point.x()+300+SLSize,85-SLSize);
        painter->drawLine(point.x()+300-SLSize,85-SLSize,point.x()+300+SLSize,85+SLSize);
    }
    if(flagCMPBox==true)
    {
        painter->drawLine(point.x()+300-SLSize,85+SLSize,point.x()+300+SLSize,85+SLSize);
        painter->drawLine(point.x()+300+SLSize,85+SLSize,point.x()+300+SLSize,85-SLSize);
        painter->drawLine(point.x()+300-SLSize,85-SLSize,point.x()+300+SLSize,85-SLSize);
        painter->drawLine(point.x()+300-SLSize,85-SLSize,point.x()+300-SLSize,85+SLSize);
    }

    update();
}

void MainWindow::on_actionRelation_triggered()
{
    if(ui->actionRelation->isChecked())
    {
        setCursor(Qt::PointingHandCursor);
        ui->actionShotLine->setEnabled(false);
        ui->actionReceiveLine->setEnabled(false);
    }
    else
    {
        ui->actionRelation->setChecked(false);
        unsetCursor();
        my->sON=false;
        my->rON=false;
        ui->actionShotLine->setEnabled(true);
        ui->actionReceiveLine->setEnabled(true);
        my->refreshPixmap();
    }
}

void MainWindow::resizeEvent (QResizeEvent * )
{
    if(my->mouseRightZoom==false)
    {
        my->resize(scrollarea->width(),scrollarea->height());
        my->refreshPixmap();
    }
}

void MainWindow::on_actionCombineFiles_triggered()
{
    combinefiles->show();
}

void MainWindow::combineFilesIntoOne()
{
    if(combinefiles->combineSuccess==true)
    {
        /*              打开选择的多文件           */
        QFile f[combinefiles->fileNumbers];
        for(int i=0;i<combinefiles->fileNumbers;i++)
        {
            QString currentName=combinefiles->fileNames.at(i);
            //qDebug()<<currentName;
            f[i].setFileName(currentName);
            //qDebug()<<f[i].fileName();
            if (!f[i].open(QIODevice::ReadOnly))
                f[i].close();
            //qDebug()<<i;
        }

        /*            打开合并后的文件            */
        combinefiles->combineFileName=combinefiles->m_ui->lineCombineFile->text();
        fAfterCombine.setFileName(combinefiles->combineFileName);
        if (!fAfterCombine.open(QIODevice::WriteOnly))
            fAfterCombine.close();

        /*            复制第一个文件            */
        QByteArray file1Array=f[0].readAll();
        fAfterCombine.write(file1Array);
        f[0].close();

        /*            确定后续文件数据位置            */
        QByteArray str;
        QByteArray rn;
        file2IsWindowsEnter=0;

        //判断file2文件回车字符的字节数
        f[1].seek(80);
        rn=f[1].read(2);
        if(rn=="\r\n")
        {
            //qDebug()<<"isWindowsEnter";
            file2IsWindowsEnter=1;
        }

        //找到file2文件的数据起始位置
        f[1].seek(0);
        for(file2FinalLine=1;file2FinalLine<200;file2FinalLine++)
        {
            str=f[1].read(1);
            if(str=="S"||str=="X"||str=="R")
            {
                break;
            }
            f[1].seek(f[1].pos()+80+file2IsWindowsEnter);
        }
        //qDebug()<<file2FinalLine;

        /*            复制余下的文件            */
        for(int j=1;j<combinefiles->fileNumbers;j++)
        {
            f[j].seek((file2FinalLine-1)*(81+file2IsWindowsEnter));
            QByteArray fileRest=f[j].readAll();
            fAfterCombine.write(fileRest);
            f[j].close();

        }
        fAfterCombine.close();
    }
    else if(combinefiles->combineSuccess==false)
        return;
}


void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,tr("Made by QT"));
}

void MainWindow::on_actionClose_triggered()
{
    exit(0);
}

void MainWindow::on_actionShotLine_triggered()
{
    if(ui->actionShotLine->isChecked())
    {
        my->shotON=true;
        if(ui->actionReceiveLine->isChecked())
            ui->actionRelation->setEnabled(true);
    }
    else
    {
        my->shotON=false;
        ui->actionRelation->setEnabled(false);
        ui->actionRelation->setChecked(false);
    }

    my->update();
}

void MainWindow::on_actionReceiveLine_triggered()
{
    if(ui->actionReceiveLine->isChecked())
    {
        my->receiveON=true;
        if(ui->actionShotLine->isChecked())
            ui->actionRelation->setEnabled(true);
    }
    else
    {
        my->receiveON=false;
        ui->actionRelation->setEnabled(false);
        ui->actionRelation->setChecked(false);
    }

    my->update();
}

void MainWindow::on_actionFoldNumbers_triggered()
{
    if(my->flagZheng==true)
    {
        if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataA==false)
        {
            my->setFoldNumbers();
            my->foldIsChanged=true;
            my->foldModeON=true;
            my->oldW=my->width();
            my->oldH=my->height();
            countFold++;
            my->alreadySetFoldDataA=true;

        }
        else if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataA==true)
        {
            my->foldModeON=true;

            if(countFold>0)
            {
                my->newW=my->width();
                my->newH=my->height();
            }
            if(my->newW-my->oldW!=0 && my->newH-my->oldH!=0)
            {

                my->foldIsChanged=true;
            }
            else
            {

                my->foldIsChanged=false;
            }

            countFold++;

            my->oldW=my->width();
            my->oldH=my->height();
        }
        else
        {
            my->foldModeON=false;
            statusLabel4->setText("");
            statusLabel5->setText("");
        }
    }
    else if(my->flagXie==true)
    {

        if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataB==false)
        {
            my->foldModeON=true;
            my->alreadySetFoldDataB=true;

            my->foldIsChanged=true;
            my->axisTransform();
            my->setFoldTransform();
            my->oldW=my->width();
            my->oldH=my->height();
            countFold++;

        }
        else if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataB==true)
        {
            my->foldModeON=true;
            if(countFold>0)
            {
                my->newW=my->width();
                my->newH=my->height();
            }
            if(my->newW-my->oldW!=0 && my->newH-my->oldH!=0)
            {

                my->foldIsChanged=true;
            }
            else
            {

                my->foldIsChanged=false;
            }
            countFold++;

            my->oldW=my->width();
            my->oldH=my->height();
        }
        else
        {

            my->foldModeON=false;
            statusLabel4->setText("");
            statusLabel5->setText("");
        }
    }
    my->refreshPixmap();
}

void MainWindow::on_actionCMP_triggered()
{
    if(ui->actionCMP->isChecked() && my->alreadySetCMP==false)
    {
        my->cmpON=true;
        my->alreadySetCMP=true;

        my->cmpIsChanged=true;
        ui->actionRelation->setEnabled(false);
        ui->actionRelation->setChecked(false);
        my->oldW=my->width();
        my->oldH=my->height();
        countCMP++;
        my->setCMP();
    }
    else if(ui->actionCMP->isChecked() && my->alreadySetCMP==true)
    {
        my->cmpON=true;
        countCMP++;
        if(countCMP>0)
        {
            my->newW=my->width();
            my->newH=my->height();
        }
        if(my->newW-my->oldW!=0 && my->newH-my->oldH!=0)
        {

            my->cmpIsChanged=true;
        }
        else
        {

            my->cmpIsChanged=false;
        }

        my->oldW=my->width();
        my->oldH=my->height();

        ui->actionRelation->setEnabled(false);
        ui->actionRelation->setChecked(false);
    }
    else
    {
        my->cmpON=false;
        if(ui->actionShotLine->isChecked() && ui->actionReceiveLine->isChecked())
            ui->actionRelation->setEnabled(true);
    }
    my->refreshPixmap();
}

void MainWindow::on_actionShotPointLine_triggered()
{
    if(ui->actionShotPointLine->isChecked() && my->alreadySetShotData==false)
    {
        my->shotPointLineON=true;
        my->setShotPointLine();
        statusLabel4->setText(tr("Loading Completed"));
        my->alreadySetShotData=true;
    }
    else if(ui->actionShotPointLine->isChecked() && my->alreadySetShotData==true)
    {
        my->shotPointLineON=true;
    }
    else
    {
        my->shotPointLineON=false;
        statusLabel4->setText("");
    }
    my->update();

}

void MainWindow::on_actionReceivePointLine_triggered()
{
    if(ui->actionReceivePointLine->isChecked())
    {
        my->receivePointLineON=true;
    }
    else
    {
        my->receivePointLineON=false;
    }
    my->update();
}


void MainWindow::on_actionOption_triggered()
{
    if(my->flagZheng==true)
    {
        option->m_ui->spinSingleWid->setValue((int)my->singleWid);
        option->m_ui->spinSingleHei->setValue((int)my->singleHei);
    }
    if(my->flagXie==true)
    {
        option->m_ui->spinSingleWid->setValue((int)my->singleWidT);
        option->m_ui->spinSingleHei->setValue((int)my->singleHeiT);
    }
    option->show();
    //int width=QApplication::desktop()->width();         //获取屏幕的分辨率
    int height=QApplication::desktop()->height();
    option->move(0,(height/2)-300);
}

void MainWindow::applyChange()
{
    // 修改网格大小，改变显示
    if(my->flagZheng==true)
    {
        int a=option->m_ui->spinSingleWid->value();
        int b=option->m_ui->spinSingleHei->value();
        if(my->singleWid!=a || my->singleHei!=b)
        {
            my->singleWid=a;
            my->singleHei=b;
            my->setFoldNumbers();
            my->foldIsChanged=true;
        }
    }
    if(my->flagXie==true)
    {
        int a=option->m_ui->spinSingleWid->value();
        int b=option->m_ui->spinSingleHei->value();
        if(my->singleWidT!=a || my->singleHeiT!=b)
        {
            my->singleWidT=a;
            my->singleHeiT=b;
            my->axisTransform();
            my->setFoldTransform();
            my->foldIsChanged=true;
        }
    }

    if(option->isIndex_0==1)
    {
        my->zero=1;
        my->one= 0;
        my->two=0;
        my->three=0;
        my->four=0;
        my->five=0;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_1==1)
    {
        my->zero=0;
        my->one= 1;
        my->two=0;
        my->three=0;
        my->four=0;
        my->five=0;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_2==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=1;
        my->three=0;
        my->four=0;
        my->five=0;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_3==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=0;
        my->three=1;
        my->four=0;
        my->five=0;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_4==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=0;
        my->three=0;
        my->four=1;
        my->five=0;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_5==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=0;
        my->three=0;
        my->four=0;
        my->five=1;
        my->six=0;
        my->seven=0;
    }
    if(option->isIndex_6==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=0;
        my->three=0;
        my->four=0;
        my->five=0;
        my->six=1;
        my->seven=0;
    }
    if(option->isIndex_7==1)
    {
        my->zero=0;
        my->one= 0;
        my->two=0;
        my->three=0;
        my->four=0;
        my->five=0;
        my->six=0;
        my->seven=1;
    }

    my->refreshPixmap();
}

void MainWindow::on_actionHelp_triggered()
{
    help->show();
}

void MainWindow::setProgressBar(int max)
{
    pBar->show();
    pBar->setMaximum(max);
    pBar->setValue(0);
}

void MainWindow::setProgressBarValue(int value)
{
    pBar->setValue(value);
}

void MainWindow::hideBar()
{
    pBar->hide();
}


void MainWindow::setShotLineColorMain(QColor clr, double db)
{
    shotColor=clr;
    shotValue=db;
}
void MainWindow::setShotLineShapeMain(int n,int x)
{
    switch(n)
    {
    case 1:
        flagSLAdd=true;
        flagSLMul=false;
        flagSLBox=false;
        break;
    case 2:
        flagSLAdd=false;
        flagSLMul=true;
        flagSLBox=false;
        break;
    case 3:
        flagSLAdd=false;
        flagSLMul=false;
        flagSLBox=true;
        break;
    }
    SLSize=x;
}

void MainWindow::setReceiveLineColorMain(QColor clr, double db)
{
    receiveColor=clr;
    receiveValue=db;
}
void MainWindow::setReceiveLineShapeMain(int n,int x)
{
    switch(n)
    {
    case 1:
        flagRLAdd=true;
        flagRLMul=false;
        flagRLBox=false;
        break;
    case 2:
        flagRLAdd=false;
        flagRLMul=true;
        flagRLBox=false;
        break;
    case 3:
        flagRLAdd=false;
        flagRLMul=false;
        flagRLBox=true;
        break;
    }
    RLSize=x;
}

void MainWindow::setCMPColorMain(QColor clr, double db)
{
    CMPColor=clr;
    CMPValue=db;
}
void MainWindow::setCMPShapeMain(int n,int x)
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
    CMPSize=x;
}
