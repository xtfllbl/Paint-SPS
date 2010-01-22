/********************************************************************************
** Form generated from reading ui file 'combinefiles.ui'
**
** Created: Fri Jan 22 10:35:19 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_COMBINEFILES_H
#define UI_COMBINEFILES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CombineFiles
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QListView *fileList;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QGroupBox *groupBox3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineCombineFile;
    QPushButton *btnCombineFile;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReset;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *CombineFiles)
    {
        if (CombineFiles->objectName().isEmpty())
            CombineFiles->setObjectName(QString::fromUtf8("CombineFiles"));
        CombineFiles->setWindowModality(Qt::ApplicationModal);
        CombineFiles->resize(526, 293);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/WinRAR.png"), QSize(), QIcon::Normal, QIcon::Off);
        CombineFiles->setWindowIcon(icon);
        gridLayout = new QGridLayout(CombineFiles);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox2 = new QGroupBox(CombineFiles);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        fileList = new QListView(groupBox2);
        fileList->setObjectName(QString::fromUtf8("fileList"));

        horizontalLayout_2->addWidget(fileList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnAdd = new QPushButton(groupBox2);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_action_db_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon1);
        btnAdd->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(btnAdd);

        btnDel = new QPushButton(groupBox2);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_action_db_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDel->setIcon(icon2);
        btnDel->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(btnDel);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox2, 0, 0, 1, 1);

        groupBox3 = new QGroupBox(CombineFiles);
        groupBox3->setObjectName(QString::fromUtf8("groupBox3"));
        gridLayout_3 = new QGridLayout(groupBox3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineCombineFile = new QLineEdit(groupBox3);
        lineCombineFile->setObjectName(QString::fromUtf8("lineCombineFile"));

        horizontalLayout->addWidget(lineCombineFile);

        btnCombineFile = new QPushButton(groupBox3);
        btnCombineFile->setObjectName(QString::fromUtf8("btnCombineFile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_action_db_update.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCombineFile->setIcon(icon3);
        btnCombineFile->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(btnCombineFile);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnReset = new QPushButton(CombineFiles);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setMinimumSize(QSize(100, 0));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_decrypted.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReset->setIcon(icon4);

        horizontalLayout_4->addWidget(btnReset);

        btnOK = new QPushButton(CombineFiles);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setMinimumSize(QSize(100, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon5);

        horizontalLayout_4->addWidget(btnOK);

        btnCancel = new QPushButton(CombineFiles);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(100, 0));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_button_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon6);

        horizontalLayout_4->addWidget(btnCancel);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        QWidget::setTabOrder(btnDel, btnCombineFile);
        QWidget::setTabOrder(btnCombineFile, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);
        QWidget::setTabOrder(btnCancel, fileList);
        QWidget::setTabOrder(fileList, lineCombineFile);

        retranslateUi(CombineFiles);

        QMetaObject::connectSlotsByName(CombineFiles);
    } // setupUi

    void retranslateUi(QDialog *CombineFiles)
    {
        CombineFiles->setWindowTitle(QApplication::translate("CombineFiles", "Combine Files", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QApplication::translate("CombineFiles", "Choose File", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CombineFiles", "Combine Files:", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QString());
        btnDel->setText(QString());
        groupBox3->setTitle(QApplication::translate("CombineFiles", "Output", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CombineFiles", "Combined To:   ", 0, QApplication::UnicodeUTF8));
        btnCombineFile->setText(QString());
        btnReset->setText(QApplication::translate("CombineFiles", "Reset", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("CombineFiles", "Apply", 0, QApplication::UnicodeUTF8));
        btnOK->setShortcut(QApplication::translate("CombineFiles", "Return", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("CombineFiles", "Cancel", 0, QApplication::UnicodeUTF8));
        btnCancel->setShortcut(QApplication::translate("CombineFiles", "Esc", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CombineFiles);
    } // retranslateUi

};

namespace Ui {
    class CombineFiles: public Ui_CombineFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBINEFILES_H
