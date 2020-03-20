#include "DLPageGame.h"

DLPageGame::DLPageGame(QWidget *parent, QString name) : QWidget(parent)
{
    gameName = name;

//    labelLogo = new QLabel(this);
//    labelLogo->setContentsMargins(0, 10, 10, 0);
//    labelLogo->setAlignment(Qt::AlignTop | Qt::AlignLeft);
//    labelLogo->setPixmap(QPixmap(":/images/Minecraft/brand.png"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    labelLogo = new QLabel(this);
    QPixmap logo = QPixmap(":/images/" + gameName + "/brand.png");
    labelLogo->setPixmap(logo);
    labelLogo->setFixedWidth(logo.width());
    labelLogo->setFixedHeight(logo.height());
    labelLogo->setContentsMargins(20, 20, 10, 10);
    labelLogo->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addWidget(labelLogo);

    layout->addStretch();

    QHBoxLayout *bar = new QHBoxLayout();
    bar->setMargin(0);
    bar->setSpacing(0);
    layout->addLayout(bar);

    bar->addSpacing(20);

    buttonStart = new QPushButton(this);
    buttonStart->setObjectName("startButton");
    buttonStart->setFixedWidth(140);
    buttonStart->setFixedHeight(60);
    buttonStart->setText("开始游戏");
    bar->addWidget(buttonStart);

    bar->addStretch();

    QProgressBar *progressBarUpdate = new QProgressBar(this);
    progressBarUpdate->setFixedWidth(480);
    progressBarUpdate->setOrientation(Qt::Horizontal);
    progressBarUpdate->setMinimum(0);
    progressBarUpdate->setMaximum(100);
    progressBarUpdate->setValue(15);
    progressBarUpdate->setFormat("正在获取更新: %p%");
    bar->addWidget(progressBarUpdate);

    bar->addSpacing(10);

    buttonUpdate = new QPushButton(this);
    buttonUpdate->setObjectName("buttonUpdate");
    buttonUpdate->setFixedWidth(40);
    buttonUpdate->setFixedHeight(40);
    buttonUpdate->setText("更新");
    bar->addWidget(buttonUpdate);

    bar->addSpacing(10);

    buttonCancel = new QPushButton(this);
    buttonCancel->setObjectName("buttonCancel");
    buttonCancel->setFixedWidth(40);
    buttonCancel->setFixedHeight(40);
    buttonCancel->setText("取消");
    bar->addWidget(buttonCancel);

    bar->addSpacing(20);
}

DLPageGame::~DLPageGame()
{
}

void DLPageGame::setGameName(QString name)
{

}
