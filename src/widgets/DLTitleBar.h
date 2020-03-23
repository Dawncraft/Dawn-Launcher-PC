#ifndef DLTITLEBAR_H
#define DLTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>

class DLTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit DLTitleBar(QWidget *parent = nullptr);
    ~DLTitleBar();

public:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void onClicked();

private:
    bool m_mousePressed;
    QPoint m_pointClicked;
    QLabel *m_labelIcon;
    QLabel *m_labelTitle;
    QPushButton *m_buttonMinimize;
    QPushButton *m_buttonMaximize;
    QPushButton *m_buttonClose;
};

#endif // DLTITLEBAR_H
