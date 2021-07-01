#include "Bullet.h"
#include "Spaceship.h"
#include "Chickens.h"

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
    //decrement chicken lives
    QList<QGraphicsItem *> collidingList=collidingItems();
    for (int i=0;i<collidingList.size() ;++i ) {
        if (typeid (*(collidingList[i]))==typeid (Chickens)) {
            dynamic_cast<Chickens *>(collidingList[i])->decrementChicken();

            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    setPos(x(), y() - 10);
    if(y()==0){
        scene()->removeItem(this);
        delete this;
    }
}
