#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QMenu>

class TrayMenu : public QMenu
{
    Q_OBJECT

public:
    explicit TrayMenu(QWidget *parent = 0);
    ~TrayMenu();

signals:

private:
    QAction *actionShow;
    QAction *actionSetting;
    QAction *actionQuit;
};

#endif // TRAYMENU_H
