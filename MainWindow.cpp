#include <QLabel>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    /*TitleBar *pTitleBar = new TitleBar(this);
    this->installEventFilter(pTitleBar);

    ui->horizontalLayout->addWidget(pTitleBar);*/
    ui->horizontalLayout->addStretch();
    ui->horizontalLayout->setSpacing(0);
    ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);

    ui->statusBar->showMessage("Welcome to use Dawn Launcher!", 6000);
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("Done");
    ui->statusBar->addPermanentWidget(permanent);

    QFile file(":/styles/dawn.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = file.readAll();
    qApp->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}
