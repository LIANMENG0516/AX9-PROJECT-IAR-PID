/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[25];
    char stringdata0[488];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "chartSignal"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "slot_RecvPortData"
QT_MOC_LITERAL(4, 38, 15), // "on_timerReadVol"
QT_MOC_LITERAL(5, 54, 14), // "on_chartUpData"
QT_MOC_LITERAL(6, 69, 16), // "on_timer_timeout"
QT_MOC_LITERAL(7, 86, 18), // "on_btnScan_clicked"
QT_MOC_LITERAL(8, 105, 18), // "on_btnOpen_clicked"
QT_MOC_LITERAL(9, 124, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(10, 144, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(11, 163, 22), // "on_btnClearRev_clicked"
QT_MOC_LITERAL(12, 186, 23), // "on_btnClearSend_clicked"
QT_MOC_LITERAL(13, 210, 19), // "on_btnStart_clicked"
QT_MOC_LITERAL(14, 230, 23), // "on_btnFwVersion_clicked"
QT_MOC_LITERAL(15, 254, 25), // "on_btnCompileInfo_clicked"
QT_MOC_LITERAL(16, 280, 25), // "on_btnRdHwVersion_clicked"
QT_MOC_LITERAL(17, 306, 25), // "on_btnWrHwVersion_clicked"
QT_MOC_LITERAL(18, 332, 22), // "on_btnTempInfo_clicked"
QT_MOC_LITERAL(19, 355, 23), // "on_btnPowerInfo_clicked"
QT_MOC_LITERAL(20, 379, 21), // "on_btnFanInfo_clicked"
QT_MOC_LITERAL(21, 401, 25), // "on_btnVoltageInfo_clicked"
QT_MOC_LITERAL(22, 427, 19), // "on_btnSetHv_clicked"
QT_MOC_LITERAL(23, 447, 20), // "on_btnGetVol_clicked"
QT_MOC_LITERAL(24, 468, 19) // "on_btnSetCw_clicked"

    },
    "Widget\0chartSignal\0\0slot_RecvPortData\0"
    "on_timerReadVol\0on_chartUpData\0"
    "on_timer_timeout\0on_btnScan_clicked\0"
    "on_btnOpen_clicked\0on_btnClose_clicked\0"
    "on_btnSend_clicked\0on_btnClearRev_clicked\0"
    "on_btnClearSend_clicked\0on_btnStart_clicked\0"
    "on_btnFwVersion_clicked\0"
    "on_btnCompileInfo_clicked\0"
    "on_btnRdHwVersion_clicked\0"
    "on_btnWrHwVersion_clicked\0"
    "on_btnTempInfo_clicked\0on_btnPowerInfo_clicked\0"
    "on_btnFanInfo_clicked\0on_btnVoltageInfo_clicked\0"
    "on_btnSetHv_clicked\0on_btnGetVol_clicked\0"
    "on_btnSetCw_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  130,    2, 0x08 /* Private */,
       4,    0,  131,    2, 0x08 /* Private */,
       5,    0,  132,    2, 0x08 /* Private */,
       6,    0,  133,    2, 0x08 /* Private */,
       7,    0,  134,    2, 0x08 /* Private */,
       8,    0,  135,    2, 0x08 /* Private */,
       9,    0,  136,    2, 0x08 /* Private */,
      10,    0,  137,    2, 0x08 /* Private */,
      11,    0,  138,    2, 0x08 /* Private */,
      12,    0,  139,    2, 0x08 /* Private */,
      13,    0,  140,    2, 0x08 /* Private */,
      14,    0,  141,    2, 0x08 /* Private */,
      15,    0,  142,    2, 0x08 /* Private */,
      16,    0,  143,    2, 0x08 /* Private */,
      17,    0,  144,    2, 0x08 /* Private */,
      18,    0,  145,    2, 0x08 /* Private */,
      19,    0,  146,    2, 0x08 /* Private */,
      20,    0,  147,    2, 0x08 /* Private */,
      21,    0,  148,    2, 0x08 /* Private */,
      22,    0,  149,    2, 0x08 /* Private */,
      23,    0,  150,    2, 0x08 /* Private */,
      24,    0,  151,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chartSignal(); break;
        case 1: _t->slot_RecvPortData(); break;
        case 2: _t->on_timerReadVol(); break;
        case 3: _t->on_chartUpData(); break;
        case 4: _t->on_timer_timeout(); break;
        case 5: _t->on_btnScan_clicked(); break;
        case 6: _t->on_btnOpen_clicked(); break;
        case 7: _t->on_btnClose_clicked(); break;
        case 8: _t->on_btnSend_clicked(); break;
        case 9: _t->on_btnClearRev_clicked(); break;
        case 10: _t->on_btnClearSend_clicked(); break;
        case 11: _t->on_btnStart_clicked(); break;
        case 12: _t->on_btnFwVersion_clicked(); break;
        case 13: _t->on_btnCompileInfo_clicked(); break;
        case 14: _t->on_btnRdHwVersion_clicked(); break;
        case 15: _t->on_btnWrHwVersion_clicked(); break;
        case 16: _t->on_btnTempInfo_clicked(); break;
        case 17: _t->on_btnPowerInfo_clicked(); break;
        case 18: _t->on_btnFanInfo_clicked(); break;
        case 19: _t->on_btnVoltageInfo_clicked(); break;
        case 20: _t->on_btnSetHv_clicked(); break;
        case 21: _t->on_btnGetVol_clicked(); break;
        case 22: _t->on_btnSetCw_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::chartSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void Widget::chartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
