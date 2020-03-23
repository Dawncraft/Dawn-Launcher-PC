#include "DLWindowFrameWidget.h"

#include <QGraphicsBlurEffect>
#include <QPainter>
#include <QMouseEvent>

#include <QDebug>

DLWindowFrameWidget::DLWindowFrameWidget(QWidget *parent, int shadowSize, bool canResize) : QWidget(parent), m_shadowSize(shadowSize), m_canResize(canResize)
{
    QGraphicsDropShadowEffect *effectShadow = new QGraphicsDropShadowEffect(this);
    effectShadow->setColor(Qt::gray);
    effectShadow->setBlurRadius(shadowSize);
    setGraphicsEffect(effectShadow);

    if (canResize)
    {
        setMouseTracking(true);
    }
}

void DLWindowFrameWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = true;
        m_oldPosition = event->globalPos();
        m_oldGeometry = parentWidget()->geometry();
        m_hitPosition = getHitPosition(event->pos());
    }
}

void DLWindowFrameWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed)
    {
        if (m_hitPosition == CENTRAL) return;

        QPoint pos = event->globalPos();
        int offsetX = pos.x() - m_oldPosition.x();
        int offsetY = pos.y() - m_oldPosition.y();

        QRect newGeometry = m_oldGeometry;
        switch (m_hitPosition)
        {
        case TOP:
            newGeometry.adjust(0, offsetY, 0, 0);
            break;
        case BOTTOM:
            newGeometry.adjust(0, 0, 0, offsetY);
            break;
        case LEFT:
            newGeometry.adjust(offsetX, 0, 0, 0);
            break;
        case RIGHT:
            newGeometry.adjust(0, 0, offsetX, 0);
            break;
        case LEFTTOP:
            newGeometry.adjust(offsetX, offsetY, 0, 0);
            break;
        case LEFTBOTTOM:
            newGeometry.adjust(offsetX, 0, 0, offsetY);
            break;
        case RIGHTTOP:
            newGeometry.adjust(0, offsetY, offsetX, 0);
            break;
        case RIGHTBOTTOM:
            newGeometry.adjust(0, 0, offsetX, offsetY);
            break;
        case CENTRAL:
        default:
            break;
       }
       parentWidget()->setGeometry(newGeometry);
    }
    else
    {
        qDebug() << getHitPosition(event->pos());

        switch (getHitPosition(event->pos()))
        {
        case TOP:
            setCursor(QCursor(Qt::SizeVerCursor));
            break;
        case BOTTOM:
            setCursor(QCursor(Qt::SizeVerCursor));
            break;
        case LEFT:
            setCursor(QCursor(Qt::SizeHorCursor));
            break;
        case RIGHT:
            setCursor(QCursor(Qt::SizeHorCursor));
            break;
        case LEFTTOP:
            setCursor(QCursor(Qt::SizeFDiagCursor));
            break;
        case LEFTBOTTOM:
            setCursor(QCursor(Qt::SizeBDiagCursor));
            break;
        case RIGHTTOP:
            setCursor(QCursor(Qt::SizeBDiagCursor));
            break;
        case RIGHTBOTTOM:
            setCursor(QCursor(Qt::SizeFDiagCursor));
            break;
        case CENTRAL:
        default:
            setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        event->accept();
    }
}

void DLWindowFrameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = false;
        releaseMouse();
    }
}

void DLWindowFrameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QWidget::paintEvent(event);
}

/* From WizNote. License: GPLv3. Also see: https://github.com/WizTeam/WizQTClient */
DLHitPosition DLWindowFrameWidget::getHitPosition(const QPoint &pos)
{
    if (!m_canResize) return CENTRAL;

    if (pos.x() < m_shadowSize)
    {
        if (pos.y() < m_shadowSize)
        {
            return LEFTTOP;
        }
        else if (pos.y() >= height() - m_shadowSize)
        {
            return LEFTBOTTOM;
        }
        else
        {
            return LEFT;
        }
    }
    else if (pos.x() > width() - m_shadowSize)
    {
        if (pos.y() < m_shadowSize)
        {
            return RIGHTTOP;
        }
        else if (pos.y() >= height() - m_shadowSize)
        {
            return RIGHTBOTTOM;
        }
        else
        {
            return RIGHT;
        }
    }
    else if (pos.y() < m_shadowSize)
    {
        return TOP;
    }
    else if (pos.y() > height() - m_shadowSize)
    {
        return BOTTOM;
    }
    else
    {
        return CENTRAL;
    }
}
