#include "DLBlurBackgroundWidget.h"

#include <QGuiApplication>
#include <QScreen>

DLBlurBackgroundWidget::DLBlurBackgroundWidget(QWidget *parent) : QWidget(parent)
{
    m_painter = new QPainter(this);

    QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect(this);
    blurEffect->setBlurRadius(4);
    setGraphicsEffect(blurEffect);
}

void DLBlurBackgroundWidget::setBackground(QWidget *widget)
{
    m_widgetBackground = widget;
}

void DLBlurBackgroundWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if (m_widgetBackground != nullptr)
    {
        QRect rect = QRect(pos(), size());
        QPixmap bg = m_widgetBackground->grab(rect);
        m_painter->begin(m_painter->device());
        m_painter->drawPixmap(rect, bg);
        m_painter->end();
    }
}
