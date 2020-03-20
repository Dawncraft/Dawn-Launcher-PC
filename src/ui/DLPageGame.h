#ifndef DLPAGEGAME_H
#define DLPAGEGAME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

class DLPageGame : public QWidget
{
    Q_OBJECT

public:
    explicit DLPageGame(QWidget *parent = nullptr, QString name = "");
    ~DLPageGame();
    void setGameName(QString name);

signals:

private slots:

private:
    QString gameName;
    QLabel *labelLogo;
    QWidget *widgetCarousel;
    QPushButton *buttonStart;
    QLabel *labelPreUpdate;
    QProgressBar *progressBarUpdate;
    QPushButton *buttonUpdate;
    QPushButton *buttonCancel;
};

#endif // DLPAGEGAME_H
