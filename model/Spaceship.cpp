#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>
#include "Spaceship.h"
#include "Bullet.h"
#include "Chickens.h"
#include "controller/ViewController.h"

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

void SpaceShip::fire(){
    Bullet * bullet = new Bullet();
    allBullets.push_back(bullet);
    scene()->addItem(bullet);

    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/music/bullet.mp3"));

    if( bulletSound->state() == QMediaPlayer::PlayingState )
        bulletSound->setPosition(0);

    else if( bulletSound->state() == QMediaPlayer::StoppedState )
        bulletSound->play();

}

void SpaceShip::hitChicken()
{
    QList<QGraphicsItem *> collindingList = collidingItems();
    for(int i=0; i < collindingList.size(); ++i){
        if(typeid (*(collindingList[i])) == typeid (Chickens)){

            spaceShipHeart->decrease();

            /// delete spaceShip from the scene
            SpaceShipController::getInstance()->removeSpaceShip();

            /// spaceShip in SpaceShipController has set to null because we have deleted it from the scene
            SpaceShipController::getInstance()->spaceShip = nullptr;

            /// add the spaceShip to the scene 2 sec later
            QTimer * reviveSpaceShip = new QTimer();
            reviveSpaceShip->setSingleShot(true);
            connect( reviveSpaceShip, SIGNAL(timeout()), SpaceShipController::getInstance(), SLOT(addSpaceShip()) );
            reviveSpaceShip->start(2000);
        }
    }
}
