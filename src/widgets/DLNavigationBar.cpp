#include "DLNavigationBar.h"

DLNavigationBar::DLNavigationBar(QWidget *parent) : DLTitleBar(parent)
{
    setObjectName("navigationbar");
    setFixedHeight(100);

    QWidget *stackedWidget = new QWidget(this);
    QStackedLayout *stackedLayout = new QStackedLayout(stackedWidget);
    stackedLayout->setMargin(0);
    stackedLayout->setSpacing(0);
    stackedLayout->setStackingMode(QStackedLayout::StackAll);
    m_layout->addWidget(stackedWidget);

    QWidget *widgetNavBar = new QWidget(this);
    QHBoxLayout *layoutNavBar = new QHBoxLayout(widgetNavBar);
    layoutNavBar->setContentsMargins(5, 0, 5, 0);
    layoutNavBar->setSpacing(0);
    widgetNavBar->setLayout(layoutNavBar);
    stackedLayout->addWidget(widgetNavBar);

    m_buttonBrand = new DLBrandButton(this);
    m_buttonBrand->setIcon(parent->windowIcon());
    m_buttonBrand->setText(parent->windowTitle());
    m_buttonBrand->setToolTip("Main Menu");
    connect(m_buttonBrand, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    layoutNavBar->addWidget(m_buttonBrand);

    QMenu *menuMain = new QMenu(this);
    menuMain->addAction("退出");
    m_buttonBrand->setMenu(menuMain);

    m_tabbarNavigation = new DLNavTabBar(this);
    m_tabbarNavigation->addTab("主页");
    m_tabbarNavigation->addTab("广场");
    m_tabbarNavigation->addTab("新闻");
    m_tabbarNavigation->addTab("论坛");
    m_tabbarNavigation->addTab("好友");
    connect(m_tabbarNavigation, SIGNAL(tabBarClicked(int)), this, SLOT(onTabClicked(int)));
    layoutNavBar->addWidget(m_tabbarNavigation);

    layoutNavBar->addStretch();

    m_widgetUser = new DLUserWidget(this);
    layoutNavBar->addWidget(m_widgetUser);

    m_backgroundWidget = new DLBlurBackgroundWidget(stackedWidget);
    m_backgroundWidget->setFixedHeight(70);
    stackedLayout->addWidget(m_backgroundWidget);
}

DLNavigationBar::~DLNavigationBar()
{
}

void DLNavigationBar::setBackgroundWidget(QWidget *widget)
{
    m_backgroundWidget->setBackground(widget);
}

void DLNavigationBar::onClicked()
{
    QWidget *window = this->window();
    if (window->isTopLevel())
    {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(sender());
        if (button == m_buttonBrand)
        {
            return;
        }
    }
}

void DLNavigationBar::onTabClicked(int index)
{
    QWidget *window = this->window();
    if (window->isTopLevel())
    {
        emit changeStackedWidgetIndex(index);
    }
}

DLBrandButton::DLBrandButton(QWidget *parent)
{
    setObjectName("buttonBrand");
    setFixedWidth(120);
    setFixedHeight(parent->height() - 32);
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    setArrowType(Qt::DownArrow);
    setPopupMode(QToolButton::InstantPopup);
}

DLNavTabBar::DLNavTabBar(QWidget *parent)
{
    setFixedHeight(parent->height() - 32);
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
    setFixedHeight(parent->height() - 32);
    QLabel *labelUser = new QLabel(this);
    labelUser->setText("未登录");
}
