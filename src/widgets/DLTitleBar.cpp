#include "DLTitleBar.h"

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

DLTitleBar::DLTitleBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("titlebar");
    setFixedHeight(30);

    m_layout = new QVBoxLayout(this);
    m_layout->setMargin(0);
    m_layout->setSpacing(0);

    QWidget *widgetTitleBar = new QWidget(this);
    QHBoxLayout* layoutTitleBar = new QHBoxLayout(widgetTitleBar);
    layoutTitleBar->setMargin(0);
    layoutTitleBar->setSpacing(0);
    widgetTitleBar->setLayout(layoutTitleBar);
    m_layout->addWidget(widgetTitleBar);

    layoutTitleBar->addSpacing(10);

    if (!parent->windowIcon().isNull())
    {
        m_labelIcon = new QLabel(this);
        m_labelIcon->setObjectName("labelIcon");
        m_labelIcon->setFixedSize(20, 20);
        m_labelIcon->setScaledContents(true);
        m_labelIcon->setPixmap(parent->windowIcon().pixmap(m_labelIcon->size()));
        layoutTitleBar->addWidget(m_labelIcon, 0, Qt::AlignLeft);
        layoutTitleBar->addSpacing(5);
    }

    if (!parent->windowTitle().isNull())
    {
        m_labelTitle = new QLabel(this);
        m_labelTitle->setObjectName("labelTitle");
        m_labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        m_labelTitle->setText(parent->windowTitle());
        layoutTitleBar->addWidget(m_labelTitle, 0, Qt::AlignLeft);
        layoutTitleBar->addSpacing(5);
    }

    layoutTitleBar->addStretch();

    if (parent->windowFlags() & Qt::WindowMinimizeButtonHint)
    {
        m_buttonMinimize = new QPushButton(this);
        m_buttonMinimize->setObjectName("buttonMinimize");
        m_buttonMinimize->setFocusPolicy(Qt::NoFocus);
        m_buttonMinimize->setToolTip("Minimize");
        connect(m_buttonMinimize, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layoutTitleBar->addWidget(m_buttonMinimize, 0, Qt::AlignRight | Qt::AlignTop);
    }

    if (parent->windowFlags() & Qt::WindowMaximizeButtonHint)
    {
        m_buttonMaximize = new QPushButton(this);
        m_buttonMaximize->setObjectName("buttonMaximize");
        m_buttonMaximize->setFocusPolicy(Qt::NoFocus);
        m_buttonMaximize->setToolTip("Maximize");
        connect(m_buttonMaximize, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layoutTitleBar->addWidget(m_buttonMaximize, 0, Qt::AlignRight | Qt::AlignTop);
    }

    if (parent->windowFlags() & Qt::WindowCloseButtonHint)
    {
        m_buttonClose = new QPushButton(this);
        m_buttonClose->setObjectName("buttonClose");
        m_buttonClose->setFocusPolicy(Qt::NoFocus);
        m_buttonClose->setToolTip("Close");
        connect(m_buttonClose, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        layoutTitleBar->addWidget(m_buttonClose, 0, Qt::AlignRight | Qt::AlignTop);
    }
}

DLTitleBar::~DLTitleBar()
{
}

bool DLTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    QWidget *widget = qobject_cast<QWidget *>(obj);
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
                return true;
            default:
                return QWidget::eventFilter(obj, event);
        }
    }
    return QWidget::eventFilter(obj, event);
}

void DLTitleBar::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture())
    {
        QWidget *window = this->window();
        if (window->isTopLevel())
        {
           SendMessage(HWND(window->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
    event->ignore();
#else
#endif
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
        else if (button == m_buttonClose)
        {
            window->close();
        }
    }
}
