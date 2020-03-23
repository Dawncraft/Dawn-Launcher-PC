#include "DLTitleBar.h"

DLTitleBar::DLTitleBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("titleBar");
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    setMinimumWidth(parent->width());
    setFixedHeight(20);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    layout->addSpacing(10);

    if (!parent->windowIcon().isNull())
    {
        m_labelIcon = new QLabel(this);
        m_labelIcon->setObjectName("labelIcon");
        m_labelIcon->setFixedSize(16, 16);
        m_labelIcon->setScaledContents(true);
        m_labelIcon->setPixmap(parent->windowIcon().pixmap(m_labelIcon->size()));
        layout->addWidget(m_labelIcon, 0, Qt::AlignLeft | Qt::AlignVCenter);
        layout->addSpacing(5);
    }

    if (!parent->windowTitle().isNull())
    {
        m_labelTitle = new QLabel(this);
        m_labelTitle->setObjectName("labelTitle");
        m_labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        m_labelTitle->setText(parent->windowTitle());
        layout->addWidget(m_labelTitle, 0, Qt::AlignLeft | Qt::AlignVCenter);
        layout->addSpacing(5);
    }

    layout->addStretch();

    if (parent->windowFlags() & Qt::WindowMinimizeButtonHint)
    {
        m_buttonMinimize = new QPushButton(this);
        m_buttonMinimize->setProperty("type", "min");
        m_buttonMinimize->setFocusPolicy(Qt::NoFocus);
        m_buttonMinimize->setToolTip("Minimize");
        connect(m_buttonMinimize, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layout->addWidget(m_buttonMinimize, 0, Qt::AlignRight | Qt::AlignTop);
    }

    if (parent->windowFlags() & Qt::WindowMaximizeButtonHint)
    {
        m_buttonMaximize = new QPushButton(this);
        m_buttonMaximize->setProperty("type", "max");
        m_buttonMaximize->setFocusPolicy(Qt::NoFocus);
        m_buttonMaximize->setToolTip("Maximize");
        connect(m_buttonMaximize, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layout->addWidget(m_buttonMaximize, 0, Qt::AlignRight | Qt::AlignTop);
    }

    if (parent->windowFlags() & Qt::WindowCloseButtonHint)
    {
        m_buttonClose = new QPushButton(this);
        m_buttonClose->setProperty("type", "close");
        m_buttonClose->setFocusPolicy(Qt::NoFocus);
        m_buttonClose->setToolTip("Close");
        connect(m_buttonClose, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layout->addWidget(m_buttonClose, 0, Qt::AlignRight | Qt::AlignTop);
    }
}

DLTitleBar::~DLTitleBar()
{
}

bool DLTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    QWidget *widget = qobject_cast<QWidget*>(obj);
    if (widget)
    {
        switch (event->type())
        {
            case QEvent::WindowIconChange:
            {
                m_labelIcon->setPixmap(widget->windowIcon().pixmap(m_labelIcon->size()));
                return true;
            }
            case QEvent::WindowTitleChange:
            {
                m_labelTitle->setText(widget->windowTitle());
                return true;
            }
            case QEvent::WindowStateChange:
            case QEvent::Resize:
            {
                // qDebug() << QString(window()->isMaximized());
                // FIXME 还原按钮图标不改变
                m_buttonMaximize->setProperty("type", window()->isMaximized() ? "restore" : "max");
                return true;
            }
            default: break;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void DLTitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = true;
        m_pointClicked = event->globalPos();
    }
}

void DLTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_buttonMaximize->click();
}

void DLTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed)
    {
        window()->move(window()->pos() + event->globalPos() - m_pointClicked);
        m_pointClicked = event->globalPos();
    }
}

void DLTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = false;
    }
}

void DLTitleBar::onClicked()
{
    QWidget *window = this->window();
    if (window->isTopLevel())
    {
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (button == m_buttonMinimize)
        {
            window->showMinimized();
        }
        else if (button == m_buttonMaximize)
        {
            window->isMaximized() ? window->showNormal() : window->showMaximized();
        }
        else if (button == m_buttonClose)
        {
            window->close();
        }
    }
}
