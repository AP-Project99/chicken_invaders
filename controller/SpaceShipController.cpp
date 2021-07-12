#include "SpaceShipController.h"
#include <QGraphicsScene>
#include "model/Birds.h"


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
    spaceShip = nullptr;
}

void SpaceShipController::fire()
{
    if(spaceShip){
        Bullet * bullet = new Bullet();
        allBullets.push_back(bullet);
        ViewController::scene->addItem(bullet);

        bulletSound = new QMediaPlayer();
        bulletSound->setMedia(QUrl("qrc:/music/bullet.mp3"));

        if( bulletSound->state() == QMediaPlayer::PlayingState )
            bulletSound->setPosition(0);

        else if( bulletSound->state() == QMediaPlayer::StoppedState )
            bulletSound->play();
    }
}

/// # move functions for spaceShip
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
/// # end of move functions

void SpaceShipController::hitChicken()
{
    QList <QGraphicsItem *> collidingList = spaceShip->collidingItems();

    for(int i = 0; i < collidingList.size(); ++i){
        if( dynamic_cast <Birds *> (collidingList[i]) ){

            spaceShip->spaceShipHeart->decrease();

            /// delete spaceShip from the scene
           /// spaceShip has set to null because we have deleted it from the scene
            removeSpaceShip();

            /// add the spaceShip to the scene 2 sec later
            reviveSpaceShip();

            break;          /// if spaceShip hits many chickens only one health will be decreased
        }

        if(typeid( *(collidingList[i]) ) == typeid(Egg) ){
            spaceShip->spaceShipHeart->decrease();

            removeSpaceShip();

            reviveSpaceShip();

//            break;

        }
    }
}

void SpaceShipController::reviveSpaceShip(){
    QTimer * reviveSpaceShip = new QTimer();

    reviveSpaceShip->setSingleShot(true);
    connect( reviveSpaceShip, SIGNAL(timeout()), this, SLOT(addSpaceShip()) );
    reviveSpaceShip->start(2000);
}


