#include "NewsPage.h"

NewsPage::NewsPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    QLabel *label = new QLabel(this);
    label->setText("这是新闻!!!");
    layout->addWidget(label);

    layout->addStretch(1);
}

NewsPage::~NewsPage()
{

}
