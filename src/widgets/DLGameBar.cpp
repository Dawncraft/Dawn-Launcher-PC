#include "DLGameBar.h"

#include <QPushButton>

DLGameBar::DLGameBar(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addSpacing(105);

    // TODO 游戏选择栏

    layout->addStretch();

    m_buttonHide = new QPushButton(this);
    m_buttonHide->setFixedWidth(32);
    m_buttonHide->setFixedHeight(32);
    m_buttonHide->setCheckable(true);
    layout->addWidget(m_buttonHide);

    layout->addSpacing(10);
}

DLGameBar::~DLGameBar()
{
}

void DLGameBar::onTabClicked(QAbstractButton *button)
{

}
