#include "SpaceShipController.h"
#include <QGraphicsScene>
#include "model/Birds.h"
#include "model/Meat.h"


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
    delete reviveSpaceShipTimer;

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
        ViewController::scene->addItem(bullet);
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

            soundSpaceShipToChicken();

            spaceShip->spaceShipHeart->decrease();

            /// delete spaceShip from the scene spaceShip has set to null
            removeSpaceShip();

            /// add the spaceShip to the scene 2 sec later
            reviveSpaceShip();

            break;          /// if spaceShip hits many chickens only one health will be decreased
        }

        else if(typeid( *(collidingList[i]) ) == typeid(Egg) ){
            if( dynamic_cast <Egg *> (collidingList[i])->reachedEnd == false ){

                soundSpaceShipToEgg();

                spaceShip->spaceShipHeart->decrease();

                removeSpaceShip();

                reviveSpaceShip();
            }
        }

        else if( typeid( *(collidingList[i]) ) == typeid(Meat) ){

            soundSpaceShipToMeat();

            ChickenController::getInstance()->meatHittedBySpaceShip(dynamic_cast <Meat *> (collidingList[i]));
        }

        if( hitSpaceShipSound ){
            QTimer *delTimer = new QTimer;
            delTimer->setSingleShot(true);
            connect(delTimer , SIGNAL(timeout()) , this , SLOT(deleteSound()));
            delTimer->start(2000);
        }

    }
}

void SpaceShipController::deleteSound()
{
    delete hitSpaceShipSound;
    hitSpaceShipSound = nullptr;
}


void SpaceShipController::soundSpaceShipToChicken()
{
    //sound for hit spaceship to birds
    hitSpaceShipSound = new QMediaPlayer;
    hitSpaceShipSound->setMedia(QUrl("qrc:/music/spaceshipToChicken.mp3"));

    if(hitSpaceShipSound->state() == QMediaPlayer::PlayingState)
        hitSpaceShipSound->setPosition(0);

    else if(hitSpaceShipSound->state() == QMediaPlayer::StoppedState)
        hitSpaceShipSound->play();

}

void SpaceShipController::soundSpaceShipToEgg()
{
    //sound for hit spaceship to eggs
    hitSpaceShipSound = new QMediaPlayer;
    hitSpaceShipSound->setMedia(QUrl("qrc:/music/spaceshipToEgg.mp3"));

    if(hitSpaceShipSound->state() == QMediaPlayer::PlayingState)
        hitSpaceShipSound->setPosition(0);

    else if(hitSpaceShipSound->state() == QMediaPlayer::StoppedState)
        hitSpaceShipSound->play();
}

void SpaceShipController::soundSpaceShipToMeat()
{
    //sound for hit spaceship to meat for get score
    hitSpaceShipSound = new QMediaPlayer;
    hitSpaceShipSound->setMedia(QUrl("qrc:/music/meat.mp3"));

    if(hitSpaceShipSound->state() == QMediaPlayer::PlayingState)
        hitSpaceShipSound->setPosition(0);

    else if(hitSpaceShipSound->state() == QMediaPlayer::StoppedState)
        hitSpaceShipSound->play();
}


void SpaceShipController::reviveSpaceShip(){
    reviveSpaceShipTimer = new QTimer();

     reviveSpaceShipTimer->setSingleShot(true);
     connect(  reviveSpaceShipTimer, SIGNAL(timeout()), this, SLOT(addSpaceShip()) );
     reviveSpaceShipTimer->start(2000);
}

void SpaceShipController::addGift()
{
    Gift *gift = new Gift();
    ViewController::scene->addItem(gift);
}
