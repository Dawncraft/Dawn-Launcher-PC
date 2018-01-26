#include "NavigationBar.h"

NavigationBar::NavigationBar(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(70);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onTabClicked(QAbstractButton*)));

    QToolButton *buttonBrand = new QToolButton(this);
    buttonBrand->setObjectName("buttonBrand");
    buttonBrand->setFixedWidth(120);
    buttonBrand->setFixedHeight(this->height());
    buttonBrand->setArrowType(Qt::DownArrow);
    buttonBrand->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    buttonBrand->setPopupMode(QToolButton::InstantPopup);
    buttonBrand->setIcon(parent->windowIcon());
    buttonBrand->setText(parent->windowTitle());
    buttonBrand->setToolTip("Main Menu");
    connect(buttonBrand, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    layout->addWidget(buttonBrand);

    QMenu *menu = new QMenu(this);
    menu->addAction("Test");
    buttonBrand->setMenu(menu);

    QPushButton *buttonHome = new QPushButton(this);
    buttonHome->setObjectName("navTabButton");
    buttonHome->setFixedWidth(100);
    buttonHome->setFixedHeight(this->height());
    buttonHome->setCheckable(true);
    buttonHome->setChecked(true);
    buttonHome->setText("主页");
    buttonGroup->addButton(buttonHome, 0);
    layout->addWidget(buttonHome);

    QPushButton *buttonNews = new QPushButton(this);
    buttonNews->setObjectName("navTabButton");
    buttonNews->setFixedWidth(100);
    buttonNews->setFixedHeight(this->height());
    buttonNews->setCheckable(true);
    buttonNews->setText("新闻");
    buttonGroup->addButton(buttonNews, 1);
    layout->addWidget(buttonNews);

    QPushButton *buttonBBS = new QPushButton(this);
    buttonBBS->setObjectName("navTabButton");
    buttonBBS->setFixedWidth(100);
    buttonBBS->setFixedHeight(this->height());
    buttonBBS->setCheckable(true);
    buttonBBS->setText("论坛");
    buttonGroup->addButton(buttonBBS, 2);
    layout->addWidget(buttonBBS);

    QPushButton *buttonGames = new QPushButton(this);
    buttonGames->setObjectName("navTabButton");
    buttonGames->setFixedWidth(100);
    buttonGames->setFixedHeight(this->height());
    buttonGames->setCheckable(true);
    buttonGames->setText("游戏库");
    buttonGroup->addButton(buttonGames, 3);
    layout->addWidget(buttonGames);

    QPushButton *buttonFriends = new QPushButton(this);
    buttonFriends->setObjectName("navTabButton");
    buttonFriends->setFixedWidth(100);
    buttonFriends->setFixedHeight(this->height());
    buttonFriends->setCheckable(true);
    buttonFriends->setText("好友");
    buttonGroup->addButton(buttonFriends, 4);
    layout->addWidget(buttonFriends);

    layout->addStretch();

    QLabel *user = new QLabel(this);
    user->setText("未登录");
    layout->addWidget(user);
}

NavigationBar::~NavigationBar()
{

}

void NavigationBar::onClicked()
{
    QWidget *window = this->window();
    if (window->isTopLevel())
    {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(sender());
        if (button == buttonBrand)
        {
            return;
        }
    }
}

void NavigationBar::onTabClicked(QAbstractButton *button)
{
    QWidget *window = this->window();
    if (window->isTopLevel())
    {
        foreach (QAbstractButton *i, buttonGroup->buttons())
        {
            if (button == i)
            {
                emit changeStackedWidgetIndex(buttonGroup->id(i));
            }
        }
    }
}
