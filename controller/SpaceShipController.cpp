#include "SpaceShipController.h"
#include <QGraphicsScene>
#include "model/Chickens.h"

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

void SpaceShipController::hitChicken()
{
    QList <QGraphicsItem *> collindingList = spaceShip->collidingItems();
    for(int i = 0; i < collindingList.size(); ++i){
        if(typeid (*(collindingList[i])) == typeid (Chickens)){

            spaceShip->spaceShipHeart->decrease();

            /// delete spaceShip from the scene
            removeSpaceShip();

            /// spaceShip has set to null because we have deleted it from the scene
            spaceShip = nullptr;

            /// add the spaceShip to the scene 2 sec later
            QTimer * reviveSpaceShip = new QTimer();
            reviveSpaceShip->setSingleShot(true);
            connect( reviveSpaceShip, SIGNAL(timeout()), this, SLOT(addSpaceShip()) );
            reviveSpaceShip->start(2000);
        }
    }
}



