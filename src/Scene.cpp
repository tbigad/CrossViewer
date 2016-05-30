#include "Scene.h"
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

}

void Scene::setPixmap(QPixmap &pix)
{
    QGraphicsPixmapItem* background = new QGraphicsPixmapItem(pix);
    background->setTransformationMode(Qt::SmoothTransformation);
    background->setPos(QPointF());
    background->setZValue(1);
    setSceneRect(pix.rect());
    addPixmap(pix);
}

Scene::~Scene()
{}
