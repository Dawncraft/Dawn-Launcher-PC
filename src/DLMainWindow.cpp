#include "DLMainWindow.h"

DLMainWindow::DLMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/icon.ico"));
    setWindowTitle("DGP");

    setObjectName("mainWindow");
    setAttribute(Qt::WA_TranslucentBackground); // 启用透明背景, 方便自定义边框阴影效果
    setWindowFlags(Qt::FramelessWindowHint); // 无边框和标题栏, 方便自定义边框和标题栏
    setContentsMargins(0, 0, 0, 0);
    setMinimumSize(1000, 570);

    m_frameWidget = new DLWindowFrameWidget(this, 20);
    setCentralWidget(m_frameWidget);

    QStackedLayout *layoutRoot = new QStackedLayout();
    layoutRoot->setStackingMode(QStackedLayout::StackAll);
    layoutRoot->setMargin(0);
    layoutRoot->setSpacing(0);
    m_frameWidget->setLayout(layoutRoot);

    m_navigationBar = new DLNavigationBar(m_frameWidget);
    installEventFilter(m_navigationBar);
    connect(m_navigationBar, SIGNAL(changePageIndex(int)), this, SLOT(onPageIndexChanged(int)));
    layoutRoot->addWidget(m_navigationBar);

    m_backgroundWidget = new DLBlurBackgroundWidget(m_frameWidget);
    m_backgroundWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_backgroundWidget->setMinimumWidth(minimumSize().width());
    m_backgroundWidget->setFixedHeight(m_navigationBar->height());
    layoutRoot->addWidget(m_backgroundWidget);

    m_stackedWidget = new QStackedWidget(m_frameWidget);
    m_stackedWidget->setContentsMargins(0, 0, 0, 0);
    m_backgroundWidget->setBackground(m_stackedWidget);
    layoutRoot->addWidget(m_stackedWidget);

    DLPageHome *pageHome = new DLPageHome(m_frameWidget);
    pageHome->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageHome);

    StorePage *pageStore = new StorePage(m_frameWidget);
    pageStore->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageStore);

    NewsPage *pageNews = new NewsPage(m_frameWidget);
    pageNews->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageNews);

    BBSPage *pageForum = new BBSPage(m_frameWidget);
    pageForum->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageForum);

    ChatPage *pageChat = new ChatPage(m_frameWidget);
    pageChat->setContentsMargins(0, 0, 0, 0);
    m_stackedWidget->addWidget(pageChat);

    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setObjectName("trayIcon");
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
