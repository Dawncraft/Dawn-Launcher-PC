#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(1000, 570);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setWindowIcon(QIcon(":/icon"));
    setWindowTitle("曙光游戏平台");

    QWidget* widget = new QWidget(parent);
    widget->setFixedWidth(this->width());
    widget->setFixedHeight(this->height());

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setMargin(0);

    titleBar = new TitleBar(this);
    installEventFilter(titleBar);
    layout->addWidget(titleBar);

    layout->addSpacing(2);

    navigationBar = new NavigationBar(this);
    layout->addWidget(navigationBar);

    layout->addStretch();

    setCentralWidget(widget);

    iconTray = new QSystemTrayIcon(this);
    iconTray->setIcon(this->windowIcon());
    iconTray->setToolTip(this->windowTitle());
    connect(iconTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));

    menuTray = new TrayMenu(this);
    menuTray->setObjectName("menuTray");
    iconTray->setContextMenu(menuTray);
    //connect(menuTray, SIGNAL(showWindow()), this, SLOT(showWindow()));

    iconTray->show();

    iconTray->showMessage("欢迎使用曙光游戏平台", "进入官网了解更多!");
}

MainWindow::~MainWindow()
{
    delete this;
}

void MainWindow::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
    {
        break;
    }
    case QSystemTrayIcon::DoubleClick:
    {
        showNormal();
        raise();
        activateWindow();
        break;
    }
    default:
        break;
    }
}
