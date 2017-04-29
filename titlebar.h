#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

class QLabel;
class QPushButton;

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void onClicked();

private:
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pCloseButton;
};

#endif // TITLEBAR_H
