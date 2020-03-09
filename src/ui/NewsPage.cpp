#include "NewsPage.h"

NewsPage::NewsPage(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    QLabel *label = new QLabel(this);
    label->setText("这是新闻!!!");
}

NewsPage::~NewsPage()
{

}
