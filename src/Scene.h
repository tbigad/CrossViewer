#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsscene>
#include <QGraphicsPixmapItem>


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = 0);
    void setPixmap(QPixmap &pix);
    ~Scene();
};

#endif // SCENE_H
