#ifndef DLGAMEBAR_H
#define DLGAMEBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTabBar>
#include <QPushButton>

class DLGameBar : public QWidget
{
    Q_OBJECT

public:
    explicit DLGameBar(QWidget *parent = nullptr);
    ~DLGameBar();

signals:

private slots:
    void onTabClicked(QAbstractButton *button);

private:
    QTabBar *m_tabBarGame;
    QPushButton *m_buttonHide;
};

#endif // DLGAMEBAR_H
