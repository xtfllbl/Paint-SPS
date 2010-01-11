/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Dec 25 14:04:13 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionReset;
    QAction *actionRelation;
    QAction *actionCombineFiles;
    QAction *actionClose;
    QAction *actionAbout_QT;
    QAction *actionShotLine;
    QAction *actionReceiveLine;
    QAction *actionFoldNumbers;
    QAction *actionCMP;
    QAction *actionShotPointLine;
    QAction *actionReceivePointLine;
    QAction *actionOption;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *mainw;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(840, 800);
        MainWindow->setMinimumSize(QSize(530, 620));
        MainWindow->setSizeIncrement(QSize(10, 10));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("images/report.png")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Nuvola_filesystems_folder_yellow_open.png")), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_reload.png")), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon2);
        actionRelation = new QAction(MainWindow);
        actionRelation->setObjectName(QString::fromUtf8("actionRelation"));
        actionRelation->setCheckable(true);
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/sr.png")), QIcon::Normal, QIcon::Off);
        actionRelation->setIcon(icon3);
        actionCombineFiles = new QAction(MainWindow);
        actionCombineFiles->setObjectName(QString::fromUtf8("actionCombineFiles"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_app_database.png")), QIcon::Normal, QIcon::Off);
        actionCombineFiles->setIcon(icon4);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_exit.png")), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon5);
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Torchlight_qt.png")), QIcon::Normal, QIcon::Off);
        actionAbout_QT->setIcon(icon6);
        actionShotLine = new QAction(MainWindow);
        actionShotLine->setObjectName(QString::fromUtf8("actionShotLine"));
        actionShotLine->setCheckable(true);
        QIcon icon7;
        icon7.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_mimetype_source_r.png")), QIcon::Normal, QIcon::Off);
        actionShotLine->setIcon(icon7);
        actionReceiveLine = new QAction(MainWindow);
        actionReceiveLine->setObjectName(QString::fromUtf8("actionReceiveLine"));
        actionReceiveLine->setCheckable(true);
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/receiveline.png")), QIcon::Normal, QIcon::Off);
        actionReceiveLine->setIcon(icon8);
        actionFoldNumbers = new QAction(MainWindow);
        actionFoldNumbers->setObjectName(QString::fromUtf8("actionFoldNumbers"));
        actionFoldNumbers->setCheckable(true);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        actionFoldNumbers->setFont(font);
        actionCMP = new QAction(MainWindow);
        actionCMP->setObjectName(QString::fromUtf8("actionCMP"));
        actionCMP->setCheckable(true);
        actionCMP->setFont(font);
        actionShotPointLine = new QAction(MainWindow);
        actionShotPointLine->setObjectName(QString::fromUtf8("actionShotPointLine"));
        actionShotPointLine->setCheckable(true);
        QIcon icon9;
        icon9.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/s.png")), QIcon::Normal, QIcon::Off);
        actionShotPointLine->setIcon(icon9);
        actionReceivePointLine = new QAction(MainWindow);
        actionReceivePointLine->setObjectName(QString::fromUtf8("actionReceivePointLine"));
        actionReceivePointLine->setCheckable(true);
        actionReceivePointLine->setEnabled(true);
        QIcon icon10;
        icon10.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/r.png")), QIcon::Normal, QIcon::Off);
        actionReceivePointLine->setIcon(icon10);
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        QIcon icon11;
        icon11.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/gnome-stock-gnome-run.png")), QIcon::Normal, QIcon::Off);
        actionOption->setIcon(icon11);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon12;
        icon12.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/Torchlight_help.png")), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon12);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainw = new QWidget(centralWidget);
        mainw->setObjectName(QString::fromUtf8("mainw"));

        gridLayout->addWidget(mainw, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionCombineFiles);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionAbout_QT);
        menuView->addAction(actionReset);
        menuView->addSeparator();
        menuView->addAction(actionRelation);
        menuView->addAction(actionShotLine);
        menuView->addAction(actionReceiveLine);
        menuView->addSeparator();
        menuView->addAction(actionCMP);
        menuView->addAction(actionFoldNumbers);
        menuView->addSeparator();
        menuView->addAction(actionOption);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionCombineFiles);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionReset);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShotLine);
        mainToolBar->addAction(actionReceiveLine);
        mainToolBar->addAction(actionShotPointLine);
        mainToolBar->addAction(actionReceivePointLine);
        mainToolBar->addAction(actionRelation);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCMP);
        mainToolBar->addAction(actionFoldNumbers);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOption);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SPS file show", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("MainWindow", "OpenS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open SPS Files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionReset->setToolTip(QApplication::translate("MainWindow", "Reset the image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionReset->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        actionRelation->setText(QApplication::translate("MainWindow", "Relation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRelation->setToolTip(QApplication::translate("MainWindow", "Push me and then click the plus on the image, you`ll see the relation betweem shoot & receive point\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRelation->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        actionCombineFiles->setText(QApplication::translate("MainWindow", "Combine", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCombineFiles->setToolTip(QApplication::translate("MainWindow", "Combine Files Into One", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCombineFiles->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Esc", 0, QApplication::UnicodeUTF8));
        actionAbout_QT->setText(QApplication::translate("MainWindow", "About QT", 0, QApplication::UnicodeUTF8));
        actionShotLine->setText(QApplication::translate("MainWindow", "Shoot Line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShotLine->setToolTip(QApplication::translate("MainWindow", "Show Shot Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionReceiveLine->setText(QApplication::translate("MainWindow", "Receive Line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionReceiveLine->setToolTip(QApplication::translate("MainWindow", "Show Receive Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFoldNumbers->setText(QApplication::translate("MainWindow", "FOLD", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFoldNumbers->setToolTip(QApplication::translate("MainWindow", "Show Fold Numbers", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFoldNumbers->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        actionCMP->setText(QApplication::translate("MainWindow", "CMP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCMP->setToolTip(QApplication::translate("MainWindow", "show Fold Point", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionShotPointLine->setText(QApplication::translate("MainWindow", "shotPointLine", 0, QApplication::UnicodeUTF8));
        actionReceivePointLine->setText(QApplication::translate("MainWindow", "receivePointLine", 0, QApplication::UnicodeUTF8));
        actionOption->setText(QApplication::translate("MainWindow", "option", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mainToolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
