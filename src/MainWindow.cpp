#include <QLabel>
#include <QFile>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1000, 540);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setWindowIcon(QIcon(":/logo"));
    setWindowTitle("曙光游戏平台");

    titleBar = new TitleBar(this);
    installEventFilter(titleBar);


}

MainWindow::~MainWindow()
{
    delete this;
}
