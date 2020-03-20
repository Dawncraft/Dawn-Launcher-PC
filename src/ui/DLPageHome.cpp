#include "DLPageHome.h"

DLPageHome::DLPageHome(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(5);

    m_gameBar = new DLGameBar(this);
    layout->addWidget(m_gameBar);

    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setContentsMargins(5, 5, 5, 5);
    m_stackedWidget->setMinimumWidth(width() - m_gameBar->width());
    m_stackedWidget->setMinimumHeight(height());
    layout->addWidget(m_stackedWidget);

    DLPageGame *pageGame = new DLPageGame(this, "Minecraft");
    m_stackedWidget->addWidget(pageGame);
}

DLPageHome::~DLPageHome()
{
}

void DLPageHome::onBackgroundColorChanged(const QColor &color)
{

}
