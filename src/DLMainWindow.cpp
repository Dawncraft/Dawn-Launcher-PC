#include "DLMainWindow.h"

DLMainWindow::DLMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setObjectName("mainWindow");
    setWindowIcon(QIcon(":/icon.ico"));
    setWindowTitle("曙光游戏平台");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    resize(1000, 570);
    setCentralWidget(new QWidget(parent));

    QVBoxLayout *layout = new QVBoxLayout(centralWidget());
    layout->setMargin(0);
    layout->setSpacing(0);

    navigationBar = new DLNavigationBar(this);
    installEventFilter(navigationBar);
    connect(navigationBar, SIGNAL(changeStackedWidgetIndex(int)), this, SLOT(setStackedWidgetIndex(int)));
    layout->addWidget(navigationBar);

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

DLMainWindow::~DLMainWindow()
{

}

void DLMainWindow::setStackedWidgetIndex(int index)
{
    stackedWidget->setCurrentIndex(index);
}

void DLMainWindow::onActivated(QSystemTrayIcon::ActivationReason reason)
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
