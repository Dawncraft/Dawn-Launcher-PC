#include "DLSplashScreen.h"

#include <QCoreApplication>

DLSplashScreen::DLSplashScreen() : QSplashScreen(QPixmap(":/images/splash.png"))
{
    setDisabled(true);
}

void DLSplashScreen::drawContents(QPainter *painter)
{
    QSplashScreen::drawContents(painter);
    painter->setPen(Qt::white);

    QFont font1;
    font1.setFamily("Arial");
    font1.setPointSize(32);
    painter->setFont(font1);
    QRect rect(0, 200, 480, 40);
    painter->drawText(rect, Qt::AlignHCenter, QCoreApplication::applicationName());

    QFont font2;
    font2.setFamily("Arial");
    font2.setPointSize(18);
    painter->setFont(font2);
    QRect rect2(0, 250, 480, 25);
    painter->drawText(rect2, Qt::AlignHCenter, "Version " + QCoreApplication::applicationVersion());
}
