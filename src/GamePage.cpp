#include "GamePage.h"

GamePage::GamePage(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    labelName = new QLabel(this);
    labelName->setAlignment(Qt::AlignCenter);
}

GamePage::~GamePage()
{

}

void GamePage::setGameName(QString name)
{
    labelName->setText(name);
}
