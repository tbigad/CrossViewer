#ifndef _VIEW_H_
#define _VIEW_H_

#include <QGraphicsView>
#include <QDebug>

class View : public QGraphicsView
{
    Q_OBJECT

public:
    View(QWidget * map);
    ~View();
    void setRotator(qreal* rotate){rotator = rotate;}
public:
    resetScale();
    qreal* rotator;
};

#endif // _VIEW_H_
