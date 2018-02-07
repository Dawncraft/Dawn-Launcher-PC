#include "GamePage.h"

GamePage::GamePage(QWidget *parent, QString name) : QWidget(parent)
{
    gameName = name;

    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    QLabel *labelBrand = new QLabel(this);
    QPixmap brand = QPixmap(":/images/" + gameName + "/brand.png");
    labelBrand->setPixmap(brand);
    labelBrand->setFixedWidth(brand.width());
    labelBrand->setFixedHeight(brand.height());
    labelBrand->setContentsMargins(40, 40, 40, 40);
    labelBrand->setAlignment(Qt::AlignVCenter | Qt::AlignTop);
    layout->addWidget(labelBrand);

    // Add silder and others
    layout->addSpacing(150);

    QHBoxLayout *bar = new QHBoxLayout();
    bar->setMargin(0);
    bar->setSpacing(0);
    layout->addLayout(bar);

    bar->addSpacing(20);

    QPushButton *start = new QPushButton(this);
    start->setObjectName("startButton");
    start->setFixedWidth(140);
    start->setFixedHeight(60);
    start->setText("开始游戏");
    bar->addWidget(start);

    bar->addSpacing(20);

    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setFixedWidth(480);
    progressBar->setOrientation(Qt::Horizontal);
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(5);
    progressBar->setFormat("正在获取更新: %p%");
    bar->addWidget(progressBar);

    bar->addSpacing(20);

    QPushButton *setting = new QPushButton(this);
    setting->setObjectName("settingButton");
    setting->setFixedWidth(40);
    setting->setFixedHeight(20);
    setting->setText("设置");
    bar->addWidget(setting);
}

GamePage::~GamePage()
{

}

void GamePage::setGameName(QString name)
{

}
