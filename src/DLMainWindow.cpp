#include "DLMainWindow.h"

DLMainWindow::DLMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setObjectName("mainWindow");
    setWindowIcon(QIcon(":/icon.ico"));
    setWindowTitle("曙光游戏平台");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    resize(1000, 570);// TODO 记忆尺寸

    setCentralWidget(new QWidget(parent));
    QStackedLayout *layoutMain = new QStackedLayout(centralWidget());
    layoutMain->setMargin(0);
    layoutMain->setSpacing(0);
    layoutMain->setStackingMode(QStackedLayout::StackAll);

    navigationBar = new DLNavigationBar(this);
    installEventFilter(navigationBar);
    connect(navigationBar, SIGNAL(changeStackedWidgetIndex(int)), this, SLOT(setStackedWidgetIndex(int)));
    layoutMain->addWidget(navigationBar);

    backgroundWidget = new DLBlurBackgroundWidget(this);
    backgroundWidget->setFixedHeight(100);
    layoutMain->addWidget(backgroundWidget);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setContentsMargins(0, 30, 0, 0);
    backgroundWidget->setBackground(stackedWidget);
    layoutMain->addWidget(stackedWidget);

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

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->windowIcon());
    trayIcon->setToolTip(this->windowTitle());
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayActivated(QSystemTrayIcon::ActivationReason)));
    trayIcon->show();

    trayMenu = new DLTrayMenu(this);
    trayMenu->setObjectName("menuTray");
    connect(trayMenu, SIGNAL(showMainWindow()), this, SLOT(onShowWindow()));
    trayIcon->setContextMenu(trayMenu);
}

DLMainWindow::~DLMainWindow()
{
}

void DLMainWindow::onShowWindow()
{
    showNormal();
    raise();
    activateWindow();
}

void DLMainWindow::setStackedWidgetIndex(int index)
{
    stackedWidget->setCurrentIndex(index);
}

void DLMainWindow::onTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger:
        {
            break;
        }
        case QSystemTrayIcon::DoubleClick:
        {
            onShowWindow();
            break;
        }
        default: break;
    }
}
