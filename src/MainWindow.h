#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSystemTrayIcon>
#include "TitleBar.h"
#include "NavigationBar.h"
#include "HomePage.h"
#include "NewsPage.h"
#include "TrayMenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

#endif // MAINWINDOW_H
