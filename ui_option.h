/********************************************************************************
** Form generated from reading ui file 'option.ui'
**
** Created: Fri Jan 22 10:35:19 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Option
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabFold;
    QGridLayout *gridLayout_4;
    QGroupBox *groupFold;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinSingleWid;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpinBox *spinSingleHei;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboColorTable;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_20;
    QFrame *line_2;
    QLabel *label_21;
    QFrame *line;
    QLabel *label_22;
    QLabel *label_11;
    QRadioButton *radioSL_Add;
    QRadioButton *radioSL_Mul;
    QRadioButton *radioSL_Box;
    QSpinBox *spinShotLineSize;
    QLabel *label_17;
    QRadioButton *radioRL_Add;
    QRadioButton *radioRL_Mul;
    QRadioButton *radioRL_Box;
    QSpinBox *spinReceiveLineSize;
    QLabel *label_18;
    QRadioButton *radioMC_Add;
    QRadioButton *radioMC_Mul;
    QRadioButton *radioMC_Box;
    QSpinBox *spinMouseClickedSize;
    QLabel *label_19;
    QRadioButton *radioCMP_Add;
    QRadioButton *radioCMP_Mul;
    QRadioButton *radioCMP_Box;
    QSpinBox *spinCMPSize;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_23;
    QComboBox *comboCMPAccuracy;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tabColor;
    QGridLayout *gridLayout_7;
    QGroupBox *groupColor;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *btnShotLineSC;
    QLabel *labelSL;
    QDoubleSpinBox *spinShotLine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *btnReceiverLineSC;
    QLabel *labelRL;
    QDoubleSpinBox *spinReceiveLine;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QPushButton *btnMouseClickedSC;
    QLabel *labelMC;
    QDoubleSpinBox *spinMouseClicked;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QPushButton *btnMouseRelationSCSL;
    QLabel *labelMCRSL;
    QDoubleSpinBox *spinShotLineRelated;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QPushButton *btnMouseRelationSCRL;
    QLabel *labelMCRRL;
    QDoubleSpinBox *spinReceiveLineRelated;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QPushButton *btnShotLineConSC;
    QLabel *labelSLC;
    QDoubleSpinBox *spinShotLineCon;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QPushButton *btnReceiveLineConSC;
    QLabel *labelRLC;
    QDoubleSpinBox *spinReceiveLineCon;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QPushButton *btnCMPSC;
    QLabel *labelCMP;
    QDoubleSpinBox *spinCMP;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnApply;
    QPushButton *btnClose;

    void setupUi(QDialog *Option)
    {
        if (Option->objectName().isEmpty())
            Option->setObjectName(QString::fromUtf8("Option"));
        Option->resize(575, 515);
        gridLayout_2 = new QGridLayout(Option);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(Option);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabFold = new QWidget();
        tabFold->setObjectName(QString::fromUtf8("tabFold"));
        gridLayout_4 = new QGridLayout(tabFold);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupFold = new QGroupBox(tabFold);
        groupFold->setObjectName(QString::fromUtf8("groupFold"));
        groupFold->setFlat(false);
        gridLayout = new QGridLayout(groupFold);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupFold);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(label);

        spinSingleWid = new QSpinBox(groupFold);
        spinSingleWid->setObjectName(QString::fromUtf8("spinSingleWid"));
        spinSingleWid->setMinimumSize(QSize(60, 0));
        spinSingleWid->setMaximum(100000);

        horizontalLayout->addWidget(spinSingleWid);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_2 = new QLabel(groupFold);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));

        horizontalLayout->addWidget(label_2);

        spinSingleHei = new QSpinBox(groupFold);
        spinSingleHei->setObjectName(QString::fromUtf8("spinSingleHei"));
        spinSingleHei->setMaximum(10000);

        horizontalLayout->addWidget(spinSingleHei);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupFold);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(label_3);

        comboColorTable = new QComboBox(groupFold);
        comboColorTable->setObjectName(QString::fromUtf8("comboColorTable"));
        comboColorTable->setMinimumSize(QSize(150, 0));
        comboColorTable->setEditable(false);
        comboColorTable->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        horizontalLayout_2->addWidget(comboColorTable);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupFold, 0, 0, 1, 1);

        groupBox = new QGroupBox(tabFold);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_20->setFont(font);
        label_20->setFrameShape(QFrame::Panel);
        label_20->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(label_20, 0, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 0, 1, 5, 1);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(0, 30));
        label_21->setFont(font);
        label_21->setFrameShape(QFrame::Panel);
        label_21->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(label_21, 0, 2, 1, 3);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 5, 5, 1);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(0, 30));
        label_22->setFont(font);
        label_22->setFrameShape(QFrame::Panel);
        label_22->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(label_22, 0, 6, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        radioSL_Add = new QRadioButton(groupBox);
        radioSL_Add->setObjectName(QString::fromUtf8("radioSL_Add"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioSL_Add->setIcon(icon);

        gridLayout_3->addWidget(radioSL_Add, 1, 2, 1, 1);

        radioSL_Mul = new QRadioButton(groupBox);
        radioSL_Mul->setObjectName(QString::fromUtf8("radioSL_Mul"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/image/wrong.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioSL_Mul->setIcon(icon1);

        gridLayout_3->addWidget(radioSL_Mul, 1, 3, 1, 1);

        radioSL_Box = new QRadioButton(groupBox);
        radioSL_Box->setObjectName(QString::fromUtf8("radioSL_Box"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/image/fang.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioSL_Box->setIcon(icon2);

        gridLayout_3->addWidget(radioSL_Box, 1, 4, 1, 1);

        spinShotLineSize = new QSpinBox(groupBox);
        spinShotLineSize->setObjectName(QString::fromUtf8("spinShotLineSize"));
        spinShotLineSize->setMinimum(1);
        spinShotLineSize->setMaximum(20);

        gridLayout_3->addWidget(spinShotLineSize, 1, 6, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 2, 0, 1, 1);

        radioRL_Add = new QRadioButton(groupBox);
        radioRL_Add->setObjectName(QString::fromUtf8("radioRL_Add"));
        radioRL_Add->setIcon(icon);

        gridLayout_3->addWidget(radioRL_Add, 2, 2, 1, 1);

        radioRL_Mul = new QRadioButton(groupBox);
        radioRL_Mul->setObjectName(QString::fromUtf8("radioRL_Mul"));
        radioRL_Mul->setIcon(icon1);

        gridLayout_3->addWidget(radioRL_Mul, 2, 3, 1, 1);

        radioRL_Box = new QRadioButton(groupBox);
        radioRL_Box->setObjectName(QString::fromUtf8("radioRL_Box"));
        radioRL_Box->setIcon(icon2);

        gridLayout_3->addWidget(radioRL_Box, 2, 4, 1, 1);

        spinReceiveLineSize = new QSpinBox(groupBox);
        spinReceiveLineSize->setObjectName(QString::fromUtf8("spinReceiveLineSize"));
        spinReceiveLineSize->setMinimum(1);
        spinReceiveLineSize->setMaximum(20);

        gridLayout_3->addWidget(spinReceiveLineSize, 2, 6, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 1);

        radioMC_Add = new QRadioButton(groupBox);
        radioMC_Add->setObjectName(QString::fromUtf8("radioMC_Add"));
        radioMC_Add->setIcon(icon);

        gridLayout_3->addWidget(radioMC_Add, 3, 2, 1, 1);

        radioMC_Mul = new QRadioButton(groupBox);
        radioMC_Mul->setObjectName(QString::fromUtf8("radioMC_Mul"));
        radioMC_Mul->setIcon(icon1);

        gridLayout_3->addWidget(radioMC_Mul, 3, 3, 1, 1);

        radioMC_Box = new QRadioButton(groupBox);
        radioMC_Box->setObjectName(QString::fromUtf8("radioMC_Box"));
        radioMC_Box->setIcon(icon2);

        gridLayout_3->addWidget(radioMC_Box, 3, 4, 1, 1);

        spinMouseClickedSize = new QSpinBox(groupBox);
        spinMouseClickedSize->setObjectName(QString::fromUtf8("spinMouseClickedSize"));
        spinMouseClickedSize->setMinimum(1);
        spinMouseClickedSize->setMaximum(20);

        gridLayout_3->addWidget(spinMouseClickedSize, 3, 6, 1, 1);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 4, 0, 1, 1);

        radioCMP_Add = new QRadioButton(groupBox);
        radioCMP_Add->setObjectName(QString::fromUtf8("radioCMP_Add"));
        radioCMP_Add->setIcon(icon);

        gridLayout_3->addWidget(radioCMP_Add, 4, 2, 1, 1);

        radioCMP_Mul = new QRadioButton(groupBox);
        radioCMP_Mul->setObjectName(QString::fromUtf8("radioCMP_Mul"));
        radioCMP_Mul->setIcon(icon1);

        gridLayout_3->addWidget(radioCMP_Mul, 4, 3, 1, 1);

        radioCMP_Box = new QRadioButton(groupBox);
        radioCMP_Box->setObjectName(QString::fromUtf8("radioCMP_Box"));
        radioCMP_Box->setIcon(icon2);

        gridLayout_3->addWidget(radioCMP_Box, 4, 4, 1, 1);

        spinCMPSize = new QSpinBox(groupBox);
        spinCMPSize->setObjectName(QString::fromUtf8("spinCMPSize"));
        spinCMPSize->setMinimum(1);
        spinCMPSize->setMaximum(20);

        gridLayout_3->addWidget(spinCMPSize, 4, 6, 1, 1);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(tabFold);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(220, 0));

        horizontalLayout_13->addWidget(label_23);

        comboCMPAccuracy = new QComboBox(groupBox_2);
        comboCMPAccuracy->setObjectName(QString::fromUtf8("comboCMPAccuracy"));

        horizontalLayout_13->addWidget(comboCMPAccuracy);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);


        gridLayout_6->addLayout(horizontalLayout_13, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        tabWidget->addTab(tabFold, QString());
        tabColor = new QWidget();
        tabColor->setObjectName(QString::fromUtf8("tabColor"));
        gridLayout_7 = new QGridLayout(tabColor);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupColor = new QGroupBox(tabColor);
        groupColor->setObjectName(QString::fromUtf8("groupColor"));
        gridLayout_5 = new QGridLayout(groupColor);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_13 = new QLabel(groupColor);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(150, 0));
        label_13->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_13->setFont(font1);
        label_13->setFrameShape(QFrame::WinPanel);
        label_13->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(label_13);

        label_14 = new QLabel(groupColor);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(102, 30));
        label_14->setFont(font);
        label_14->setFrameShape(QFrame::WinPanel);
        label_14->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(label_14);

        label_15 = new QLabel(groupColor);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(100, 0));
        label_15->setMaximumSize(QSize(16777215, 30));
        label_15->setFont(font);
        label_15->setFrameShape(QFrame::WinPanel);
        label_15->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(label_15);

        label_16 = new QLabel(groupColor);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 30));
        label_16->setFont(font);
        label_16->setFrameShape(QFrame::WinPanel);
        label_16->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(label_16);


        gridLayout_5->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupColor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(label_4);

        btnShotLineSC = new QPushButton(groupColor);
        btnShotLineSC->setObjectName(QString::fromUtf8("btnShotLineSC"));

        horizontalLayout_4->addWidget(btnShotLineSC);

        labelSL = new QLabel(groupColor);
        labelSL->setObjectName(QString::fromUtf8("labelSL"));
        labelSL->setMinimumSize(QSize(100, 0));
        labelSL->setAutoFillBackground(true);
        labelSL->setFrameShape(QFrame::Panel);
        labelSL->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(labelSL);

        spinShotLine = new QDoubleSpinBox(groupColor);
        spinShotLine->setObjectName(QString::fromUtf8("spinShotLine"));
        spinShotLine->setMinimum(0.01);
        spinShotLine->setMaximum(10);
        spinShotLine->setSingleStep(0.1);

        horizontalLayout_4->addWidget(spinShotLine);


        gridLayout_5->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupColor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(label_5);

        btnReceiverLineSC = new QPushButton(groupColor);
        btnReceiverLineSC->setObjectName(QString::fromUtf8("btnReceiverLineSC"));

        horizontalLayout_5->addWidget(btnReceiverLineSC);

        labelRL = new QLabel(groupColor);
        labelRL->setObjectName(QString::fromUtf8("labelRL"));
        labelRL->setMinimumSize(QSize(100, 0));
        labelRL->setAutoFillBackground(true);
        labelRL->setFrameShape(QFrame::Panel);
        labelRL->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(labelRL);

        spinReceiveLine = new QDoubleSpinBox(groupColor);
        spinReceiveLine->setObjectName(QString::fromUtf8("spinReceiveLine"));
        spinReceiveLine->setMinimum(0.01);
        spinReceiveLine->setMaximum(10);
        spinReceiveLine->setSingleStep(0.1);

        horizontalLayout_5->addWidget(spinReceiveLine);


        gridLayout_5->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupColor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(150, 0));

        horizontalLayout_6->addWidget(label_6);

        btnMouseClickedSC = new QPushButton(groupColor);
        btnMouseClickedSC->setObjectName(QString::fromUtf8("btnMouseClickedSC"));

        horizontalLayout_6->addWidget(btnMouseClickedSC);

        labelMC = new QLabel(groupColor);
        labelMC->setObjectName(QString::fromUtf8("labelMC"));
        labelMC->setMinimumSize(QSize(100, 0));
        labelMC->setAutoFillBackground(true);
        labelMC->setFrameShape(QFrame::Panel);
        labelMC->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(labelMC);

        spinMouseClicked = new QDoubleSpinBox(groupColor);
        spinMouseClicked->setObjectName(QString::fromUtf8("spinMouseClicked"));
        spinMouseClicked->setMinimum(0.01);
        spinMouseClicked->setMaximum(10);
        spinMouseClicked->setSingleStep(0.1);

        horizontalLayout_6->addWidget(spinMouseClicked);


        gridLayout_5->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupColor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(150, 0));

        horizontalLayout_7->addWidget(label_7);

        btnMouseRelationSCSL = new QPushButton(groupColor);
        btnMouseRelationSCSL->setObjectName(QString::fromUtf8("btnMouseRelationSCSL"));

        horizontalLayout_7->addWidget(btnMouseRelationSCSL);

        labelMCRSL = new QLabel(groupColor);
        labelMCRSL->setObjectName(QString::fromUtf8("labelMCRSL"));
        labelMCRSL->setMinimumSize(QSize(100, 0));
        labelMCRSL->setAutoFillBackground(true);
        labelMCRSL->setFrameShape(QFrame::Panel);
        labelMCRSL->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(labelMCRSL);

        spinShotLineRelated = new QDoubleSpinBox(groupColor);
        spinShotLineRelated->setObjectName(QString::fromUtf8("spinShotLineRelated"));
        spinShotLineRelated->setMinimum(0.01);
        spinShotLineRelated->setMaximum(10);
        spinShotLineRelated->setSingleStep(0.1);

        horizontalLayout_7->addWidget(spinShotLineRelated);


        gridLayout_5->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(groupColor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(150, 0));

        horizontalLayout_8->addWidget(label_10);

        btnMouseRelationSCRL = new QPushButton(groupColor);
        btnMouseRelationSCRL->setObjectName(QString::fromUtf8("btnMouseRelationSCRL"));

        horizontalLayout_8->addWidget(btnMouseRelationSCRL);

        labelMCRRL = new QLabel(groupColor);
        labelMCRRL->setObjectName(QString::fromUtf8("labelMCRRL"));
        labelMCRRL->setMinimumSize(QSize(100, 0));
        labelMCRRL->setAutoFillBackground(true);
        labelMCRRL->setFrameShape(QFrame::Panel);
        labelMCRRL->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(labelMCRRL);

        spinReceiveLineRelated = new QDoubleSpinBox(groupColor);
        spinReceiveLineRelated->setObjectName(QString::fromUtf8("spinReceiveLineRelated"));
        spinReceiveLineRelated->setMinimum(0.01);
        spinReceiveLineRelated->setMaximum(10);
        spinReceiveLineRelated->setSingleStep(0.1);

        horizontalLayout_8->addWidget(spinReceiveLineRelated);


        gridLayout_5->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(groupColor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(150, 0));

        horizontalLayout_9->addWidget(label_8);

        btnShotLineConSC = new QPushButton(groupColor);
        btnShotLineConSC->setObjectName(QString::fromUtf8("btnShotLineConSC"));

        horizontalLayout_9->addWidget(btnShotLineConSC);

        labelSLC = new QLabel(groupColor);
        labelSLC->setObjectName(QString::fromUtf8("labelSLC"));
        labelSLC->setMinimumSize(QSize(100, 0));
        labelSLC->setAutoFillBackground(true);
        labelSLC->setFrameShape(QFrame::Panel);
        labelSLC->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(labelSLC);

        spinShotLineCon = new QDoubleSpinBox(groupColor);
        spinShotLineCon->setObjectName(QString::fromUtf8("spinShotLineCon"));
        spinShotLineCon->setMinimum(0.01);
        spinShotLineCon->setMaximum(10);
        spinShotLineCon->setSingleStep(0.1);

        horizontalLayout_9->addWidget(spinShotLineCon);


        gridLayout_5->addLayout(horizontalLayout_9, 6, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(groupColor);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(150, 0));

        horizontalLayout_10->addWidget(label_9);

        btnReceiveLineConSC = new QPushButton(groupColor);
        btnReceiveLineConSC->setObjectName(QString::fromUtf8("btnReceiveLineConSC"));

        horizontalLayout_10->addWidget(btnReceiveLineConSC);

        labelRLC = new QLabel(groupColor);
        labelRLC->setObjectName(QString::fromUtf8("labelRLC"));
        labelRLC->setMinimumSize(QSize(100, 0));
        labelRLC->setAutoFillBackground(true);
        labelRLC->setFrameShape(QFrame::Panel);
        labelRLC->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(labelRLC);

        spinReceiveLineCon = new QDoubleSpinBox(groupColor);
        spinReceiveLineCon->setObjectName(QString::fromUtf8("spinReceiveLineCon"));
        spinReceiveLineCon->setMinimum(0.01);
        spinReceiveLineCon->setMaximum(10);
        spinReceiveLineCon->setSingleStep(0.1);

        horizontalLayout_10->addWidget(spinReceiveLineCon);


        gridLayout_5->addLayout(horizontalLayout_10, 7, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_12 = new QLabel(groupColor);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(150, 0));

        horizontalLayout_12->addWidget(label_12);

        btnCMPSC = new QPushButton(groupColor);
        btnCMPSC->setObjectName(QString::fromUtf8("btnCMPSC"));

        horizontalLayout_12->addWidget(btnCMPSC);

        labelCMP = new QLabel(groupColor);
        labelCMP->setObjectName(QString::fromUtf8("labelCMP"));
        labelCMP->setMinimumSize(QSize(100, 0));
        labelCMP->setAutoFillBackground(true);
        labelCMP->setFrameShape(QFrame::Panel);
        labelCMP->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(labelCMP);

        spinCMP = new QDoubleSpinBox(groupColor);
        spinCMP->setObjectName(QString::fromUtf8("spinCMP"));
        spinCMP->setMinimum(0.01);
        spinCMP->setMaximum(10);
        spinCMP->setSingleStep(0.1);

        horizontalLayout_12->addWidget(spinCMP);


        gridLayout_5->addLayout(horizontalLayout_12, 8, 0, 1, 1);


        gridLayout_7->addWidget(groupColor, 0, 0, 1, 1);

        tabWidget->addTab(tabColor, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnApply = new QPushButton(Option);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnApply->setIcon(icon3);

        horizontalLayout_3->addWidget(btnApply);

        btnClose = new QPushButton(Option);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_button_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon4);

        horizontalLayout_3->addWidget(btnClose);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(Option);

        tabWidget->setCurrentIndex(1);
        comboColorTable->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Option);
    } // setupUi

    void retranslateUi(QDialog *Option)
    {
        Option->setWindowTitle(QApplication::translate("Option", "Options", 0, QApplication::UnicodeUTF8));
        groupFold->setTitle(QApplication::translate("Option", "Fold Settings:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Option", "Unit Width:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Option", "Unit Height:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Option", "Choose Color Map:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Option", "Shape Settings:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Option", "Name", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Option", "Shape", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Option", "Size", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Option", "Shot Line:", 0, QApplication::UnicodeUTF8));
        radioSL_Add->setText(QString());
        radioSL_Mul->setText(QString());
        radioSL_Box->setText(QString());
        label_17->setText(QApplication::translate("Option", "Receive Line:", 0, QApplication::UnicodeUTF8));
        radioRL_Add->setText(QString());
        radioRL_Mul->setText(QString());
        radioRL_Box->setText(QString());
        label_18->setText(QApplication::translate("Option", "Mouse Clicked:", 0, QApplication::UnicodeUTF8));
        radioMC_Add->setText(QString());
        radioMC_Mul->setText(QString());
        radioMC_Box->setText(QString());
        label_19->setText(QApplication::translate("Option", "CMP:", 0, QApplication::UnicodeUTF8));
        radioCMP_Add->setText(QString());
        radioCMP_Mul->setText(QString());
        radioCMP_Box->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Option", "CMP Setting:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Option", "Decrease CMP Display Accuracy to:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFold), QApplication::translate("Option", "Preferences", 0, QApplication::UnicodeUTF8));
        groupColor->setTitle(QApplication::translate("Option", "Color Settings:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Option", "Name", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Option", "Choose Color", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Option", "Color", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Option", "Line Width", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Option", "Shot Line", 0, QApplication::UnicodeUTF8));
        btnShotLineSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelSL->setText(QString());
        label_5->setText(QApplication::translate("Option", "Receive Line", 0, QApplication::UnicodeUTF8));
        btnReceiverLineSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelRL->setText(QString());
        label_6->setText(QApplication::translate("Option", "Mouse Clicked", 0, QApplication::UnicodeUTF8));
        btnMouseClickedSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelMC->setText(QString());
        label_7->setText(QApplication::translate("Option", "Shot Line Related", 0, QApplication::UnicodeUTF8));
        btnMouseRelationSCSL->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelMCRSL->setText(QString());
        label_10->setText(QApplication::translate("Option", "Receive Line Related", 0, QApplication::UnicodeUTF8));
        btnMouseRelationSCRL->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelMCRRL->setText(QString());
        label_8->setText(QApplication::translate("Option", "Shot Line Connection", 0, QApplication::UnicodeUTF8));
        btnShotLineConSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelSLC->setText(QString());
        label_9->setText(QApplication::translate("Option", "Receiver Line Connection", 0, QApplication::UnicodeUTF8));
        btnReceiveLineConSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelRLC->setText(QString());
        label_12->setText(QApplication::translate("Option", "CMP", 0, QApplication::UnicodeUTF8));
        btnCMPSC->setText(QApplication::translate("Option", "Select Color", 0, QApplication::UnicodeUTF8));
        labelCMP->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabColor), QApplication::translate("Option", "Color Setting", 0, QApplication::UnicodeUTF8));
        btnApply->setText(QApplication::translate("Option", "Refreash", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("Option", "Close", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Option);
    } // retranslateUi

};

namespace Ui {
    class Option: public Ui_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
