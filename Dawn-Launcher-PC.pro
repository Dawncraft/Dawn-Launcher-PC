#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T18:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dawn-Launcher
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
# Make your code fail to compile if you use deprecated APIs.
# disables all the APIs deprecated before Qt 6.0.0.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

RESOURCES += Resources.qrc

# App information
VERSION = 0.0.0.1
RC_ICONS = icon.ico
RC_LANG = 0x0004
QMAKE_TARGET_PRODUCT = "Dawn Game Platform"
QMAKE_TARGET_DESCRIPTION = "A game platform."
QMAKE_TARGET_COMPANY = "Dawncraft Studio"
QMAKE_TARGET_COPYRIGHT = "Copyright 2002-2017 Dawncraft Studio. All rights reserved."
