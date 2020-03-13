#ifndef DLTITLEBAR_H
#define DLTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>

class DLTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit DLTitleBar(bool isIndependent = true, QWidget *parent = nullptr);
    ~DLTitleBar();

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    QHBoxLayout *m_layoutTitlebar;

private slots:
    void onClicked();

private:
    QLabel *m_labelIcon;
    QLabel *m_labelTitle;
    QPushButton *m_buttonMinimize;
    QPushButton *m_buttonMaximize;
    QPushButton *m_buttonClose;
};

#endif // DLTITLEBAR_H
