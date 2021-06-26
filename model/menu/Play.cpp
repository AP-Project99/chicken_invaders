#include "Play.h"

Play::Play() :QObject(), QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/start.png"));
    setPos(510,400);

}

void Play::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
