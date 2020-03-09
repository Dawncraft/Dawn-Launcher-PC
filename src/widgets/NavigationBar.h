#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QToolButton>
#include <QPushButton>
#include <QMenu>
#include <QLabel>

class NavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationBar(QWidget *parent = 0);
    ~NavigationBar();

signals:
    void changeStackedWidgetIndex(int index);

private slots:
    void onClicked();
    void onTabClicked(QAbstractButton *button);

private:
    QToolButton *buttonBrand;
    QButtonGroup *buttonGroup;
};

#endif // NAVIGATIONBAR_H
