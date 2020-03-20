#ifndef DLSINGLEAPPLICATION_H
#define DLSINGLEAPPLICATION_H

#include <QApplication>
#include <QWidget>
#include <QLocalServer>
#include <QSharedMemory>

#include "DLMainWindow.h"
#include "DLConfiguration.h"

class DLSingleApplication : public QApplication
{
    Q_OBJECT

public:
    DLSingleApplication(int &argc, char *argv[], const QString key);
    void initLocalServer();

    bool isRunning();
    DLConfig &getConfig();
    void setWindow(DLMainWindow *window);

private slots:
    void receiveConnection();

private:
    QString m_uniqueKey;
    bool m_isRunning;
    DLConfig m_configer;
    DLMainWindow *m_mainWindow;
    QSharedMemory m_sharedMemory;
    QLocalServer *m_localServer;

};

#endif // DLSINGLEAPPLICATION_H
