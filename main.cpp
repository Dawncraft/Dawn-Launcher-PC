#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QSplashScreen splash(QPixmap(":/images/splash.png"));
    splash.setDisabled(true);
    splash.show();
    splash.showMessage(QObject::tr("正在启动中..."), Qt::AlignLeft|Qt::AlignBottom, Qt::green);
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < (6 * 1000))
    {
        QCoreApplication::processEvents();
    }
    splash.finish(&window);


    window.show();

    return app.exec();
}
