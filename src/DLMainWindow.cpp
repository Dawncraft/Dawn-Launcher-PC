#include "DLMainWindow.h"

DLMainWindow::DLMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setObjectName("mainWindow");
    setWindowIcon(QIcon(":/icon.ico"));
    setWindowTitle(tr("DGP"));
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setMinimumSize(1000, 570);

    QWidget *widgetMain = new QWidget(this);
    widgetMain->setMinimumSize(minimumSize());
    setCentralWidget(widgetMain);

    QStackedLayout *layoutMain = new QStackedLayout(widgetMain);
    layoutMain->setMargin(0);
    layoutMain->setSpacing(0);
    layoutMain->setStackingMode(QStackedLayout::StackAll);

    m_navigationBar = new DLNavigationBar(widgetMain);
    installEventFilter(m_navigationBar);
    connect(m_navigationBar, SIGNAL(changePageIndex(int)), this, SLOT(onPageIndexChanged(int)));
    layoutMain->addWidget(m_navigationBar);

    m_backgroundWidget = new DLBlurBackgroundWidget(widgetMain);
    m_backgroundWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_backgroundWidget->setMinimumWidth(minimumSize().width());
    m_backgroundWidget->setFixedHeight(m_navigationBar->height());
    layoutMain->addWidget(m_backgroundWidget);

    m_stackedWidget = new QStackedWidget(widgetMain);
    m_stackedWidget->setContentsMargins(0, 0, 0, 0);
    m_backgroundWidget->setBackground(m_stackedWidget);
    layoutMain->addWidget(m_stackedWidget);

    DLPageHome *pageHome = new DLPageHome(widgetMain);
    pageHome->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageHome);

    StorePage *pageStore = new StorePage(widgetMain);
    pageStore->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageStore);

    NewsPage *pageNews = new NewsPage(widgetMain);
    pageNews->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageNews);

    BBSPage *pageForum = new BBSPage(widgetMain);
    pageForum->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageForum);

    ChatPage *pageChat = new ChatPage(widgetMain);
    pageChat->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageChat);

    m_trayIcon = new QSystemTrayIcon(widgetMain);
    m_trayIcon->setIcon(windowIcon());
    m_trayIcon->setToolTip(windowTitle());
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayActivated(QSystemTrayIcon::ActivationReason)));
    m_trayIcon->show();

    m_trayMenu = new DLTrayMenu(widgetMain);
    m_trayMenu->setObjectName("menuTray");
    connect(m_trayMenu, SIGNAL(showMainWindow()), this, SLOT(onShowWindow()));
    m_trayIcon->setContextMenu(m_trayMenu);
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

void DLMainWindow::onPageIndexChanged(int index)
{
    m_stackedWidget->setCurrentIndex(index);
}

void DLMainWindow::onTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
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
