#ifndef DAWNSINGLEAPPLICATION_H
#define DAWNSINGLEAPPLICATION_H

#include <QApplication>
#include <QWidget>
#include <QLocalServer>
#include <QSharedMemory>

class DawnSingleApplication : public QApplication
{
    Q_OBJECT

public:
    DawnSingleApplication(int &argc, char **argv, const QString key);
    bool isRunning();
    void initLocalServer();
    void setWindow(QWidget *window);

private slots:
    void receiveConnection();

private:
    QString _uniqueKey;
    bool _isRunning;
    QWidget *_window;
    QSharedMemory _sharedMemory;
    QLocalServer *_localServer;

};

#endif // DAWNSINGLEAPPLICATION_H
