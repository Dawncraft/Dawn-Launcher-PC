#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T18:00:00
#
#-------------------------------------------------

QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += C++11
TEMPLATE = app

TARGET = Dawn-Launcher

# Make your code fail to compile if you use deprecated APIs.
# disables all the APIs deprecated before Qt 6.0.0.
DEFINES += QT_DEPRECATED_WARNINGS #QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES +=

HEADERS +=

FORMS +=

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
