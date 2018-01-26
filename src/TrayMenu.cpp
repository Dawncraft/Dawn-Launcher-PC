#include "TrayMenu.h"

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
    actionShow = new QAction(QIcon(":/menu/show"), "显示", this);
    //connect(actionShow, SIGNAL(triggered(bool)), this, SIGNAL(showWindow()));
    addAction(actionShow);

    actionSetting = new QAction(QIcon(":/menu/setting"), "设置", this);
    //connect(actionSetting, SIGNAL(triggered(bool)), this, SIGNAL(openSetting()));
    addAction(actionSetting);

    addSeparator();

    actionQuit = new QAction(QIcon(":/menu/quit"), "退出", this);
    //connect(actionQuit, SIGNAL(triggered(bool)), this, SIGNAL(exit()));
    addAction(actionQuit);
}

TrayMenu::~TrayMenu()
{

}
