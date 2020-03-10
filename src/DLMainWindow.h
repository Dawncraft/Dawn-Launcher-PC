#ifndef DLMAINWINDOW_H
#define DLMAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSystemTrayIcon>
#include "widgets/TitleBar.h"
#include "widgets/NavigationBar.h"
#include "ui/HomePage.h"
#include "ui/StorePage.h"
#include "ui/NewsPage.h"
#include "ui/BBSPage.h"
#include "ui/ChatPage.h"
#include "TrayMenu.h"

class DLMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DLMainWindow(QWidget *parent = 0);
    ~DLMainWindow();

private slots:
    void setStackedWidgetIndex(int index);
    void onActivated(QSystemTrayIcon::ActivationReason reason);

private:
    TitleBar *titleBar;
    NavigationBar *navigationBar;
    QStackedWidget *stackedWidget;
    QSystemTrayIcon *iconTray;
    TrayMenu *menuTray;
};

#endif // DLMAINWINDOW_H
