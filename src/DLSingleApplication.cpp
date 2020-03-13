#include "DLSingleApplication.h"
#include <QLocalSocket>

#define TIMEOUT (1000)

DLSingleApplication::DLSingleApplication(int &argc, char *argv[], const QString key) : QApplication(argc, argv), m_uniqueKey(key), m_isRunning(false), m_configer("settings.ini"), m_mainWindow(nullptr)
{
    QLocalSocket localSocket;
    localSocket.connectToServer(m_uniqueKey);
    if (localSocket.waitForConnected(TIMEOUT))
    {
        m_isRunning = true;
        qInfo() << "Already started!";
        localSocket.disconnectFromServer();
    }
}

bool DLSingleApplication::isRunning()
{
    return m_isRunning;
}

DLConfig& DLSingleApplication::getConfig()
{
    return m_configer;
}

void DLSingleApplication::initLocalServer()
{
    m_localServer = new QLocalServer(this);
    connect(m_localServer, SIGNAL(newConnection()), this, SLOT(receiveConnection()));
    if (!m_localServer->listen(m_uniqueKey))
    {
        if (m_localServer->serverError() == QAbstractSocket::AddressInUseError)
        {
            QLocalServer::removeServer(m_uniqueKey);
            m_localServer->listen(m_uniqueKey);
        }
    }
    qInfo() << "Local server init";
}

void DLSingleApplication::setWindow(DLMainWindow *window)
{
    m_mainWindow = window;
}

void DLSingleApplication::receiveConnection()
{
    QLocalSocket *localSocket = m_localServer->nextPendingConnection();
    if (localSocket)
    {
        if (!localSocket->waitForReadyRead(TIMEOUT))
        {
            qCritical() << localSocket->errorString();
            // FIXME ???
            // return;
        }
        if (m_mainWindow)
        {
            m_mainWindow->onShowWindow();
        }
        localSocket->disconnectFromServer();
    }
}
