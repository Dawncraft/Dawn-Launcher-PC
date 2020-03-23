#ifndef DLWINDOWFRAMEWIDGET_H
#define DLWINDOWFRAMEWIDGET_H

#include <QWidget>

enum DLHitPosition { CENTRAL, TOP, BOTTOM, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTTOP, RIGHTBOTTOM };

class DLWindowFrameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DLWindowFrameWidget(QWidget *parent = nullptr, int shadowSize = 10, bool canResize = true);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    DLHitPosition getHitPosition(const QPoint &pos);
    int m_shadowSize;
    bool m_canResize;
    bool m_mousePressed;
    DLHitPosition m_hitPosition;
    QPoint m_oldPosition;
    QRect m_oldGeometry;
};

#endif // DLWINDOWFRAMEWIDGET_H
