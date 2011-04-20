#include "qjd_sps_option.h"
#include "ui_qjd_sps_option.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QFile>
qjdOption::qjdOption(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::Option)
{
    m_ui->setupUi(this);

    QFile file(":/styles/stylesheet.qss");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString s = in.readAll();
    this->setStyleSheet(s);

    isIndex_0=0;
    isIndex_1=0;
    isIndex_2=0;
    isIndex_3=0;
    isIndex_4=0;
    isIndex_5=0;
    isIndex_6=0;
    isIndex_7=0;

    m_ui->comboColorTable->insertItem(0,"0","");
    m_ui->comboColorTable->insertItem(1,"1","");
    m_ui->comboColorTable->insertItem(2,"2","");
    m_ui->comboColorTable->insertItem(3,"3","");
    m_ui->comboColorTable->insertItem(4,"4","");
    m_ui->comboColorTable->insertItem(5,"5","");
    m_ui->comboColorTable->insertItem(6,"6","");
    m_ui->comboColorTable->insertItem(7,"7","");

    m_ui->comboColorTable->setCurrentIndex(1);

    QSize size(100,20);
    //黑白色表
    QIcon index_0(":/new/prefix1/image/index_0.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(0,index_0);

    //彩色色表
    QIcon index_1(":/new/prefix1/image/index_1.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(1,index_1);

    QIcon index_2(":/new/prefix1/image/index_2.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(2,index_2);

    QIcon index_3(":/new/prefix1/image/index_3.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(3,index_3);

    QIcon index_4(":/new/prefix1/image/index_4.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(4,index_4);

    QIcon index_5(":/new/prefix1/image/index_5.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(5,index_5);

    QIcon index_6(":/new/prefix1/image/index_6.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(6,index_6);

    QIcon index_7(":/new/prefix1/image/index_7.png");
    m_ui->comboColorTable->setIconSize(size);
    m_ui->comboColorTable->setItemIcon(7,index_7);

    // 默认的颜色
    m_ui->btnShotLineSC->setPalette(QPalette(Qt::blue));
    m_ui->btnReceiverLineSC->setPalette(QPalette(Qt::red));
    m_ui->btnMouseClickedSC->setPalette(QPalette(Qt::green));
    m_ui->btnMouseRelationSCSL->setPalette(QPalette(Qt::yellow));
    m_ui->btnMouseRelationSCRL->setPalette(QPalette(Qt::black));
    m_ui->btnShotLineConSC->setPalette(QPalette(Qt::blue));
    m_ui->btnReceiveLineConSC->setPalette(QPalette(Qt::red));
    m_ui->btnCMPSC->setPalette(QPalette(Qt::green));

    shotLineColor=QColor(Qt::blue);
    receiveLineColor=QColor(Qt::red);
    mouseClickedColor=QColor(Qt::green);
    shotLineRelatedColor=QColor(Qt::yellow);
    receiveLineRelatedColor=QColor(Qt::black);
    shotLineConColor=QColor(Qt::blue);
    receiveLineConColor=QColor(Qt::red);
    CMP_Color=QColor(Qt::green);

    //线条默认粗细
    m_ui->spinShotLine->setValue(1);
    m_ui->spinReceiveLine->setValue(0.5);
    m_ui->spinMouseClicked->setValue(2);
    m_ui->spinShotLineRelated->setValue(1);
    m_ui->spinReceiveLineRelated->setValue(2);
    m_ui->spinShotLineCon->setValue(1);
    m_ui->spinReceiveLineCon->setValue(0.5);
    m_ui->spinCMP->setVisible(0.1);

    shotLineValue=1;
    receiveLineValue=0.5;
    mouseClickedValue=2;
    shotLineRelatedValue=1;
    receiveLineRelatedValue=2;
    shotLineConValue=1;
    receiveLineConValue=0.5;
    CMP_Value=0.1;

    flagShotLine=false;
    flagReceiveLine=false;
    flagMouseClicked=false;
    flagShotLineRelated=false;
    flagReceiveLineRelated=false;
    flagShotLineCon=false;
    flagReceiveLineCon=false;

    //形状默认大小
    m_ui->spinShotLineSize->setValue(6);
    m_ui->spinReceiveLineSize->setValue(2);
    m_ui->spinMouseClickedSize->setValue(6);
    m_ui->spinCMPSize->setValue(2);


    //radioButton group
    groupShotLine.addButton(m_ui->radioSL_Add);
    groupShotLine.addButton(m_ui->radioSL_Mul);
    groupShotLine.addButton(m_ui->radioSL_Box);

    groupReceiveLine.addButton(m_ui->radioRL_Add);
    groupReceiveLine.addButton(m_ui->radioRL_Mul);
    groupReceiveLine.addButton(m_ui->radioRL_Box);

    groupMouseClicked.addButton(m_ui->radioMC_Add);
    groupMouseClicked.addButton(m_ui->radioMC_Mul);
    groupMouseClicked.addButton(m_ui->radioMC_Box);

    groupCMP.addButton(m_ui->radioCMP_Add);
    groupCMP.addButton(m_ui->radioCMP_Mul);
    groupCMP.addButton(m_ui->radioCMP_Box);

    // 默认的形状
    m_ui->radioSL_Add->setChecked(true);
    m_ui->radioRL_Add->setChecked(true);
    m_ui->radioMC_Add->setChecked(true);
    m_ui->radioCMP_Add->setChecked(true);

    /// cmp 精度
//    m_ui->comboCMPAccuracy->insertItem(0,"100%");
//    m_ui->comboCMPAccuracy->insertItem(1,"50%");
//    m_ui->comboCMPAccuracy->insertItem(2,"25%");
//    m_ui->comboCMPAccuracy->insertItem(3,"10%");

    /// 乱设layout 会断错误
        //m_ui->tabWidget->layout()->setSizeConstraint(QLayout::SetFixedSize);
//        layout()->setSizeConstraint(QLayout::SetFixedSize);

}

qjdOption::~qjdOption()
{
    delete m_ui;
}

void qjdOption::changeEvent(QEvent *e)
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

void qjdOption::on_btnApply_clicked()
{
    if(m_ui->comboColorTable->currentIndex()==0)
    {
        isIndex_0=1;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==1)
    {
        isIndex_0=0;
        isIndex_1=1;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==2)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=1;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==3)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=1;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==4)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=1;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==5)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=1;
        isIndex_6=0;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==6)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=1;
        isIndex_7=0;
    }
    if(m_ui->comboColorTable->currentIndex()==7)
    {
        isIndex_0=0;
        isIndex_1=0;
        isIndex_2=0;
        isIndex_3=0;
        isIndex_4=0;
        isIndex_5=0;
        isIndex_6=0;
        isIndex_7=1;
    }

    //颜色
    if(flagShotLine==true)
        emit signalShotLineColor(shotLineColor,shotLineValue);
    if(flagReceiveLine==true)
        emit signalReceiveLineColor(receiveLineColor,receiveLineValue);
    if(flagMouseClicked==true)
        emit signalMouseClickedColor(mouseClickedColor,mouseClickedValue);
    if(flagShotLineRelated==true)
        emit signalMouseClickedSLColor(shotLineRelatedColor,shotLineRelatedValue);
    if(flagReceiveLineRelated==true)
        emit signalMouseClickedRLColor(receiveLineRelatedColor,receiveLineRelatedValue);
    if(flagShotLineCon==true)
        emit signalShotLineConColor(shotLineConColor,shotLineConValue);
    if(flagReceiveLineCon==true)
        emit signalReceiveLineConColor(receiveLineConColor,receiveLineConValue);
    if(flagCMP==true)
        emit signalCMP(CMP_Color,CMP_Value);

    flagShotLine=0;
    flagReceiveLine=0;
    flagMouseClicked=0;
    flagShotLineRelated=0;
    flagReceiveLineRelated=0;
    flagShotLineCon=0;
    flagReceiveLineCon=0;

    //决定形状
    decideShape();

}

void qjdOption::on_btnClose_clicked()
{
    close();
}

void qjdOption::on_btnShotLineSC_clicked()
{
    QColorDialog a;
    shotLineColor = a.getColor();
    if (shotLineColor.isValid()) {
        m_ui->btnShotLineSC->setPalette(QPalette(shotLineColor));
        flagShotLine=1;
    }
    else flagShotLine=0;
}

void qjdOption::on_btnReceiverLineSC_clicked()
{
    QColorDialog a;
    receiveLineColor = a.getColor();
    if (receiveLineColor.isValid()) {
        m_ui->btnReceiverLineSC->setPalette(QPalette(receiveLineColor));
        flagReceiveLine=1;
    }
    else flagReceiveLine=0;
}

void qjdOption::on_btnMouseClickedSC_clicked()
{
    QColorDialog a;
    mouseClickedColor = a.getColor();
    if (mouseClickedColor.isValid()) {
        m_ui->btnMouseClickedSC->setPalette(QPalette(mouseClickedColor));
        flagMouseClicked=1;
    }
    else flagMouseClicked=0;
}

void qjdOption::on_btnMouseRelationSCSL_clicked()
{
    QColorDialog a;
    shotLineRelatedColor = a.getColor();
    if (shotLineRelatedColor.isValid()) {
        m_ui->btnMouseRelationSCSL->setPalette(QPalette(shotLineRelatedColor));
        flagShotLineRelated=1;
    }
    else flagShotLineRelated=0;
}

void qjdOption::on_btnMouseRelationSCRL_clicked()
{
    QColorDialog a;
    receiveLineRelatedColor = a.getColor();
    if (receiveLineRelatedColor.isValid()) {
        m_ui->btnMouseRelationSCRL->setPalette(QPalette(receiveLineRelatedColor));
        flagReceiveLineRelated=1;
    }
    else flagReceiveLineRelated=0;
}

void qjdOption::on_btnShotLineConSC_clicked()
{
    QColorDialog a;
    shotLineConColor = a.getColor();
    if (shotLineConColor.isValid()) {
        m_ui->btnShotLineConSC->setPalette(QPalette(shotLineConColor));
        flagShotLineCon=1;
    }
    else flagShotLineCon=0;
}

void qjdOption::on_btnReceiveLineConSC_clicked()
{
    QColorDialog a;
    receiveLineConColor = a.getColor();
    if (receiveLineConColor.isValid()) {
        m_ui->btnReceiveLineConSC->setPalette(QPalette(receiveLineConColor));
        flagReceiveLineCon=1;
    }
    else flagReceiveLineCon=0;
}

void qjdOption::on_btnCMPSC_clicked()
{
    QColorDialog a;
    CMP_Color = a.getColor();
    if (CMP_Color.isValid()) {
        m_ui->btnCMPSC->setPalette(QPalette(CMP_Color));
        flagCMP=1;
    }
    else flagCMP=0;
}

void qjdOption::on_spinShotLine_valueChanged(QString s)
{
    shotLineValue=s.toDouble();
    flagShotLine=1;
}

void qjdOption::on_spinReceiveLine_valueChanged(QString s)
{
    receiveLineValue=s.toDouble();
    flagReceiveLine=1;
}

void qjdOption::on_spinMouseClicked_valueChanged(QString s)
{
    mouseClickedValue=s.toDouble();
    flagMouseClicked=1;
}

void qjdOption::on_spinShotLineRelated_valueChanged(QString s)
{
    shotLineRelatedValue=s.toDouble();
    flagShotLineRelated=1;
}

void qjdOption::on_spinReceiveLineRelated_valueChanged(QString s)
{
    receiveLineRelatedValue=s.toDouble();
    flagReceiveLineRelated=1;
}

void qjdOption::on_spinShotLineCon_valueChanged(QString s)
{
    shotLineConValue=s.toDouble();
    flagShotLineCon=1;
}

void qjdOption::on_spinReceiveLineCon_valueChanged(QString s)
{
    receiveLineConValue=s.toDouble();
    flagReceiveLineCon=1;
}

void qjdOption::on_spinCMP_valueChanged(QString s)
{
    CMP_Value=s.toDouble();
    flagCMP=1;
}

void qjdOption::decideShape()
{
    // 炮点
    if(groupShotLine.checkedButton()==m_ui->radioSL_Add)
    {
        int x=m_ui->spinShotLineSize->value();
        emit signalShotLineShape(1,x);
    }
    if(groupShotLine.checkedButton()==m_ui->radioSL_Mul)
    {
        int x=m_ui->spinShotLineSize->value();
        emit signalShotLineShape(2,x);
    }
    if(groupShotLine.checkedButton()==m_ui->radioSL_Box)
    {
        int x=m_ui->spinShotLineSize->value();
        emit signalShotLineShape(3,x);
    }

    //检波点
    if(groupReceiveLine.checkedButton()==m_ui->radioRL_Add)
    {
        int x=m_ui->spinReceiveLineSize->value();
        emit signalReceiveLineShape(1,x);
    }
    if(groupReceiveLine.checkedButton()==m_ui->radioRL_Mul)
    {
        int x=m_ui->spinReceiveLineSize->value();
        emit signalReceiveLineShape(2,x);
    }
    if(groupReceiveLine.checkedButton()==m_ui->radioRL_Box)
    {
        int x=m_ui->spinReceiveLineSize->value();
        emit signalReceiveLineShape(3,x);
    }

    // 鼠标点击点
    if(groupMouseClicked.checkedButton()==m_ui->radioMC_Add)
    {
        int x=m_ui->spinMouseClickedSize->value();
        emit signalMouseClickedShape(1,x);
    }
    if(groupMouseClicked.checkedButton()==m_ui->radioMC_Mul)
    {
        int x=m_ui->spinMouseClickedSize->value();
        emit signalMouseClickedShape(2,x);
    }
    if(groupMouseClicked.checkedButton()==m_ui->radioMC_Box)
    {
        int x=m_ui->spinMouseClickedSize->value();
        emit signalMouseClickedShape(3,x);
    }

    // CMP
    if(groupCMP.checkedButton()==m_ui->radioCMP_Add)
    {
        int x=m_ui->spinCMPSize->value();
        emit signalCMPShape(1,x);
    }
    if(groupCMP.checkedButton()==m_ui->radioCMP_Mul)
    {
        int x=m_ui->spinCMPSize->value();
        emit signalCMPShape(2,x);
    }
    if(groupCMP.checkedButton()==m_ui->radioCMP_Box)
    {
        int x=m_ui->spinCMPSize->value();
        emit signalCMPShape(3,x);
    }
}
