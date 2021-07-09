#include "SpaceShipController.h"
#include <QGraphicsScene>

SpaceShipController::SpaceShipController()
{

}

SpaceShipController * SpaceShipController::spaceShipController = nullptr;

SpaceShipController * SpaceShipController::getInstance()
{
    if(spaceShipController == nullptr)
        spaceShipController = new SpaceShipController;

    return spaceShipController;

}

void SpaceShipController::addSpaceShip()
{
    spaceShip = SpaceShip::getInstance();
    ViewController::scene->addItem(spaceShip);
    spaceShip->setPos(600 , 550);
}

void SpaceShipController::removeSpaceShip(){
    ViewController::scene->removeItem(spaceShip);
    SpaceShip::spaceShip == nullptr;
//    delete SpaceShip::spaceShip;
//    spaceShip->spaceShip == nullptr;
//    delete spaceShip->spaceShip;
//    spaceShip == nullptr;

}

void SpaceShipController::fire()
{
    if(spaceShip)
        spaceShip->fire();
}

void SpaceShipController::moveSpaceShipRight()
{
    if( spaceShip->x() + spaceShip->boundingRect().width() <= 1370)
        spaceShip->setPos(spaceShip->x() + 20 , spaceShip->y());
}

void SpaceShipController::moveSpaceShipUp()
{
    if(spaceShip->y() >= 0)
        spaceShip->setPos(spaceShip->x() , spaceShip->y() - 20);

}

void SpaceShipController::moveSpaceShipDown()
{
    if( spaceShip->y() < 580)
        spaceShip->setPos(spaceShip->x() , spaceShip->y() + 20);
}

void SpaceShipController::moveSpaceShipLeft()
{
    if( spaceShip->x() >= -20 )
        spaceShip->setPos(spaceShip->x() - 20 , spaceShip->y());

}


