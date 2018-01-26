#include "NavigationBar.h"

NavigationBar::NavigationBar(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(100);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    buttonBrand = new QToolButton(this);
    buttonBrand->setFixedWidth(this->height());
    buttonBrand->setFixedHeight(this->height());
    buttonBrand->setArrowType(Qt::DownArrow);
    buttonBrand->setText(parent->windowTitle());
    buttonBrand->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    connect(buttonBrand, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    layout->addWidget(buttonBrand);

    buttonHome = new QPushButton(this);
    buttonHome->setObjectName("navTabButton");
    buttonHome->setFixedHeight(this->height());
    buttonHome->setCheckable(true);
    buttonHome->setText("主页");
    layout->addWidget(buttonHome);

    buttonNews = new QPushButton(this);
    buttonNews->setObjectName("navTabButton");
    buttonNews->setFixedHeight(this->height());
    buttonNews->setCheckable(true);
    buttonNews->setText("新闻");
    layout->addWidget(buttonNews);

    buttonBBS = new QPushButton(this);
    buttonBBS->setObjectName("navTabButton");
    buttonBBS->setFixedHeight(this->height());
    buttonBBS->setCheckable(true);
    buttonBBS->setText("论坛");
    layout->addWidget(buttonBBS);

    buttonGames = new QPushButton(this);
    buttonGames->setObjectName("navTabButton");
    buttonGames->setFixedHeight(this->height());
    buttonGames->setCheckable(true);
    buttonGames->setText("游戏库");
    layout->addWidget(buttonGames);

    buttonFriends = new QPushButton(this);
    buttonFriends->setObjectName("navTabButton");
    buttonFriends->setFixedHeight(this->height());
    buttonFriends->setCheckable(true);
    buttonFriends->setText("好友");
    layout->addWidget(buttonFriends);

    layout->addStretch();
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

        }
    }
}
