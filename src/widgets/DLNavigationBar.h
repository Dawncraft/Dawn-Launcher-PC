#ifndef DLNAVIGATIONBAR_H
#define DLNAVIGATIONBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QTabBar>
#include <QMenu>

#include "DLTitleBar.h"

class DLBrandButton : public QToolButton
{
    Q_OBJECT

public:
    explicit DLBrandButton(QWidget *parent = nullptr);
    ~DLBrandButton() = default;

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

class DLNavigationBar : public DLTitleBar
{
    Q_OBJECT

public:
    explicit DLNavigationBar(QWidget *parent = nullptr);
    ~DLNavigationBar();

signals:
    void changeStackedWidgetIndex(int index);

private slots:
    void onClicked();
    void onTabClicked(int index);

private:
    DLBrandButton *m_buttonBrand;
    DLNavTabBar *m_tabbarNavigation;
    DLUserWidget *m_widgetUser;

};

#endif // DLNAVIGATIONBAR_H
