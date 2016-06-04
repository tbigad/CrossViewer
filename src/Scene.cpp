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

void Scene::clearScene()
{
    clear();
    QString str(tr(" Open file(press F3)or drop files here"));
    writeText(str);
}

void Scene::writeText(QString &str)
{
    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(16);
    addText(str,font);
}
