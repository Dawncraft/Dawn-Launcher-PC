#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QSplashScreen splash(QPixmap(":/images/splash.png"));
    splash.setDisabled(true);
    splash.show();
    splash.showMessage(QObject::tr("正在启动中..."), Qt::AlignLeft|Qt::AlignBottom, Qt::green);

    QFile file(":/styles/dawn.qss");
    file.open(QFile::ReadOnly);
    qApp->setStyleSheet(file.readAll());

    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < (1 * 1000))
    {
        QCoreApplication::processEvents();
    }

    splash.finish(&window);

    window.show();

    return app.exec();
}
