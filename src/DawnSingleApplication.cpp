#include "DawnSingleApplication.h"
#include <QLocalSocket>

#define TIMEOUT (1000)

DawnSingleApplication::DawnSingleApplication(int &argc, char **argv, const QString key) : QApplication(argc, argv), _uniqueKey(key), _isRunning(false), _window(nullptr)
{
    QLocalSocket localSocket;
    localSocket.connectToServer(_uniqueKey);
    if (localSocket.waitForConnected(TIMEOUT))
    {
        localSocket.disconnectFromServer();
        qInfo() << "Already started!";
        _isRunning = true;
    }
}

bool DawnSingleApplication::isRunning()
{
    return _isRunning;
}

void DawnSingleApplication::initLocalServer()
{
    _localServer = new QLocalServer(this);
    connect(_localServer, SIGNAL(newConnection()), this, SLOT(receiveConnection()));
    if (!_localServer->listen(_uniqueKey))
    {
        if (_localServer->serverError() == QAbstractSocket::AddressInUseError)
        {
            QLocalServer::removeServer(_uniqueKey);
            _localServer->listen(_uniqueKey);
        }
    }
    qInfo() << "Local server init";
}

void DawnSingleApplication::setWindow(QWidget *window)
{
    _window = window;
}

void DawnSingleApplication::receiveConnection()
{
    QLocalSocket *localSocket = _localServer->nextPendingConnection();
    if (localSocket)
    {
        if (!localSocket->waitForReadyRead(TIMEOUT))
        {
            qCritical() << localSocket->errorString();
            // FIXME ???
            // return;
        }
        qDebug() << _window;
        if (_window)
        {
            _window->showNormal();
            _window->raise();
            _window->activateWindow();
        }
        localSocket->disconnectFromServer();
    }
}
