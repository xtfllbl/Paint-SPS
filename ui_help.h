/********************************************************************************
** Form generated from reading ui file 'help.ui'
**
** Created: Fri Jan 22 10:35:19 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *mouse;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QTextBrowser *textBrowser_2;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QTextBrowser *textBrowser_3;
    QSpacerItem *horizontalSpacer_8;
    QWidget *function;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *toolButton_7;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_14;
    QToolButton *toolButton_8;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_15;
    QToolButton *toolButton_9;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton_10;
    QLabel *label_14;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(806, 696);
        gridLayout = new QGridLayout(Help);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Help);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Help);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        mouse = new QWidget();
        mouse->setObjectName(QString::fromUtf8("mouse"));
        gridLayout_2 = new QGridLayout(mouse);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(mouse);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/leftclick.png")));

        horizontalLayout_2->addWidget(label_2);

        textBrowser = new QTextBrowser(mouse);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(260, 120));

        horizontalLayout_2->addWidget(textBrowser);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(mouse);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/rightclick.png")));

        horizontalLayout_3->addWidget(label_3);

        textBrowser_2 = new QTextBrowser(mouse);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setMaximumSize(QSize(260, 16777215));

        horizontalLayout_3->addWidget(textBrowser_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_4 = new QLabel(mouse);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/wheel.png")));

        horizontalLayout_4->addWidget(label_4);

        textBrowser_3 = new QTextBrowser(mouse);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setMaximumSize(QSize(260, 90));

        horizontalLayout_4->addWidget(textBrowser_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(mouse, QString());
        function = new QWidget();
        function->setObjectName(QString::fromUtf8("function"));
        gridLayout_3 = new QGridLayout(function);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        toolButton = new QToolButton(function);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_app_database.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(toolButton);

        label_5 = new QLabel(function);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButton_2 = new QToolButton(function);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/image/Crystal_Clear_action_reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(toolButton_2);

        label_6 = new QLabel(function);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);


        gridLayout_3->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        toolButton_3 = new QToolButton(function);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/image/32px-Crystal_Clear_mimetype_source_r.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(function);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/image/receiveline.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_4);

        label_7 = new QLabel(function);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);


        gridLayout_3->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        toolButton_5 = new QToolButton(function);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/image/s.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(function);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/image/r.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(toolButton_6);

        label_9 = new QLabel(function);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_11->addWidget(label_9);


        gridLayout_3->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        toolButton_7 = new QToolButton(function);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(40, 40));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/image/sr.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon6);
        toolButton_7->setIconSize(QSize(32, 32));

        horizontalLayout_13->addWidget(toolButton_7);

        label_11 = new QLabel(function);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);


        gridLayout_3->addLayout(horizontalLayout_13, 4, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        toolButton_8 = new QToolButton(function);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(40, 40));
        toolButton_8->setMaximumSize(QSize(40, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        toolButton_8->setFont(font1);
        toolButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_14->addWidget(toolButton_8);

        label_12 = new QLabel(function);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_14->addWidget(label_12);


        gridLayout_3->addLayout(horizontalLayout_14, 5, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        toolButton_9 = new QToolButton(function);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setMinimumSize(QSize(40, 40));
        toolButton_9->setMaximumSize(QSize(40, 40));
        toolButton_9->setFont(font1);
        toolButton_9->setIconSize(QSize(32, 32));

        horizontalLayout_15->addWidget(toolButton_9);

        label_13 = new QLabel(function);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);


        gridLayout_3->addLayout(horizontalLayout_15, 6, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        toolButton_10 = new QToolButton(function);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setMinimumSize(QSize(40, 40));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/image/gnome-stock-gnome-run.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon7);
        toolButton_10->setIconSize(QSize(32, 32));

        horizontalLayout_16->addWidget(toolButton_10);

        label_14 = new QLabel(function);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_16->addWidget(label_14);


        gridLayout_3->addLayout(horizontalLayout_16, 7, 0, 1, 1);

        tabWidget->addTab(function, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(Help);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Help", "Help", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        textBrowser->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Clcik the left button, the point you  pointed will be highlight  if the &quot;relation&quot; action is checked. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The points which have relation  with the point will also be hightlighted by different colors. </p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        textBrowser_2->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click the right button and hold it, you can drag a rectangle out. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">With the relaease of the right button, the image in the rectangle you dragged will be zoom in. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inde"
                        "nt:0px;\">Notice: If you just clicked or drag a very small rectangle, the system will do nothing to answer your operation.</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        textBrowser_3->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You can use mouse whell scroll up or down the dispaly area.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you push the middle button, the image will be resized.</p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(mouse), QApplication::translate("Help", "Mouse", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Help", "Combine SPS files into one, so that you can see the whole work area.", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Help", "Reset the image whether you want to look the default size of the image.", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Help", "Click and show the shot line or receive line.", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Help", "click and the shot point or receive point will connect by a line.", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Help", "Press this to open the relation function, just right click the point the related points will be highlighted.", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("Help", "CMP", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Help", "Show the CMP(Common Depth Point) of the current work area. ", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("Help", "FOLD", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Help", "Show the fold numbers of the current area(Based on the CMP).", 0, QApplication::UnicodeUTF8));
        toolButton_10->setText(QApplication::translate("Help", "...", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Help", "Fold numbers` option. Include  grid data and the colormap.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(function), QApplication::translate("Help", "Function", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Help);
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
