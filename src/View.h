#ifndef _VIEW_H_
#define _VIEW_H_

#include <QGraphicsView>
#include <QDebug>
#include <QWheelEvent>
#include <QScrollBar>

class View : public QGraphicsView
{
    Q_OBJECT

public:
    View(QWidget * map);
    ~View();
    void setRotator(qreal* rotate){rotator = rotate;}
    void zoomPlus(double factor = 1.0);
    void zoomMinus(double factor = 1.0);
protected:
    void wheelEvent(QWheelEvent *event);
public:
    void resetScale();
    qreal* rotator;
};

#endif // _VIEW_H_
