/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created: Fri Jan 22 10:35:39 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,
      38,   32,    9,    9, 0x05,
      58,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,    9,    9,    9, 0x0a,
      90,    9,    9,    9, 0x0a,
      99,    9,    9,    9, 0x0a,
     132,  124,    9,    9, 0x0a,
     160,    9,    9,    9, 0x0a,
     177,    9,    9,    9, 0x0a,
     196,    9,    9,    9, 0x0a,
     203,    9,    9,    9, 0x0a,
     219,    9,    9,    9, 0x0a,
     238,    9,    9,    9, 0x0a,
     266,    9,    9,    9, 0x0a,
     285,    9,    9,    9, 0x0a,
     294,    9,    9,    9, 0x0a,
     312,  310,    9,    9, 0x0a,
     344,  310,    9,    9, 0x0a,
     379,  310,    9,    9, 0x0a,
     415,  310,    9,    9, 0x0a,
     453,  310,    9,    9, 0x0a,
     491,  310,    9,    9, 0x0a,
     526,  310,    9,    9, 0x0a,
     564,  310,    9,    9, 0x0a,
     591,  310,    9,    9, 0x0a,
     617,  310,    9,    9, 0x0a,
     646,  310,    9,    9, 0x0a,
     676,  310,    9,    9, 0x0a,
     697,    9,    9,    9, 0x0a,
     717,    9,    9,    9, 0x08,
     744,  124,    9,    9, 0x08,
     768,  124,    9,    9, 0x08,
     798,  124,    9,    9, 0x08,
     828,  124,    9,    9, 0x08,
     853,  124,    9,    9, 0x08,
     881,  124,    9,    9, 0x08,
     901,  124,    9,    9, 0x08,
     931,  124,    9,    9, 0x08,
     964,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyWidget[] = {
    "MyWidget\0\0max\0signalMaxSet(int)\0value\0"
    "signalValueSet(int)\0signalHideBar()\0"
    "refreshPixmap()\0decide()\0"
    "updateRubberBandRegion()\0painter\0"
    "paintFoldNumbers(QPainter*)\0"
    "setFoldNumbers()\0setFoldTransform()\0"
    "setK()\0axisTransform()\0setShotPointLine()\0"
    "setInterpolationTransform()\0"
    "setAxisTransform()\0setCMP()\0setColorTable()\0"
    ",\0setShotLineColor(QColor,double)\0"
    "setReceiveLineColor(QColor,double)\0"
    "setMouseClickedColor(QColor,double)\0"
    "setMouseClickedSLColor(QColor,double)\0"
    "setMouseClickedRLColor(QColor,double)\0"
    "setShotLineConColor(QColor,double)\0"
    "setReceiveLineConColor(QColor,double)\0"
    "setCMPColor(QColor,double)\0"
    "setShotLineShape(int,int)\0"
    "setReceiveLineShape(int,int)\0"
    "setMouseClickedShape(int,int)\0"
    "setCMPShape(int,int)\0setCMPAccuracy(int)\0"
    "resizeEvent(QResizeEvent*)\0"
    "paintMrRight(QPainter*)\0"
    "paintSfileRelation(QPainter*)\0"
    "paintRfileRelation(QPainter*)\0"
    "paintShotLine(QPainter*)\0"
    "paintReceiveLine(QPainter*)\0"
    "paintCMP(QPainter*)\0paintShotPointLine(QPainter*)\0"
    "paintReceivePointLine(QPainter*)\0"
    "setInterpolation()\0"
};

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget,
      qt_meta_data_MyWidget, 0 }
};

const QMetaObject *MyWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget))
        return static_cast<void*>(const_cast< MyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalMaxSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: signalValueSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: signalHideBar(); break;
        case 3: refreshPixmap(); break;
        case 4: decide(); break;
        case 5: updateRubberBandRegion(); break;
        case 6: paintFoldNumbers((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 7: setFoldNumbers(); break;
        case 8: setFoldTransform(); break;
        case 9: setK(); break;
        case 10: axisTransform(); break;
        case 11: setShotPointLine(); break;
        case 12: setInterpolationTransform(); break;
        case 13: setAxisTransform(); break;
        case 14: setCMP(); break;
        case 15: setColorTable(); break;
        case 16: setShotLineColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: setReceiveLineColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: setMouseClickedColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 19: setMouseClickedSLColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 20: setMouseClickedRLColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 21: setShotLineConColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 22: setReceiveLineConColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 23: setCMPColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 24: setShotLineShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: setReceiveLineShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: setMouseClickedShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: setCMPShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: setCMPAccuracy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 30: paintMrRight((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 31: paintSfileRelation((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 32: paintRfileRelation((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 33: paintShotLine((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 34: paintReceiveLine((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 35: paintCMP((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 36: paintShotPointLine((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 37: paintReceivePointLine((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 38: setInterpolation(); break;
        default: ;
        }
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void MyWidget::signalMaxSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyWidget::signalValueSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyWidget::signalHideBar()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
