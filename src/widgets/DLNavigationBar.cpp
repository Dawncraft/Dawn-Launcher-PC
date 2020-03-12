#include "DLNavigationBar.h"

DLNavigationBar::DLNavigationBar(QWidget *parent) : DLTitleBar(parent)
{
    setObjectName("navigationbar");
    setFixedHeight(70);

    QVBoxLayout *layoutNavBar = new QVBoxLayout(this);
    layoutNavBar->setMargin(0);
    layoutNavBar->setSpacing(0);
    this->setLayout(layoutNavBar);

    QWidget *widget1 = new QWidget(this);
    widget1->setLayout(m_layoutTitlebar);
    layoutNavBar->addWidget(widget1);

    QWidget *widget2 = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 0, 5, 0);
    layout->setSpacing(0);
    widget2->setLayout(layout);
    layoutNavBar->addWidget(widget2);

    m_buttonBrand = new DLBrandButton(this);
    m_buttonBrand->setIcon(parent->windowIcon());
    m_buttonBrand->setText(parent->windowTitle());
    m_buttonBrand->setToolTip("Main Menu");
    connect(m_buttonBrand, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    layout->addWidget(m_buttonBrand);

    QMenu *menuMain = new QMenu(this);
    menuMain->addAction("退出");
    m_buttonBrand->setMenu(menuMain);

    m_tabbarNavigation = new DLNavTabBar(this);
    m_tabbarNavigation->addTab("主页");
    m_tabbarNavigation->addTab("广场");
    m_tabbarNavigation->addTab("新闻");
    m_tabbarNavigation->addTab("论坛");
    m_tabbarNavigation->addTab("好友");
    layout->addWidget(m_tabbarNavigation);

    layout->addStretch();

    m_widgetUser = new DLUserWidget(this);
    layout->addWidget(m_widgetUser);
}

DLNavigationBar::~DLNavigationBar()
{
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
