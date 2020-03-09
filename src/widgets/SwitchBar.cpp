#include "SwitchBar.h"

SwitchBar::SwitchBar(QWidget *parent, QString games[]) : QWidget(parent)
{
    setFixedWidth(100);
    setFixedHeight(parent->height());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onTabClicked(QAbstractButton*)));

    for (int i = 0; i < 2; i++)
    {
        QPushButton *buttonGame = new QPushButton(this);
        buttonGame->setObjectName("swiTabButton");
        buttonGame->setFixedWidth(this->width());
        buttonGame->setFixedHeight(this->width());
        buttonGame->setCheckable(true);
        if (i == 0) buttonGame->setChecked(true);
        buttonGame->setIcon(QIcon(":/images/" + games[i] + "/icon"));
        buttonGame->setText(games[i]);
        buttonGroup->addButton(buttonGame, i);
        layout->addWidget(buttonGame);
    }

    layout->addStretch();
}

SwitchBar::~SwitchBar()
{

}

void SwitchBar::onTabClicked(QAbstractButton *button)
{

}
