#include "DLMainWindow.h"

DLMainWindow::DLMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setObjectName("mainWindow");
    setWindowIcon(QIcon(":/icon.ico"));
    setWindowTitle(tr("DGP"));
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setMinimumSize(1000, 570);
    setCentralWidget(new QWidget(this));

    QStackedLayout *layoutMain = new QStackedLayout(this);
    layoutMain->setSizeConstraint(QLayout::SetMinimumSize);
    layoutMain->setMargin(0);
    layoutMain->setSpacing(0);
    layoutMain->setStackingMode(QStackedLayout::StackAll);

    m_navigationBar = new DLNavigationBar(this);
    installEventFilter(m_navigationBar);
    connect(m_navigationBar, SIGNAL(changePageIndex(int)), this, SLOT(onPageIndexChanged(int)));
    layoutMain->addWidget(m_navigationBar);

    m_backgroundWidget = new DLBlurBackgroundWidget(this);
    m_backgroundWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    m_backgroundWidget->setFixedHeight(m_navigationBar->height());
    layoutMain->addWidget(m_backgroundWidget);

    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setContentsMargins(0, 0, 0, 0);
    m_backgroundWidget->setBackground(m_stackedWidget);
    layoutMain->addWidget(m_stackedWidget);

    DLPageHome *pageHome = new DLPageHome(this);
    pageHome->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageHome);

    StorePage *pageStore = new StorePage(this);
    pageStore->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageStore);

    NewsPage *pageNews = new NewsPage(this);
    pageNews->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageNews);

    BBSPage *pageForum = new BBSPage(this);
    pageForum->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageForum);

    ChatPage *pageChat = new ChatPage(this);
    pageChat->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageChat);

    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(windowIcon());
    m_trayIcon->setToolTip(windowTitle());
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayActivated(QSystemTrayIcon::ActivationReason)));
    m_trayIcon->show();

    m_trayMenu = new DLTrayMenu(this);
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
