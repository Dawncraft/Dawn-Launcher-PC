#ifndef DLPAGEHOME_H
#define DLPAGEHOME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "../widgets/DLGameBar.h"
#include "DLPageGame.h"

class DLPageHome : public QWidget
{
    Q_OBJECT

public:
    explicit DLPageHome(QWidget *parent = nullptr);
    ~DLPageHome();

signals:

private slots:


private:
    DLGameBar *m_gameBar;
    QStackedWidget *m_stackedWidget;
};

#endif // DLPAGEHOME_H
