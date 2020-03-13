#include "HomePage.h"

HomePage::HomePage(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 30 + 70, 5, 5);
    layout->setSpacing(0);

    QString games[] = {"Minecraft", "Ourfirstclass"};

    switchBar = new SwitchBar(this, games);
    layout->addWidget(switchBar);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setContentsMargins(5, 5, 5, 5);
    stackedWidget->setFixedWidth(this->width() - 100);
    stackedWidget->setFixedHeight(this->height());
    layout->addWidget(stackedWidget);

    GamePage *gamePage = new GamePage(this, "Minecraft");
    stackedWidget->addWidget(gamePage);

}

HomePage::~HomePage()
{
}
