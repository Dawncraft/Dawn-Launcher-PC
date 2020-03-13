#ifndef DLTRAYMENU_H
#define DLTRAYMENU_H

#include <QMenu>

class DLTrayMenu : public QMenu
{
    Q_OBJECT

public:
    explicit DLTrayMenu(QWidget *parent = nullptr);
    ~DLTrayMenu();

signals:
    void showMainWindow();

private slots:
    void showWindow();
    void openSettings();
    void quit();

private:
    QVector<QAction*> actionRecentGames;
    QAction *actionShow;
    QAction *actionSettings;
    QAction *actionQuit;
};

#endif // DLTRAYMENU_H
