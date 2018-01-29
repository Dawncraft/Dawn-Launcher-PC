#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QLabel>

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = 0);
    ~GamePage();
    void setGameName(QString name);

signals:

public slots:

private:
    QLabel *labelName;
};

#endif // GAMEPAGE_H
