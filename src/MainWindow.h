#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "TitleBar.h"
#include "NavigationBar.h"
#include "TrayMenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);

private:
    TitleBar *titleBar;
    NavigationBar *navigationBar;

    QSystemTrayIcon *iconTray;
    TrayMenu *menuTray;
};

#endif // MAINWINDOW_H
