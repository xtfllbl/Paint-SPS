/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Dec 25 14:04:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     317,   11,   11,   11, 0x08,
     351,   11,   11,   11, 0x08,
     381,   11,   11,   11, 0x08,
     408,   11,   11,   11, 0x08,
     434,   11,   11,   11, 0x08,
     444,   11,   11,   11, 0x08,
     473,   11,   11,   11, 0x08,
     505,   11,   11,   11, 0x08,
     547,  541,   11,   11, 0x08,
     577,   11,   11,   11, 0x08,
     610,  602,   11,   11, 0x08,
     630,   11,   11,   11, 0x08,
     657,   11,   11,   11, 0x08,
     675,   11,   11,   11, 0x08,
     687,   11,   11,   11, 0x08,
     709,   11,   11,   11, 0x08,
     723,   11,   11,   11, 0x08,
     743,   11,   11,   11, 0x08,
     768,   11,   11,   11, 0x08,
     780,  778,   11,   11, 0x08,
     816,  778,   11,   11, 0x08,
     846,  778,   11,   11, 0x08,
     885,  778,   11,   11, 0x08,
     918,  778,   11,   11, 0x08,
     949,  778,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionHelp_triggered()\0"
    "on_actionOption_triggered()\0"
    "on_actionCMP_triggered()\0"
    "on_actionReceivePointLine_triggered()\0"
    "on_actionShotPointLine_triggered()\0"
    "on_actionFoldNumbers_triggered()\0"
    "on_actionReceiveLine_triggered()\0"
    "on_actionShotLine_triggered()\0"
    "on_actionClose_triggered()\0"
    "on_actionAbout_QT_triggered()\0"
    "on_actionCombineFiles_triggered()\0"
    "on_actionRelation_triggered()\0"
    "on_actionReset_triggered()\0"
    "on_actionOpen_triggered()\0setData()\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "mouseDoubleClickEvent(QMouseEvent*)\0"
    "event\0mousePressEvent(QMouseEvent*)\0"
    "paintEvent(QPaintEvent*)\0painter\0"
    "paintCor(QPainter*)\0resizeEvent(QResizeEvent*)\0"
    "setFileLocation()\0frontOpen()\0"
    "combineFilesIntoOne()\0applyChange()\0"
    "setProgressBar(int)\0setProgressBarValue(int)\0"
    "hideBar()\0,\0setShotLineColorMain(QColor,double)\0"
    "setShotLineShapeMain(int,int)\0"
    "setReceiveLineColorMain(QColor,double)\0"
    "setReceiveLineShapeMain(int,int)\0"
    "setCMPColorMain(QColor,double)\0"
    "setCMPShapeMain(int,int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionHelp_triggered(); break;
        case 1: on_actionOption_triggered(); break;
        case 2: on_actionCMP_triggered(); break;
        case 3: on_actionReceivePointLine_triggered(); break;
        case 4: on_actionShotPointLine_triggered(); break;
        case 5: on_actionFoldNumbers_triggered(); break;
        case 6: on_actionReceiveLine_triggered(); break;
        case 7: on_actionShotLine_triggered(); break;
        case 8: on_actionClose_triggered(); break;
        case 9: on_actionAbout_QT_triggered(); break;
        case 10: on_actionCombineFiles_triggered(); break;
        case 11: on_actionRelation_triggered(); break;
        case 12: on_actionReset_triggered(); break;
        case 13: on_actionOpen_triggered(); break;
        case 14: setData(); break;
        case 15: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 16: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 17: mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 18: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 19: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 20: paintCor((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 21: resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 22: setFileLocation(); break;
        case 23: frontOpen(); break;
        case 24: combineFilesIntoOne(); break;
        case 25: applyChange(); break;
        case 26: setProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: setProgressBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: hideBar(); break;
        case 29: setShotLineColorMain((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 30: setShotLineShapeMain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: setReceiveLineColorMain((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 32: setReceiveLineShapeMain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: setCMPColorMain((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 34: setCMPShapeMain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
