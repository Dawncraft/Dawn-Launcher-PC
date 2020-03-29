#ifndef DLMAINWINDOW_H
#define DLMAINWINDOW_H

#include <QStackedLayout>
#include <QStackedWidget>
#include <QSystemTrayIcon>

#include "widgets/DLWindow.h"
#include "widgets/DLNavigationBar.h"
#include "widgets/DLBlurBackgroundWidget.h"
#include "widgets/DLTrayMenu.h"
#include "ui/DLPageHome.h"
#include "ui/StorePage.h"
#include "ui/NewsPage.h"
#include "ui/BBSPage.h"
#include "ui/ChatPage.h"

class DLMainWindow : public DLWindow
{
    Q_OBJECT

public:
    explicit DLMainWindow(QWidget *parent = 0);
    ~DLMainWindow();

public slots:
    void onShowWindow();

private slots:
    void onPageIndexChanged(int index);
    void onTrayActivated(QSystemTrayIcon::ActivationReason reason);

private:
    DLNavigationBar *m_navigationBar;
    DLBlurBackgroundWidget *m_backgroundWidget;
    QStackedWidget *m_stackedWidget;
    QSystemTrayIcon *m_trayIcon;
    DLTrayMenu *m_trayMenu;
};

#endif // DLMAINWINDOW_H
