#ifndef DLSPLASHSCREEN_H
#define DLSPLASHSCREEN_H

#include <QSplashScreen>
#include <QPainter>

class DLSplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    DLSplashScreen();

protected:
    void drawContents(QPainter *painter) override;

};

#endif // DLSPLASHSCREEN_H
