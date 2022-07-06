#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T18:00:00
#
#-------------------------------------------------

QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
TEMPLATE = app

TARGET = Dawn-Launcher

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS +=

FORMS += test.ui

RESOURCES += resources/res.qrc

include(src/src.pri)

# App information
VERSION = 0.0.0.1
RC_ICONS = resources/icon.ico
RC_LANG = 0x0004
QMAKE_TARGET_PRODUCT = "Dawn Game Platform"
QMAKE_TARGET_DESCRIPTION = "Dawn Game Platform"
QMAKE_TARGET_COMPANY = "Dawncraft Studio"
QMAKE_TARGET_COPYRIGHT = "Copyright 2002-2020 Dawncraft Studio."

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
