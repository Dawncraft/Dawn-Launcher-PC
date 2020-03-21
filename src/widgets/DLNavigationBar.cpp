#include "DLNavigationBar.h"

DLNavigationBar::DLNavigationBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("navigationBar");
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    setMinimumWidth(parent->width());
    setFixedHeight(100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    m_titleBar = new DLTitleBar(this);
    m_titleBar->setStyleSheet("DLTitleBar {background: transparent;}");
    layout->addWidget(m_titleBar);

    QWidget *widgetNavBar = new QWidget(this);
    widgetNavBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    widgetNavBar->setMinimumWidth(parent->width());
    widgetNavBar->setFixedHeight(height());
    widgetNavBar->setStyleSheet("QWidget {background: transparent;}");

    QHBoxLayout *layoutNavBar = new QHBoxLayout(widgetNavBar);
    layoutNavBar->setContentsMargins(5, 0, 5, 0);
    layoutNavBar->setSpacing(0);
    widgetNavBar->setLayout(layoutNavBar);
    layout->addWidget(widgetNavBar);

    m_widgetBrand = new DLBrandWidget(widgetNavBar);
    layoutNavBar->addWidget(m_widgetBrand);

    m_tabBarNav = new DLNavTabBar(widgetNavBar);
    m_tabBarNav->addTab("主页");
    m_tabBarNav->addTab("广场");
    m_tabBarNav->addTab("新闻");
    m_tabBarNav->addTab("论坛");
    m_tabBarNav->addTab("好友");
    connect(m_tabBarNav, SIGNAL(tabBarClicked(int)), this, SLOT(onTabClicked(int)));
    layoutNavBar->addWidget(m_tabBarNav);

    layoutNavBar->addStretch();

    m_widgetUser = new DLUserWidget(widgetNavBar);
    layoutNavBar->addWidget(m_widgetUser);
}

DLNavigationBar::~DLNavigationBar()
{
}

bool DLNavigationBar::eventFilter(QObject *obj, QEvent *event)
{
    return m_titleBar->eventFilter(obj, event);
}

void DLNavigationBar::mousePressEvent(QMouseEvent *event)
{
    return m_titleBar->mousePressEvent(event);
}

void DLNavigationBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    return m_titleBar->mouseDoubleClickEvent(event);
}

void DLNavigationBar::mouseMoveEvent(QMouseEvent *event)
{
    return m_titleBar->mouseMoveEvent(event);
}

void DLNavigationBar::mouseReleaseEvent(QMouseEvent *event)
{
    return m_titleBar->mouseReleaseEvent(event);
}

void DLNavigationBar::onTabClicked(int index)
{
    if (window()->isTopLevel())
    {
        emit changePageIndex(index);
    }
}

DLBrandWidget::DLBrandWidget(QWidget *parent)
{
    setFixedSize(100, parent->height() - 30);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignHCenter);
    setLayout(layout);

    m_buttonBrand = new QToolButton(this);
    m_buttonBrand->setFixedWidth(100);
    m_buttonBrand->setFixedHeight(50);
    m_buttonBrand->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_buttonBrand->setArrowType(Qt::DownArrow);
    m_buttonBrand->setPopupMode(QToolButton::InstantPopup);
    m_buttonBrand->setIcon(parent->windowIcon()); // TODO 菜单大图标
    m_buttonBrand->setToolTip(tr("Main Menu"));
    layout->addWidget(m_buttonBrand);

    QMenu *menuMain = new QMenu(this);
    menuMain->addAction(tr("Quit"));
    m_buttonBrand->setMenu(menuMain);

    layout->addSpacing(5);

    m_progressBar = new QProgressBar(this);
    m_progressBar->setFixedWidth(100);
    m_progressBar->setFixedHeight(5);
    m_progressBar->setTextVisible(false);
    layout->addWidget(m_progressBar);
    // TODO 更新进度条
}

DLNavTabBar::DLNavTabBar(QWidget *parent)
{
    setFixedHeight(parent->height() - 30);
    setDrawBase(false);
    setExpanding(false);
    setUsesScrollButtons(false);
    setMovable(false);
    setTabsClosable(false);
}

QSize DLNavTabBar::tabSizeHint(int index) const
{
    return QSize(100, 70);
}

DLUserWidget::DLUserWidget(QWidget *parent)
{
    setFixedWidth(70);
    setFixedHeight(parent->height() - 30);
    QLabel *labelUser = new QLabel(this);
    labelUser->setText("未登录");
}
