#ifndef DLPAGEHOME_H
#define DLPAGEHOME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "../widgets/SwitchBar.h"
#include "GamePage.h"

class DLPageHome : public QWidget
{
    Q_OBJECT

public:
    explicit DLPageHome(QWidget *parent = nullptr);
    ~DLPageHome();

signals:

public slots:

private:
    SwitchBar *switchBar;
    QStackedWidget *stackedWidget;
};

#endif // DLPAGEHOME_H
