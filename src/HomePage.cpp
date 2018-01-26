#include "HomePage.h"

HomePage::HomePage(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    QLabel *label = new QLabel(this);
    label->setText("这是主页!!!");
}

HomePage::~HomePage()
{

}
