#include "View.h"

View::View(QWidget * map) : QGraphicsView(map)
{
    setContentsMargins(1,1,1,1);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setViewportUpdateMode (QGraphicsView::FullViewportUpdate);

    setAcceptDrops(true);
}

View::~View()
{
}

void View::wheelEvent(QWheelEvent *event)
{
    if (event->delta() == 0)
        return;

    QPointF pointBeforeScale( QGraphicsView::mapToScene( event->pos() ) );
    QPointF screenCenter = mapToScene( rect().center() );
        if(event->delta() > 0){
            zoomPlus(1.2);
        }else{
            zoomMinus(1.2);
        }
    QPointF pointAfterScale( QGraphicsView::mapToScene( event->pos() ) );
    QPointF offset = pointBeforeScale - pointAfterScale;
    QPointF newCenter = screenCenter + offset;
    centerOn(newCenter);
}

void View::resetScale()
{
    QMatrix m;
    qreal r = *rotator;
    m.rotate(r);
    setMatrix(m);
    centerOn(scene()->sceneRect().center());
}
void View::zoomPlus(double factor)
{
    scale(factor,factor);
}

void View::zoomMinus(double factor)
{
    scale(1.0 / factor, 1.0 / factor);
}


