#ifndef DLNAVIGATIONBAR_H
#define DLNAVIGATIONBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QProgressBar>
#include <QTabBar>
#include <QMenu>

#include "DLBlurBackgroundWidget.h"
#include "DLTitleBar.h"

class DLBrandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DLBrandWidget(QWidget *parent = nullptr);
    ~DLBrandWidget() = default;

private:
    QToolButton *m_buttonBrand;
    QProgressBar *m_progressBar;

};

class DLNavTabBar : public QTabBar
{
    Q_OBJECT

public:
    explicit DLNavTabBar(QWidget *parent = nullptr);
    ~DLNavTabBar() = default;

protected:
    QSize tabSizeHint(int index) const override;

};

class DLUserWidget : public QFrame
{
    Q_OBJECT

public:
    explicit DLUserWidget(QWidget *parent = nullptr);
    ~DLUserWidget() = default;

};

class DLNavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit DLNavigationBar(QWidget *parent = nullptr);
    ~DLNavigationBar();

public:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void changeStackedWidgetIndex(int index);

private slots:
    void onTabClicked(int index);

private:
    DLTitleBar *m_titleBar;
    DLBrandWidget *m_widgetBrand;
    DLNavTabBar *m_tabBarNav;
    DLUserWidget *m_widgetUser;

};

#endif // DLNAVIGATIONBAR_H
