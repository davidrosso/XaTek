#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T08:39:58
#
#-------------------------------------------------

QT       += core gui quick qml quickwidgets quickcontrols2 network xml multimedia
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

target.path = /home/root
INSTALLS += target

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XaTek
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    connectivityform.cpp \
    datetimeform.cpp \    
    displayforms.cpp \
    homescreen.cpp \
    insertclotchip.cpp \
    openscanclotchip.cpp \
    passcodeunlock.cpp \
    preparepatient.cpp \
    qualityassuranceform.cpp \
    serviceform.cpp \
    setadminpasscode.cpp \
    setpatientid.cpp \
    settingoptionsform.cpp \
    setuserid.cpp \
    setuserpasscode.cpp \
    verifyclotchip.cpp \
    viewtestresultsform.cpp \
    selectnetwork.cpp \
    bluetoothpairing.cpp \
    timelastdose.cpp \
    collectsample.cpp \
    preheatclotchip.cpp \
    testinprogress.cpp \
    keyboard.cpp \
    testresultdetails.cpp \
    testcomplete.cpp

HEADERS += \
        mainwindow.h \
    connectivityform.h \
    datetimeform.h \
    displayforms.h \
    homescreen.h \
    insertclotchip.h \
    openscanclotchip.h \
    passcodeunlock.h \
    preparepatient.h \
    qualityassuranceform.h \
    serviceform.h \
    setadminpasscode.h \
    setpatientid.h \
    settingoptionsform.h \
    setuserid.h \
    setuserpasscode.h \
    verifyclotchip.h \
    viewtestresultsform.h \
    selectnetwork.h \
    bluetoothpairing.h \
    timelastdose.h \
    collectsample.h \
    preheatclotchip.h \
    testinprogress.h \
    keyboard.h \
    testresultdetails.h \
    testcomplete.h

FORMS += \
        mainwindow.ui \
    homescreen.ui \
    passcodeunlock.ui \
    viewtestresultsform.ui \
    settingoptionsform.ui \
    setadminpasscode.ui \
    serviceform.ui \
    qualityassuranceform.ui \
    displayforms.ui \
    datetimeform.ui \
    connectivityform.ui \
    setuserid.ui \
    setpatientid.ui \
    setuserpasscode.ui \
    verifyclotchip.ui \
    openscanclotchip.ui \
    preparepatient.ui \
    insertclotchip.ui \
    selectnetwork.ui \
    bluetoothpairing.ui \
    timelastdose.ui \
    collectsample.ui \
    preheatclotchip.ui \
    testinprogress.ui \
    keyboard.ui \
    testresultdetails.ui \
    testcomplete.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
