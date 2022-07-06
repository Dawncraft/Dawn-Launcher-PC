#ifndef DLWINDOW_H
#define DLWINDOW_H

#include <QWidget>

#include "DLTitleBar.h"

enum DLHitPosition { CENTRAL, TOP, BOTTOM, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTTOP, RIGHTBOTTOM };

class DLWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DLWindow(QWidget *parent = nullptr, bool canResize = true, int shadowSize = 10, DLTitleFlags flag = NoTitle);
    QWidget *rootWidget() const;
    void setRootWidget(QWidget *widget);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    DLHitPosition getHitPosition(const QPoint &pos);
    DLTitleBar *m_titleBar;
    QWidget *m_rootWidget;
    bool m_canResize;
    int m_shadowSize;
    bool m_mousePressed;
    DLHitPosition m_hitPosition;
    QPointF m_oldPosition;
    QRect m_oldGeometry;

};

#endif // DLWINDOW_H
