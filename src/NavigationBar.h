#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>

class NavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationBar(QWidget *parent = 0);
    ~NavigationBar();

private slots:
    void onClicked();

private:
    QToolButton *buttonBrand;
    QPushButton *buttonHome;
    QPushButton *buttonNews;
    QPushButton *buttonBBS;
    QPushButton *buttonGames;
    QPushButton *buttonFriends;
};

#endif // NAVIGATIONBAR_H
