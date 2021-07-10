#include "Bullet.h"
#include "Spaceship.h"
#include "Chickens.h"

Bullet::Bullet() : QObject() , QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/bullet2.png"));
    setPos(SpaceShip::getInstance()->x()+70, SpaceShip::getInstance()->y() - 35);

    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(move()));
    bulletTimer->start(25);

    chickenController = ChickenController::getInstance();
}

void Bullet::bulletHitChicken()
{
    QList<QGraphicsItem *> collidingList = collidingItems();

    bool hitted = false;

    for ( int i = 0; i < collidingList.size() ; ++i ) {
        if (typeid ( *(collidingList[i]) ) == typeid (Chickens)) {
            chickenController->decrementChicken( dynamic_cast <Chickens *>(collidingList[i]) );

            hitted = true;
        }
    }

    if(hitted){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::move()
{
    bulletHitChicken();

    setPos(x(), y() - 10);

    if( y() == 0 ){
        scene()->removeItem(this);
        delete this;
    }
}
