#include "DLBlurBackgroundWidget.h"
#include <QPainter>

DLBlurBackgroundWidget::DLBlurBackgroundWidget(QWidget *parent) : QWidget(parent)
{
    auto blurEffect = new QGraphicsBlurEffect(this);
    blurEffect->setBlurRadius(5);
    setGraphicsEffect(blurEffect);
}

void DLBlurBackgroundWidget::setBackground(QWidget *widget)
{
    this->m_widgetBackground = widget;
}

void DLBlurBackgroundWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (m_widgetBackground != nullptr)
    {
        QPixmap bg = m_widgetBackground->grab(geometry());
        painter.begin(painter.device());
        painter.drawPixmap(geometry(), bg);
        painter.end();
    }
    QWidget::paintEvent(event);
}
