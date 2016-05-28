#ifndef _VIEW_H_
#define _VIEW_H_

#include <QGraphicsView>

class View : public QGraphicsView
{
    Q_OBJECT

public:
    View(QWidget * map);
    ~View();
};

#endif // _VIEW_H_
