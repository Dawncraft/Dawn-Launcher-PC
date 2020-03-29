#ifndef DLTITLEBAR_H
#define DLTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>

enum DLTitleFlag
{
    NoTitle = 0,
    TitleIcon = 2,
    TitleLabel = 4,
    MinimizeButton = 8,
    MaximizeButton = 16,
    CloseButton = 32,

    FixedWindowTitleButton = MinimizeButton | CloseButton,
    NormalWindowTitleButton = FixedWindowTitleButton | MaximizeButton
};

Q_DECLARE_FLAGS(DLTitleFlags, DLTitleFlag)
Q_DECLARE_OPERATORS_FOR_FLAGS(DLTitleFlags)

class DLTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit DLTitleBar(QWidget *parent = nullptr, DLTitleFlags flag = NoTitle);
    ~DLTitleBar();

public:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void setTitleIcon(const QPixmap &icon);
    void setTitleLabel(const QString &label);

private slots:
    void onClicked();

private:
    DLTitleFlags m_titleFlag;
    QLabel *m_labelIcon;
    QLabel *m_labelTitle;
    QPushButton *m_buttonMinimize;
    QPushButton *m_buttonMaximize;
    QPushButton *m_buttonClose;
    bool m_mousePressed;
    QPoint m_pointClicked;
};

#endif // DLTITLEBAR_H
