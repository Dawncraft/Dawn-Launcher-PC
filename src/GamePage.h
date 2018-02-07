#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = 0, QString name = "");
    ~GamePage();
    void setGameName(QString name);

signals:

public slots:

private:
    QString gameName;
};

#endif // GAMEPAGE_H
