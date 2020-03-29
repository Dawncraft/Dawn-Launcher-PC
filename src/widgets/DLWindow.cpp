#include "DLWindow.h"

#include <QGraphicsBlurEffect>
#include <QPainter>

#define DRAG_SIZE 10

DLWindow::DLWindow(QWidget *parent, bool canResize, int shadowSize, DLTitleFlags flag) : QWidget(parent), m_canResize(canResize), m_shadowSize(shadowSize)
{
    setContentsMargins(DRAG_SIZE, DRAG_SIZE, DRAG_SIZE, DRAG_SIZE);

    if (canResize) setMouseTracking(true);

    if (shadowSize > 0)
    {
        QGraphicsDropShadowEffect *effectShadow = new QGraphicsDropShadowEffect(this);
        effectShadow->setColor(Qt::gray);
        effectShadow->setBlurRadius(shadowSize);
        setGraphicsEffect(effectShadow);
    }

    setRootWidget(this);
    if (flag != NoTitle)
    {
        QVBoxLayout *rootLayout = new QVBoxLayout();
        rootLayout->setMargin(0);
        rootLayout->setSpacing(0);

        m_titleBar = new DLTitleBar(this, flag);
        installEventFilter(m_titleBar);
        rootLayout->addWidget(m_titleBar);

        QWidget *rootWidget = new QWidget(this);
        rootLayout->addWidget(rootWidget);

        setRootWidget(rootWidget);
    }
}

QWidget *DLWindow::rootWidget() const
{
    return m_rootWidget;
}

void DLWindow::setRootWidget(QWidget *widget)
{
    m_rootWidget = widget;
}

void DLWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = true;
        m_oldPosition = event->globalPos();
        m_oldGeometry = geometry();
        m_hitPosition = getHitPosition(event->pos());
    }
}

void DLWindow::mouseMoveEvent(QMouseEvent *event)
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
       setGeometry(newGeometry);
    }
    else
    {
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

void DLWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = false;
        releaseMouse();
    }
}

void DLWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QWidget::paintEvent(event);
}

/* From WizNote. License: GPLv3. Also see: https://github.com/WizTeam/WizQTClient */
DLHitPosition DLWindow::getHitPosition(const QPoint &pos)
{
    if (!m_canResize) return CENTRAL;

    if (pos.x() < DRAG_SIZE)
    {
        if (pos.y() < DRAG_SIZE)
        {
            return LEFTTOP;
        }
        else if (pos.y() >= height() - DRAG_SIZE)
        {
            return LEFTBOTTOM;
        }
        else
        {
            return LEFT;
        }
    }
    else if (pos.x() > width() - DRAG_SIZE)
    {
        if (pos.y() < DRAG_SIZE)
        {
            return RIGHTTOP;
        }
        else if (pos.y() >= height() - DRAG_SIZE)
        {
            return RIGHTBOTTOM;
        }
        else
        {
            return RIGHT;
        }
    }
    else if (pos.y() < DRAG_SIZE)
    {
        return TOP;
    }
    else if (pos.y() > height() - DRAG_SIZE)
    {
        return BOTTOM;
    }
    else
    {
        return CENTRAL;
    }
}
