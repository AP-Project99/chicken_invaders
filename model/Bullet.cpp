#include "Bullet.h"
#include "Spaceship.h"

Bullet::Bullet(QGraphicsScene * scene) : QObject() , QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/bullet2.png"));
    setPos(SpaceShip::getInstance()->x()+70, SpaceShip::getInstance()->y() - 35);
    scene->addItem(this);

    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(move()));
    bulletTimer->start(25);

}

void Bullet::move()
{
    setPos(x(), y() - 10);
}
