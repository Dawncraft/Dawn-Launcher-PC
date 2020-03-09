#ifndef SWITCHBAR_H
#define SWITCHBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

class SwitchBar : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchBar(QWidget *parent = 0, QString games[] = {});
    ~SwitchBar();

signals:

private slots:
    void onTabClicked(QAbstractButton *button);

private:
    QButtonGroup *buttonGroup;
};

#endif // SWITCHBAR_H
