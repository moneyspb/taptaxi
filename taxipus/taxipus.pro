QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase.cpp \
    addclientdialog.cpp \
    addmanagerdialog.cpp \
    addmodelcardialog.cpp \
    addtaxistdialog.cpp \
    adminmenudialog.cpp \
    base_repository.cpp \
    basecombomodel.cpp \
    client.cpp \
    client_repository.cpp \
    clientssssdialog.cpp \
    dontknowdialog.cpp \
    loginmenegerdialog.cpp \
    main.cpp \
    manager.cpp \
    manager_repository.cpp \
    managersdialog.cpp \
    mathLibrary.cpp \
    model_car.cpp \
    model_car_repository.cpp \
    modelcarsdialog.cpp \
    order.cpp \
    order_repository.cpp \
    orderdialog.cpp \
    orderswindow.cpp \
    person.cpp \
    person_repository.cpp \
    taptaxi.cpp \
    taxist.cpp \
    taxist_repository.cpp \
    taxistssssdialog.cpp

HEADERS += \
    DataBase.h \
    addclientdialog.h \
    addmanagerdialog.h \
    addmodelcardialog.h \
    addtaxistdialog.h \
    adminmenudialog.h \
    applicationhelper.h \
    base_repository.h \
    basecombomodel.h \
    client.h \
    client_repository.h \
    clientssssdialog.h \
    dontknowdialog.h \
    loginmenegerdialog.h \
    manager.h \
    manager_repository.h \
    managersdialog.h \
    managerssssdialog.h \
    mathLibrary.h \
    model_car.h \
    model_car_repository.h \
    modelcarsdialog.h \
    order.h \
    order_repository.h \
    orderdialog.h \
    orderswindow.h \
    person.h \
    person_repository.h \
    role.h \
    status_order.h \
    taptaxi.h \
    tariff.h \
    taxist.h \
    taxist_repository.h \
    taxistssssdialog.h

FORMS += \
    addclientdialog.ui \
    addmanagerdialog.ui \
    addmodelcardialog.ui \
    addtaxistdialog.ui \
    adminmenudialog.ui \
    clientssssdialog.ui \
    dontknowdialog.ui \
    loginmenegerdialog.ui \
    managersdialog.ui \
    modelcarsdialog.ui \
    orderdialog.ui \
    orderswindow.ui \
    taptaxi.ui \
    taxistssssdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
