#ifndef NEWSPAGE_H
#define NEWSPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class NewsPage : public QWidget
{
    Q_OBJECT

public:
    explicit NewsPage(QWidget *parent = 0);
    ~NewsPage();

signals:

public slots:
};

#endif // NEWSPAGE_H
