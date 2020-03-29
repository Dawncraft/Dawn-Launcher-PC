#include "DLBlurBackgroundWidget.h"

#include <QGuiApplication>
#include <QScreen>

DLBlurBackgroundWidget::DLBlurBackgroundWidget(QWidget *parent) : QWidget(parent), m_painter(new QPainter(this))
{
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
    if (false && m_widgetBackground != nullptr)
    {
        // FIXME 自动获取控件位置
        QPixmap bg = m_widgetBackground->grab(geometry());
        m_painter->begin(m_painter->device());
        m_painter->drawPixmap(geometry(), bg);
        m_painter->end();
    }
    //QWidget::paintEvent(event);
}
