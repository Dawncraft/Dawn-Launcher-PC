#include <QFile>
#include <QElapsedTimer>
#include "DLSingleApplication.h"
#include "DLSplashScreen.h"
#include "DLMainWindow.h"

int main(int argc, char *argv[])
{
    DLSingleApplication app(argc, argv, "Dawn-Launcher");
    if (!app.isRunning())
    {
        app.initLocalServer();

        DLSplashScreen splash;
        splash.show();
        splash.showMessage(QObject::tr("正在启动中..."), Qt::AlignLeft | Qt::AlignBottom, Qt::white);

        QFile file(":/styles/dawn.qss");
        file.open(QFile::ReadOnly);
        qApp->setStyleSheet(file.readAll());

        QElapsedTimer timer;
        timer.start();
        while (timer.elapsed() < (3 * 1000))
        {
            QCoreApplication::processEvents();
        }

        DLMainWindow window;

        app.setWindow(&window);
        window.resize(1000, 570);// TODO 记忆尺寸

        splash.finish(&window);

        window.show();

        return app.exec();
    }
    return 0;
}
