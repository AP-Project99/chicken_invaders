#include "Spaceship.h"

SpaceShip * SpaceShip::spaceShip = nullptr;

SpaceShip::SpaceShip() : QObject() , QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/spaceship.png"));


    setFlag(QGraphicsPixmapItem::ItemIsFocusable,true);
    setFocus();


    spaceShipHeart = Heart::getInstance();

}

SpaceShip * SpaceShip::getInstance()
{
    if(spaceShip == nullptr)
        spaceShip = new SpaceShip();

    return spaceShip;
}


