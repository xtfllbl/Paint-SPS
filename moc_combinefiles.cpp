/****************************************************************************
** Meta object code from reading C++ file 'combinefiles.h'
**
** Created: Fri Jan 22 10:35:41 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "combinefiles.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combinefiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CombineFiles[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   13,   13,   13, 0x08,
      56,   13,   13,   13, 0x08,
      76,   13,   13,   13, 0x08,
      99,   13,   13,   13, 0x08,
     118,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CombineFiles[] = {
    "CombineFiles\0\0on_btnReset_clicked()\0"
    "on_btnAdd_clicked()\0on_btnDel_clicked()\0"
    "on_btnCancel_clicked()\0on_btnOK_clicked()\0"
    "on_btnCombineFile_clicked()\0"
};

const QMetaObject CombineFiles::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CombineFiles,
      qt_meta_data_CombineFiles, 0 }
};

const QMetaObject *CombineFiles::metaObject() const
{
    return &staticMetaObject;
}

void *CombineFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CombineFiles))
        return static_cast<void*>(const_cast< CombineFiles*>(this));
    return QDialog::qt_metacast(_clname);
}

int CombineFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnReset_clicked(); break;
        case 1: on_btnAdd_clicked(); break;
        case 2: on_btnDel_clicked(); break;
        case 3: on_btnCancel_clicked(); break;
        case 4: on_btnOK_clicked(); break;
        case 5: on_btnCombineFile_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
