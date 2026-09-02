/****************************************************************************
** Meta object code from reading C++ file 'PaginaModificaAttivita.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UI/PaginaModificaAttivita.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PaginaModificaAttivita.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN22PaginaModificaAttivitaE_t {};
} // unnamed namespace

template <> constexpr inline auto PaginaModificaAttivita::qt_create_metaobjectdata<qt_meta_tag_ZN22PaginaModificaAttivitaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PaginaModificaAttivita",
        "tornaIndietro",
        "",
        "modificheSalvate",
        "modificaAttivita",
        "Attivita*",
        "a"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'tornaIndietro'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modificheSalvate'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modificaAttivita'
        QtMocHelpers::SignalData<void(Attivita *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PaginaModificaAttivita, qt_meta_tag_ZN22PaginaModificaAttivitaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PaginaModificaAttivita::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22PaginaModificaAttivitaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22PaginaModificaAttivitaE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22PaginaModificaAttivitaE_t>.metaTypes,
    nullptr
} };

void PaginaModificaAttivita::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PaginaModificaAttivita *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->tornaIndietro(); break;
        case 1: _t->modificheSalvate(); break;
        case 2: _t->modificaAttivita((*reinterpret_cast<std::add_pointer_t<Attivita*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PaginaModificaAttivita::*)()>(_a, &PaginaModificaAttivita::tornaIndietro, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PaginaModificaAttivita::*)()>(_a, &PaginaModificaAttivita::modificheSalvate, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PaginaModificaAttivita::*)(Attivita * )>(_a, &PaginaModificaAttivita::modificaAttivita, 2))
            return;
    }
}

const QMetaObject *PaginaModificaAttivita::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaginaModificaAttivita::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22PaginaModificaAttivitaE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PaginaModificaAttivita::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PaginaModificaAttivita::tornaIndietro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PaginaModificaAttivita::modificheSalvate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PaginaModificaAttivita::modificaAttivita(Attivita * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
