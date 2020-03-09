#include <QSplashScreen>
#include <QElapsedTimer>
#include "DawnSingleApplication.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    DawnSingleApplication app(argc, argv, "Dawn-Launcher");
    if (!app.isRunning())
    {
        app.initLocalServer();

        QFile file(":/styles/dawn.qss");
        file.open(QFile::ReadOnly);
        qApp->setStyleSheet(file.readAll());

        QSplashScreen splash(QPixmap(":/images/splash.png"));
        splash.setDisabled(true);
        splash.show();
        splash.showMessage(QObject::tr("正在启动中..."), Qt::AlignLeft|Qt::AlignBottom, Qt::green);

        QElapsedTimer timer;
        timer.start();
        while (timer.elapsed() < (1 * 1000))
        {
            QCoreApplication::processEvents();
        }

        MainWindow window;
        app.setWindow(&window);

        splash.finish(&window);

        window.show();

        return app.exec();
    }
    return 0;
}
