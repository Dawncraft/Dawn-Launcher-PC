#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(1000, 570);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setWindowIcon(QIcon(":/icon"));
    setWindowTitle("曙光游戏平台");
    setCentralWidget(new QWidget(parent));
    setObjectName("mainWindow");

    QVBoxLayout *layout = new QVBoxLayout(centralWidget());
    layout->setMargin(0);
    layout->setSpacing(0);

    titleBar = new TitleBar(this);
    installEventFilter(titleBar);
    layout->addWidget(titleBar);

    navigationBar = new NavigationBar(this);
    navigationBar->setContentsMargins(5, 0, 5, 0);
    layout->addWidget(navigationBar);
    connect(navigationBar, SIGNAL(changeStackedWidgetIndex(int)), this, SLOT(setStackedWidgetIndex(int)));

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setContentsMargins(5, 0, 5, 0);
    stackedWidget->setFixedWidth(this->width());
    stackedWidget->setFixedHeight(this->height() - 100);
    layout->addWidget(stackedWidget);

    HomePage *homePage = new HomePage(this);
    stackedWidget->addWidget(homePage);

    StorePage *storePage = new StorePage(this);
    stackedWidget->addWidget(storePage);

    NewsPage *newsPage = new NewsPage(this);
    stackedWidget->addWidget(newsPage);

    BBSPage *bbsPage = new BBSPage(this);
    stackedWidget->addWidget(bbsPage);

    ChatPage *chatPage = new ChatPage(this);
    stackedWidget->addWidget(chatPage);

    iconTray = new QSystemTrayIcon(this);
    iconTray->setIcon(this->windowIcon());
    iconTray->setToolTip(this->windowTitle());
    connect(iconTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));

    menuTray = new TrayMenu(this);
    menuTray->setObjectName("menuTray");
    iconTray->setContextMenu(menuTray);
    //connect(menuTray, SIGNAL(showWindow()), this, SLOT(showWindow()));

    iconTray->show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setStackedWidgetIndex(int index)
{
    stackedWidget->setCurrentIndex(index);
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
