#include "qjd_sps_mainwindow.h"
#include "ui_qjd_sps_mainwindow.h"
#include <QFileDialog>
#include <QRubberBand>
#include <QtGui>
#include <QGridLayout>
#include <stdlib.h>
#include <stdio.h>
#define Num 100

qjdMainWindow::qjdMainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    my = new qjdWidget();
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
    my->alreadySetFoldDataZheng=false;
    my->alreadySetFoldDataXie=false;
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

    label1->setFixedHeight(25); //空出上面 25
    label2->setFixedWidth(80);  //左面 80
    label3->setFixedWidth(80);  //右面 80
    label4->setFixedHeight(40); //下面 40

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

    openfile= new qjdOpenFile();               //其他类的对象的创建
    combinefiles= new qjdCombineFiles();
    option= new qjdOption();
    help = new qjdHelp();

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

qjdMainWindow::~qjdMainWindow()
{
    delete ui;
}

void qjdMainWindow::frontOpen()
{
    if(openfile->openSuccess==true)
    {
        my->rON=false;
        my->sON=false;
        my->slinename.clear();
        my->spointnumber.clear();
        my->estS.clear();
        my->norS.clear();
        my->xlinename.clear();
        my->xpointnumber.clear();
        my->xreceivelinename.clear();
        my->xfromreceiver.clear();
        my->xtoreceiver.clear();
        my->rlinename.clear();
        my->rpointnumber.clear();
        my->estR.clear();
        my->norR.clear();

        openfile->SfileName = openfile->m_ui->lineSFile->text();
        openfile->RfileName = openfile->m_ui->lineRFile->text();
        openfile->XfileName = openfile->m_ui->lineXFile->text();

        fsps.setFileName(openfile->SfileName);
        frps.setFileName(openfile->RfileName);
        fxps.setFileName(openfile->XfileName);
        if (!fsps.open(QIODevice::ReadOnly))
            fsps.close();
        if (!frps.open(QIODevice::ReadOnly))
            frps.close();
        if (!fxps.open(QIODevice::ReadOnly))
            fxps.close();

        setWindowTitle(tr("SPS File Show ---- ")+fsps.fileName());
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

        my->alreadySetFoldDataZheng=false;
        my->alreadySetFoldDataXie=false;
        my->alreadySetShotData=false;
        my->alreadySetCMP=false;

        my->maxFold=0;
        my->maxFoldT=0;

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
        else
        {

            my->HOldIncrease=1;
            my->VOldIncrease=1;
            ui->actionReset->setEnabled(false);

            my->resize(scrollarea->width(),scrollarea->height());

            my->mouseRightZoom=false;
            HScrollBar->setValue(0);
            VScrollBar->setValue(0);

            /// 新添加
            my->setCMP();
            my->alreadySetCMP=true;
            if(my->flagZheng==true)
            {
                my->setFoldNumbers();
                my->alreadySetFoldDataZheng=true;
            }
            if(my->flagXie==true)
            {
                my->axisTransform();
                my->setFoldTransform();
                my->alreadySetFoldDataXie=true;
            }
            my->foldIsChanged=true;
            my->cmpIsChanged=true;
        }
        /// 显示
        my->refreshPixmap();
    }
    else if(openfile->openSuccess==false)
    {
        return;
    }
}

void qjdMainWindow::on_actionOpen_triggered()
{
    openfile->show();
    int width=QApplication::desktop()->width();         //获取屏幕的分辨率
    int height=QApplication::desktop()->height();
    openfile->move(width/2-100,height/2-100);
}

void qjdMainWindow::setFileLocation()
{
    /// windows是回车换行'\r\n',linux下面为'\n'
    isWindowsEnter=0;
    QByteArray str;
    QByteArray rn;

    //判断S文件回车字符的字节数
    fsps.seek(80);
    rn=fsps.read(2);
    if(rn=="\r\n")
    {
        isWindowsEnter=1;
    }
    //找到S文件的数据起始位置
    fsps.seek(0);
    for(firstLineS=1;firstLineS<200;firstLineS++)
    {
        str=fsps.read(1);
        if(str=="S"||str=="X"||str=="R")
        {
            break;
        }
        fsps.seek(fsps.pos()+80+isWindowsEnter);
    }
    firstLineS=firstLineS-1;

    //找到R文件的数据起始位置
    frps.seek(0);
    for(firstLineR=1;firstLineR<200;firstLineR++)
    {
        str=frps.read(1);
        if(str=="S"||str=="X"||str=="R")
        {
            break;
        }
        frps.seek(frps.pos()+80+isWindowsEnter);
    }
    firstLineR=firstLineR-1;

    //找到X文件的数据起始位置
    fxps.seek(0);
    for(firstLineX=1;firstLineX<200;firstLineX++)
    {
        str=fxps.read(1);
        if(str=="S"||str=="X"||str=="R")
        {
            break;
        }
        fxps.seek(fxps.pos()+80+isWindowsEnter);
    }
    firstLineX=firstLineX-1;

    my->SNumber=0;
    my->RNumber=0;
    my->XNumber=0;
    //找到S文件的数据结束位置
    fsps.seek(0);
    while(!fsps.atEnd())
    {
        str=fsps.read(1);
        if(str=="S")
        {
            my->SNumber++;
        }
        fsps.seek(fsps.pos()+80+isWindowsEnter);
    }
    qDebug()<<finalLineS;

    //找到R文件的数据结束位置
    frps.seek(0);
    while(!frps.atEnd())
    {
        str=frps.read(1);
        if(str=="R")
        {
            my->RNumber++;
        }
        frps.seek(frps.pos()+80+isWindowsEnter);
    }
    //找到X文件的数据结束位置
    fxps.seek(0);
    while(!fxps.atEnd())
    {
        str=fxps.read(1);
        if(str=="X")
        {
            my->XNumber++;
        }
        fxps.seek(fxps.pos()+80+isWindowsEnter);
    }
    qDebug()<<firstLineS<<firstLineR<<firstLineX;
    qDebug()<<my->SNumber<<my->RNumber<<my->XNumber;
}

void qjdMainWindow::mouseMoveEvent ( QMouseEvent *event )
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

void qjdMainWindow::mousePressEvent( QMouseEvent *event)
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
            my->decide();       // 判断点击的是炮点还是检波点
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

void qjdMainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
//    my->HOldIncrease=1;
//    my->VOldIncrease=1;
//    ui->actionReset->setEnabled(false);
//
//    my->resize(scrollarea->width(),scrollarea->height());
//
//    my->mouseRightZoom=false;
//    HScrollBar->setValue(0);
//    VScrollBar->setValue(0);
//
//    my->refreshPixmap();
}

void qjdMainWindow::mouseReleaseEvent ( QMouseEvent *event )
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

        my->refreshPixmap();
    }


}

void qjdMainWindow::setData()
{
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
    my->slinename.resize(my->SNumber);
    my->spointnumber.resize(my->SNumber);
    my->estS.resize(my->SNumber);
    my->norS.resize(my->SNumber);
    my->estDrawS.resize(my->SNumber);
    my->norDrawS.resize(my->SNumber);

    fsps.seek(firstLineS*(81+plusEnter)+1);
    //    while(!fsps.atEnd())
    for(int i=0;i<my->SNumber;i++)
    {
        fsps.readLine(Slinename,17);
        my->slinename[i]=atof(Slinename);
        fsps.readLine(Spointnumber,9);
        my->spointnumber[i]=atof(Spointnumber);

        //        qDebug()<<Slinename;
        fsps.seek(fsps.pos()+21);
        fsps.readLine(EstS,10);
        my->estS[i]=atof(EstS);
        fsps.readLine(NorS,11);
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

        fsps.seek(fsps.pos()+17+plusEnter);
    }
    ////------------------------R文件数据处理---------------------------//
    //    my->RNumber=0;
    //    frps.seek(firstLineR*(81+plusEnter));
    //    while(!frps.atEnd())
    //    {
    //        my->RNumber++;
    //        frps.seek(frps.pos()+81+plusEnter);
    //    }
    my->rlinename.resize(my->RNumber);
    my->rpointnumber.resize(my->RNumber);
    my->estR.resize(my->RNumber);
    my->norR.resize(my->RNumber);
    my->estDrawR.resize(my->RNumber);
    my->norDrawR.resize(my->RNumber);

    frps.seek(firstLineR*(81+plusEnter)+1);
    //    while(!frps.atEnd())
    for(int j=0;j<my->RNumber;j++)
    {
        frps.readLine(Rlinename,17);
        my->rlinename[j]=atof(Rlinename);
        frps.readLine(Rpointnumber,9);
        my->rpointnumber[j]=atof(Rpointnumber);

        frps.seek(frps.pos()+21);
        frps.readLine(EstR,10);
        my->estR[j]=atof(EstR);
        frps.readLine(NorR,11);
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
        //        j++;

        frps.seek(frps.pos()+17+plusEnter);
    }
    my->wid=my->maxE-my->minE;
    my->hei=my->maxN-my->minN;
    //    qDebug()<<my->maxN<<my->minN;
    my->minDrawE=my->minE-my->wid*0.1;
    my->maxDrawE=my->maxE+my->wid*0.1;
    my->minDrawN=my->minN-my->hei*0.1;
    my->maxDrawN=my->maxN+my->hei*0.1;

    my->drawWid=my->maxDrawE-my->minDrawE;
    my->drawHei=my->maxDrawN-my->minDrawN;

    //    qDebug()<<my->drawWid<<my->drawHei;
    ////------------------------X文件数据处理----------------------//
    //    my->XNumber=0;
    //    fxps.seek(firstLineX*(81+plusEnter));
    //    while(!fxps.atEnd())
    //    {
    //        my->XNumber++;
    //        fxps.seek(fxps.pos()+81+plusEnter);
    //    }
    my->xlinename.resize(my->XNumber);
    my->xpointnumber.resize(my->XNumber);
    my->xreceivelinename.resize(my->XNumber);
    my->xfromreceiver.resize(my->XNumber);
    my->xtoreceiver.resize(my->XNumber);

    fxps.seek(firstLineX*(81+plusEnter)+13);
    //    while(!fxps.atEnd())
    for(int k=0;k<my->XNumber;k++)
    {
        fxps.readLine(Xlinename,17);
        my->xlinename[k]=atof(Xlinename);

        fxps.readLine(Xpointnumber,9);
        my->xpointnumber[k]=atof(Xpointnumber);

        fxps.seek(fxps.pos()+10);

        fxps.readLine(Xreceivelinename,17);
        my->xreceivelinename[k]=atof(Xreceivelinename);

        fxps.readLine(XFromreceiver,9);
        my->xfromreceiver[k]=atof(XFromreceiver);

        fxps.readLine(XToreceiver,9);
        my->xtoreceiver[k]=atof(XToreceiver);
        //qDebug()<<my->xlinename[k]<<my->xpointnumber[k]<<my->xreceivelinename[k]<<my->xfromreceiver[k]<<my->xtoreceiver[k];
        //        k++;

        fxps.seek(fxps.pos()+15+plusEnter);
    }
    //  qDebug()<<my->SNumber<<my->RNumber<<my->XNumber;
    fsps.close();
    frps.close();
    fxps.close();

}

void qjdMainWindow::on_actionReset_triggered()
{
    my->HOldIncrease=1;
    my->VOldIncrease=1;
    ui->actionReset->setEnabled(false);

    my->resize(scrollarea->width(),scrollarea->height());

    my->mouseRightZoom=false;
    HScrollBar->setValue(0);
    VScrollBar->setValue(0);

    my->refreshPixmap();
}

void qjdMainWindow::paintEvent(QPaintEvent *)
{
    HBarValue=HScrollBar->value();
    VBarValue=VScrollBar->value();
    HBarMax=HScrollBar->maximum();
    VBarMax=VScrollBar->maximum();

    QPainter painter(this);
    paintCor(&painter);
}

void qjdMainWindow::paintCor(QPainter *painter)
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
    //Axis X
    painter->drawLine(point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height(),
                      scrollarea->width()+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+more+ui->menuBar->height());
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

    //Axis Y
    // 右边
    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x(),scrollarea->height()+40+ui->mainToolBar->height()+ui->menuBar->height());
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

    // 左边
    if(my->foldModeON==false)
    {
        painter->drawLine(point.x()-more,40+ui->mainToolBar->height()+ui->menuBar->height(),
                          point.x()-more,scrollarea->height()+40+ui->mainToolBar->height()+ui->menuBar->height());
        for(int y=0;y<=(scrollarea->height()/100);y++)
        {
            painter->drawLine(-more+point.x(),40+ui->mainToolBar->height()+scrollarea->height()-y*100+ui->menuBar->height(),
                              -more+point.x()+6,40+ui->mainToolBar->height()+scrollarea->height()-y*100+ui->menuBar->height());
        }
        for(int y=0;y<(scrollarea->height()/20);y++)
        {
            painter->drawLine(-more+point.x(),40+ui->mainToolBar->height()+scrollarea->height()-y*20+ui->menuBar->height(),
                              -more+point.x()+3,40+ui->mainToolBar->height()+scrollarea->height()-y*20+ui->menuBar->height());
        }
    }

    // 画个N
    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x()-2,40+ui->mainToolBar->height()+ui->menuBar->height()+5);
    painter->drawLine(scrollarea->width()+more+point.x(),40+ui->mainToolBar->height()+ui->menuBar->height(),
                      scrollarea->width()+more+point.x()+2,40+ui->mainToolBar->height()+ui->menuBar->height()+5);
    painter->drawText(scrollarea->width()+more+point.x()-4,40+ui->mainToolBar->height()+ui->menuBar->height()-7,"N");

    /*----------------------------------------------------------------------------------*/
    /*                           写坐标值                          */
    /*----------------------------------------------------------------------------------*/

    painter->setLayoutDirection(Qt::LeftToRight);
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

            if(my->foldModeON==false)
            {
                painter->drawText(10,
                                  40+ui->mainToolBar->height()+scrollarea->height()-100*y+5+ui->menuBar->height(),
                                  b);
            }
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

void qjdMainWindow::on_actionRelation_triggered()
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

void qjdMainWindow::resizeEvent (QResizeEvent * )
{

    //    my->alreadySetShotData;
    if(my->mouseRightZoom==false)
    {
        my->resize(scrollarea->width(),scrollarea->height());
        my->refreshPixmap();
    }
}

void qjdMainWindow::on_actionCombineFiles_triggered()
{
    combinefiles->show();
}

void qjdMainWindow::combineFilesIntoOne()
{
    if(combinefiles->combineSuccess==true)
    {
        /*              打开选择的多文件           */
        QFile f[combinefiles->fileNumbers];
        for(int i=0;i<combinefiles->fileNumbers;i++)
        {
            QString currentName=combinefiles->fileNames.at(i);
            f[i].setFileName(currentName);
            if (!f[i].open(QIODevice::ReadOnly))
                f[i].close();
        }

        /*            打开合并后的文件            */
        combinefiles->combineFileName=combinefiles->m_ui->lineCombineFile->text();
        fAfterCombine.setFileName(combinefiles->combineFileName);
        if (!fAfterCombine.open(QIODevice::WriteOnly))
            fAfterCombine.close();

        /*            复制第一个文件            */
        QByteArray fileArray;
        QByteArray str;

        f[0].seek(0);
        while(!f[0].atEnd())
        {
            str=f[0].read(1);
            if(str=="S" || str=="R" || str=="X" || str=="H")
            {
                fileArray.append(str);
                fileArray.append(f[0].readLine(100));
            }
        }
        fAfterCombine.write(fileArray);
        f[0].close();
        fileArray.clear();     //不要忘记清空

        /*            复制后续文件数据位置            */
        for(int j=1;j<combinefiles->fileNumbers;j++)
        {
            //找到数据并复制
            f[j].seek(0);
            while(!f[j].atEnd())
            {
                str=f[j].read(1);
                if(str=="H")
                {
                    f[j].seek(f[j].pos()+80);
                }
                if(str=="S"||str=="X"||str=="R")
                {
                    fileArray.append(str);
                    fileArray.append(f[j].readLine(100));
                }
            }
            fAfterCombine.write(fileArray);
            fileArray.clear();
            f[j].close();
        }
        fAfterCombine.close();
        combinefiles->reset();
    }
    else if(combinefiles->combineSuccess==false)
        return;
}


void qjdMainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,tr("Made by QT"));
}

void qjdMainWindow::on_actionClose_triggered()
{
    exit(0);
}

void qjdMainWindow::on_actionShotLine_triggered()
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

void qjdMainWindow::on_actionReceiveLine_triggered()
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

void qjdMainWindow::on_actionFoldNumbers_triggered()
{
    if(my->flagZheng==true)
    {
        if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataZheng==false)
        {
            qDebug()<<"false";
            my->setFoldNumbers();
            //            my->foldIsChanged=true;
            my->foldModeON=true;
            my->alreadySetFoldDataZheng=true;

        }
        else if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataZheng==true)
        {
            my->foldModeON=true;
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

        if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataXie==false)
        {
            my->foldModeON=true;
            my->alreadySetFoldDataXie=true;

            my->axisTransform();
            my->setFoldTransform();
        }
        else if(ui->actionFoldNumbers->isChecked() && my->alreadySetFoldDataXie==true)
        {
            my->foldModeON=true;
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

void qjdMainWindow::on_actionCMP_triggered()
{
    if(ui->actionCMP->isChecked() && my->alreadySetCMP==false)
    {
        my->cmpON=true;
        my->alreadySetCMP=true;

        my->cmpIsChanged=true;
        ui->actionRelation->setEnabled(false);
        ui->actionRelation->setChecked(false);
        my->setCMP();
    }
    else if(ui->actionCMP->isChecked() && my->alreadySetCMP==true)
    {
        my->cmpON=true;

    }
    else
    {
        my->cmpON=false;
    }
    my->refreshPixmap();
}

void qjdMainWindow::on_actionShotPointLine_triggered()
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

void qjdMainWindow::on_actionReceivePointLine_triggered()
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


void qjdMainWindow::on_actionOption_triggered()
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

void qjdMainWindow::applyChange()
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

void qjdMainWindow::on_actionHelp_triggered()
{
    help->show();
}

void qjdMainWindow::setProgressBar(int max)
{
    pBar->show();
    pBar->setMaximum(max);
    pBar->setValue(0);
}

void qjdMainWindow::setProgressBarValue(int value)
{
    pBar->setValue(value);
}

void qjdMainWindow::hideBar()
{
    pBar->hide();
}


void qjdMainWindow::setShotLineColorMain(QColor clr, double db)
{
    shotColor=clr;
    shotValue=db;
}
void qjdMainWindow::setShotLineShapeMain(int n,int x)
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

void qjdMainWindow::setReceiveLineColorMain(QColor clr, double db)
{
    receiveColor=clr;
    receiveValue=db;
}
void qjdMainWindow::setReceiveLineShapeMain(int n,int x)
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

void qjdMainWindow::setCMPColorMain(QColor clr, double db)
{
    CMPColor=clr;
    CMPValue=db;
}
void qjdMainWindow::setCMPShapeMain(int n,int x)
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
