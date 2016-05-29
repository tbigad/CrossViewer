#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsscene>


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = 0);
    ~Scene();
};

#endif // SCENE_H
