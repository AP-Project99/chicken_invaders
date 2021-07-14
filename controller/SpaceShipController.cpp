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
        QMediaPlayer * hitSpaceShip = nullptr;

        if( dynamic_cast <Birds *> (collidingList[i]) ){

            //sound for hit spaceship to birds
            hitSpaceShip = new QMediaPlayer;
            hitSpaceShip->setMedia(QUrl("qrc:/music/spaceshipToChicken.mp3"));

            if(hitSpaceShip->state() == QMediaPlayer::PlayingState)
                hitSpaceShip->setPosition(0);
            else if(hitSpaceShip->state() == QMediaPlayer::StoppedState)
                hitSpaceShip->play();


            spaceShip->spaceShipHeart->decrease();

            /// delete spaceShip from the scene spaceShip has set to null
            removeSpaceShip();

            /// add the spaceShip to the scene 2 sec later
            reviveSpaceShip();

            break;          /// if spaceShip hits many chickens only one health will be decreased
        }

        else if(typeid( *(collidingList[i]) ) == typeid(Egg) ){
            if( dynamic_cast <Egg *> (collidingList[i])->reachedEnd == false ){

                //sound for hit spaceship to eggs
                hitSpaceShip = new QMediaPlayer;
                hitSpaceShip->setMedia(QUrl("qrc:/music/spaceshipToEgg.mp3"));

                if(hitSpaceShip->state() == QMediaPlayer::PlayingState)
                    hitSpaceShip->setPosition(0);
                else if(hitSpaceShip->state() == QMediaPlayer::StoppedState)
                    hitSpaceShip->play();


                spaceShip->spaceShipHeart->decrease();

                removeSpaceShip();

                reviveSpaceShip();
            }
        }

        else if( typeid( *(collidingList[i]) ) == typeid(Meat) ){
            ChickenController::getInstance()->meatHittedBySpaceShip(dynamic_cast <Meat *> (collidingList[i]));
        }

        if( hitSpaceShip ){
            delete hitSpaceShip;
            hitSpaceShip = nullptr;
        }
    }
}

void SpaceShipController::reviveSpaceShip(){
    reviveSpaceShipTimer = new QTimer();

     reviveSpaceShipTimer->setSingleShot(true);
    connect(  reviveSpaceShipTimer, SIGNAL(timeout()), this, SLOT(addSpaceShip()) );
     reviveSpaceShipTimer->start(2000);
}

