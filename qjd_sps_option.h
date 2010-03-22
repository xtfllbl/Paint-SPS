#ifndef OPTION_H
#define OPTION_H

#include <QtGui/QDialog>
#include "ui_qjd_sps_option.h"
#include <QColorDialog>

namespace Ui {
    class Option;
}

class qjdOption : public QDialog {
    Q_OBJECT
public:
    qjdOption(QWidget *parent = 0);
    ~qjdOption();
    Ui::Option *m_ui;

    bool isIndex_0;
    bool isIndex_1;
    bool isIndex_2;
    bool isIndex_3;
    bool isIndex_4;
    bool isIndex_5;
    bool isIndex_6;
    bool isIndex_7;

    bool flagShotLine;
    bool flagReceiveLine;
    bool flagMouseClicked;
    bool flagShotLineRelated;
    bool flagReceiveLineRelated;
    bool flagShotLineCon;
    bool flagReceiveLineCon;
    bool flagCMP;

    QColor shotLineColor;
    QColor receiveLineColor;
    QColor mouseClickedColor;
    QColor shotLineRelatedColor;
    QColor receiveLineRelatedColor;
    QColor shotLineConColor;
    QColor receiveLineConColor;
    QColor CMP_Color;

    double shotLineValue;
    double receiveLineValue;
    double mouseClickedValue;
    double shotLineRelatedValue;
    double receiveLineRelatedValue;
    double shotLineConValue;
    double receiveLineConValue;
    double CMP_Value;

protected:
    void changeEvent(QEvent *e);

private:
    QButtonGroup groupShotLine;
    QButtonGroup groupReceiveLine;
    QButtonGroup groupMouseClicked;
    QButtonGroup groupCMP;

    //函数
    void decideShape();
signals:
    //改变颜色和粗细
    void signalShotLineColor(QColor,double);
    void signalReceiveLineColor(QColor,double);
    void signalMouseClickedColor(QColor,double);
    void signalMouseClickedSLColor(QColor,double);
    void signalMouseClickedRLColor(QColor,double);
    void signalShotLineConColor(QColor,double);
    void signalReceiveLineConColor(QColor,double);
    void signalCMP(QColor,double);
    //改变形状和大小
    void signalShotLineShape(int,int);
    void signalReceiveLineShape(int,int);
    void signalMouseClickedShape(int,int);
    void signalCMPShape(int,int);
    //改变cmp 的精度
    void signalCMPAccuracy(int);

private slots:
    void on_comboCMPAccuracy_currentIndexChanged(int index);
    void on_spinCMP_valueChanged(QString );
    void on_btnCMPSC_clicked();
    void on_spinReceiveLineCon_valueChanged(QString );
    void on_spinShotLineCon_valueChanged(QString );
    void on_spinReceiveLineRelated_valueChanged(QString );
    void on_spinShotLineRelated_valueChanged(QString );
    void on_spinMouseClicked_valueChanged(QString );
    void on_spinReceiveLine_valueChanged(QString );
    void on_spinShotLine_valueChanged(QString );
    void on_btnReceiveLineConSC_clicked();
    void on_btnShotLineConSC_clicked();
    void on_btnMouseRelationSCRL_clicked();
    void on_btnMouseRelationSCSL_clicked();
    void on_btnMouseClickedSC_clicked();
    void on_btnReceiverLineSC_clicked();
    void on_btnShotLineSC_clicked();
    void on_btnClose_clicked();
    void on_btnApply_clicked();

};

#endif // OPTION_H
