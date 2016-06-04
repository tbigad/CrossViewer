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

View::resetScale()
{
    setMatrix( QMatrix() );
    centerOn(scene()->sceneRect().center());
}


