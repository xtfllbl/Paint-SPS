/****************************************************************************
** Meta object code from reading C++ file 'option.h'
**
** Created: Fri Dec 25 13:11:30 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "option.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'option.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Option[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x05,
      45,    8,    7,    7, 0x05,
      83,    8,    7,    7, 0x05,
     122,    8,    7,    7, 0x05,
     163,    8,    7,    7, 0x05,
     204,    8,    7,    7, 0x05,
     242,    8,    7,    7, 0x05,
     283,    8,    7,    7, 0x05,
     308,    8,    7,    7, 0x05,
     337,    8,    7,    7, 0x05,
     369,    8,    7,    7, 0x05,
     402,    8,    7,    7, 0x05,
     426,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     455,  449,    7,    7, 0x08,
     500,    7,    7,    7, 0x08,
     533,    7,    7,    7, 0x08,
     555,    7,    7,    7, 0x08,
     599,    7,    7,    7, 0x08,
     640,    7,    7,    7, 0x08,
     688,    7,    7,    7, 0x08,
     733,    7,    7,    7, 0x08,
     775,    7,    7,    7, 0x08,
     816,    7,    7,    7, 0x08,
     854,    7,    7,    7, 0x08,
     887,    7,    7,    7, 0x08,
     917,    7,    7,    7, 0x08,
     951,    7,    7,    7, 0x08,
     985,    7,    7,    7, 0x08,
    1016,    7,    7,    7, 0x08,
    1047,    7,    7,    7, 0x08,
    1074,    7,    7,    7, 0x08,
    1096,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Option[] = {
    "Option\0\0,\0signalShotLineColor(QColor,double)\0"
    "signalReceiveLineColor(QColor,double)\0"
    "signalMouseClickedColor(QColor,double)\0"
    "signalMouseClickedSLColor(QColor,double)\0"
    "signalMouseClickedRLColor(QColor,double)\0"
    "signalShotLineConColor(QColor,double)\0"
    "signalReceiveLineConColor(QColor,double)\0"
    "signalCMP(QColor,double)\0"
    "signalShotLineShape(int,int)\0"
    "signalReceiveLineShape(int,int)\0"
    "signalMouseClickedShape(int,int)\0"
    "signalCMPShape(int,int)\0signalCMPAccuracy(int)\0"
    "index\0on_comboCMPAccuracy_currentIndexChanged(int)\0"
    "on_spinCMP_valueChanged(QString)\0"
    "on_btnCMPSC_clicked()\0"
    "on_spinReceiveLineCon_valueChanged(QString)\0"
    "on_spinShotLineCon_valueChanged(QString)\0"
    "on_spinReceiveLineRelated_valueChanged(QString)\0"
    "on_spinShotLineRelated_valueChanged(QString)\0"
    "on_spinMouseClicked_valueChanged(QString)\0"
    "on_spinReceiveLine_valueChanged(QString)\0"
    "on_spinShotLine_valueChanged(QString)\0"
    "on_btnReceiveLineConSC_clicked()\0"
    "on_btnShotLineConSC_clicked()\0"
    "on_btnMouseRelationSCRL_clicked()\0"
    "on_btnMouseRelationSCSL_clicked()\0"
    "on_btnMouseClickedSC_clicked()\0"
    "on_btnReceiverLineSC_clicked()\0"
    "on_btnShotLineSC_clicked()\0"
    "on_btnClose_clicked()\0on_btnApply_clicked()\0"
};

const QMetaObject Option::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Option,
      qt_meta_data_Option, 0 }
};

const QMetaObject *Option::metaObject() const
{
    return &staticMetaObject;
}

void *Option::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Option))
        return static_cast<void*>(const_cast< Option*>(this));
    return QDialog::qt_metacast(_clname);
}

int Option::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalShotLineColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: signalReceiveLineColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: signalMouseClickedColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: signalMouseClickedSLColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: signalMouseClickedRLColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: signalShotLineConColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 6: signalReceiveLineConColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: signalCMP((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: signalShotLineShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: signalReceiveLineShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: signalMouseClickedShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: signalCMPShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: signalCMPAccuracy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_comboCMPAccuracy_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: on_spinCMP_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: on_btnCMPSC_clicked(); break;
        case 16: on_spinReceiveLineCon_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_spinShotLineCon_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_spinReceiveLineRelated_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: on_spinShotLineRelated_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_spinMouseClicked_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: on_spinReceiveLine_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_spinShotLine_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_btnReceiveLineConSC_clicked(); break;
        case 24: on_btnShotLineConSC_clicked(); break;
        case 25: on_btnMouseRelationSCRL_clicked(); break;
        case 26: on_btnMouseRelationSCSL_clicked(); break;
        case 27: on_btnMouseClickedSC_clicked(); break;
        case 28: on_btnReceiverLineSC_clicked(); break;
        case 29: on_btnShotLineSC_clicked(); break;
        case 30: on_btnClose_clicked(); break;
        case 31: on_btnApply_clicked(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void Option::signalShotLineColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Option::signalReceiveLineColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Option::signalMouseClickedColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Option::signalMouseClickedSLColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Option::signalMouseClickedRLColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Option::signalShotLineConColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Option::signalReceiveLineConColor(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Option::signalCMP(QColor _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Option::signalShotLineShape(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Option::signalReceiveLineShape(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Option::signalMouseClickedShape(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Option::signalCMPShape(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Option::signalCMPAccuracy(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
