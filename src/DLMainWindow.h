#ifndef DLMAINWINDOW_H
#define DLMAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QSystemTrayIcon>

#include "widgets/DLTitleBar.h"
#include "widgets/DLNavigationBar.h"
#include "widgets/DLTrayMenu.h"
#include "ui/DLPageHome.h"
#include "ui/StorePage.h"
#include "ui/NewsPage.h"
#include "ui/BBSPage.h"
#include "ui/ChatPage.h"

class DLMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DLMainWindow(QWidget *parent = 0);
    ~DLMainWindow();

public slots:
    void onShowWindow();

private slots:
    void onStackedWidgetIndexChanged(int index);
    void onTrayActivated(QSystemTrayIcon::ActivationReason reason);

private:
    DLTitleBar *titleBar;
    DLNavigationBar *navigationBar;
    QStackedWidget *stackedWidget;
    QSystemTrayIcon *trayIcon;
    DLTrayMenu *trayMenu;
};

#endif // DLMAINWINDOW_H
