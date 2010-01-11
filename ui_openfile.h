/********************************************************************************
** Form generated from reading ui file 'openfile.ui'
**
** Created: Fri Dec 25 11:10:16 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPENFILE_H
#define UI_OPENFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenFile
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineSFile;
    QPushButton *btnSFile;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineRFile;
    QPushButton *btnRFile;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineXFile;
    QPushButton *btnXFile;
    QGroupBox *groupUnit;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineSingleWid;
    QLabel *label_5;
    QLineEdit *lineSingleHei;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *pushButton;

    void setupUi(QWidget *OpenFile)
    {
        if (OpenFile->objectName().isEmpty())
            OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        OpenFile->setWindowModality(Qt::ApplicationModal);
        OpenFile->resize(409, 268);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("images/folder.png")), QIcon::Normal, QIcon::Off);
        OpenFile->setWindowIcon(icon);
        gridLayout = new QGridLayout(OpenFile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(OpenFile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Vera Sans"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineSFile = new QLineEdit(OpenFile);
        lineSFile->setObjectName(QString::fromUtf8("lineSFile"));
        lineSFile->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(lineSFile);

        btnSFile = new QPushButton(OpenFile);
        btnSFile->setObjectName(QString::fromUtf8("btnSFile"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Nuvola_filesystems_folder_yellow_open.png")), QIcon::Normal, QIcon::Off);
        btnSFile->setIcon(icon1);
        btnSFile->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(btnSFile);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(OpenFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineRFile = new QLineEdit(OpenFile);
        lineRFile->setObjectName(QString::fromUtf8("lineRFile"));

        horizontalLayout_2->addWidget(lineRFile);

        btnRFile = new QPushButton(OpenFile);
        btnRFile->setObjectName(QString::fromUtf8("btnRFile"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Nuvola_filesystems_folder_blue_open.png")), QIcon::Normal, QIcon::Off);
        btnRFile->setIcon(icon2);
        btnRFile->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(btnRFile);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(OpenFile);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lineXFile = new QLineEdit(OpenFile);
        lineXFile->setObjectName(QString::fromUtf8("lineXFile"));

        horizontalLayout_3->addWidget(lineXFile);

        btnXFile = new QPushButton(OpenFile);
        btnXFile->setObjectName(QString::fromUtf8("btnXFile"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Nuvola_filesystems_folder_grey_open.png")), QIcon::Normal, QIcon::Off);
        btnXFile->setIcon(icon3);
        btnXFile->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(btnXFile);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        groupUnit = new QGroupBox(OpenFile);
        groupUnit->setObjectName(QString::fromUtf8("groupUnit"));
        gridLayout_2 = new QGridLayout(groupUnit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupUnit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Vera Sans"));
        label_4->setFont(font1);

        horizontalLayout_5->addWidget(label_4);

        lineSingleWid = new QLineEdit(groupUnit);
        lineSingleWid->setObjectName(QString::fromUtf8("lineSingleWid"));

        horizontalLayout_5->addWidget(lineSingleWid);

        label_5 = new QLabel(groupUnit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        lineSingleHei = new QLineEdit(groupUnit);
        lineSingleHei->setObjectName(QString::fromUtf8("lineSingleHei"));

        horizontalLayout_5->addWidget(lineSingleHei);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout->addWidget(groupUnit, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_2 = new QPushButton(OpenFile);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnOK = new QPushButton(OpenFile);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setMinimumSize(QSize(100, 0));
        btnOK->setMaximumSize(QSize(100, 16777215));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_apply.png")), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon4);

        horizontalLayout_4->addWidget(btnOK);

        pushButton = new QPushButton(OpenFile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_button_cancel.png")), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);

        horizontalLayout_4->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        QWidget::setTabOrder(btnSFile, btnRFile);
        QWidget::setTabOrder(btnRFile, btnXFile);
        QWidget::setTabOrder(btnXFile, btnOK);
        QWidget::setTabOrder(btnOK, pushButton);
        QWidget::setTabOrder(pushButton, lineSFile);
        QWidget::setTabOrder(lineSFile, lineRFile);
        QWidget::setTabOrder(lineRFile, lineXFile);

        retranslateUi(OpenFile);
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), groupUnit, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(OpenFile);
    } // setupUi

    void retranslateUi(QWidget *OpenFile)
    {
        OpenFile->setWindowTitle(QApplication::translate("OpenFile", "Open Files", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenFile", "SPS:", 0, QApplication::UnicodeUTF8));
        btnSFile->setText(QString());
        btnSFile->setShortcut(QApplication::translate("OpenFile", "F1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OpenFile", "RPS:", 0, QApplication::UnicodeUTF8));
        btnRFile->setText(QString());
        label_3->setText(QApplication::translate("OpenFile", "XPS:", 0, QApplication::UnicodeUTF8));
        btnXFile->setText(QString());
        groupUnit->setTitle(QApplication::translate("OpenFile", "Unit:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OpenFile", "Unit width:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OpenFile", "Unit height:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("OpenFile", "More", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("OpenFile", "Apply", 0, QApplication::UnicodeUTF8));
        btnOK->setShortcut(QApplication::translate("OpenFile", "Return", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("OpenFile", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("OpenFile", "Esc", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OpenFile);
    } // retranslateUi

};

namespace Ui {
    class OpenFile: public Ui_OpenFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILE_H
