#include "BBSPage.h"

BBSPage::BBSPage(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->width());
    setFixedHeight(parent->height());

    /*
    QWebView view;
    view.load(QUrl("http://www.baidu.com"));
    view.show();
    */
}

BBSPage::~BBSPage()
{

}
