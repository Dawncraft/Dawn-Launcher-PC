#include "DLTrayMenu.h"
#include <QApplication>

DLTrayMenu::DLTrayMenu(QWidget *parent) : QMenu(parent), actionRecentGames()
{
    // TODO 托盘菜单最近游戏

    addSeparator();

    actionShow = new QAction(QIcon(":/menu/show"), "显示", this);
    connect(actionShow, SIGNAL(triggered(bool)), this, SLOT(showWindow()));
    addAction(actionShow);

    actionSettings = new QAction(QIcon(":/menu/setting"), "设置", this);
    connect(actionSettings, SIGNAL(triggered(bool)), this, SLOT(openSettings()));
    addAction(actionSettings);

    actionQuit = new QAction(QIcon(":/menu/quit"), "退出", this);
    connect(actionQuit, SIGNAL(triggered(bool)), this, SLOT(quit()));
    addAction(actionQuit);
}

DLTrayMenu::~DLTrayMenu()
{
}

void DLTrayMenu::showWindow()
{
    emit showMainWindow();
}

void DLTrayMenu::openSettings()
{
    // TODO 打开设置对话框未实现
}

void DLTrayMenu::quit()
{
    qApp->quit();
}
