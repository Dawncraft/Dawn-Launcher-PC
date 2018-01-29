#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "SwitchBar.h"
#include "GamePage.h"

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

signals:

public slots:

private:
    SwitchBar *switchBar;
    QStackedWidget *stackedWidget;
};

#endif // HOMEPAGE_H
