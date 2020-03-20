#ifndef DLBLURBACKGROUNDWIDGET_H
#define DLBLURBACKGROUNDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsBlurEffect>

class DLBlurBackgroundWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DLBlurBackgroundWidget(QWidget *parent = nullptr);

public:
    void setBackground(QWidget *widget);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPainter *m_painter;
    QWidget *m_widgetBackground;

};

#endif // DLBLURBACKGROUNDWIDGET_H
