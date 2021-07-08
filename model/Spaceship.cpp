#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>

#include "Spaceship.h"
#include "Bullet.h"

SpaceShip * SpaceShip::spaceShip = nullptr;

SpaceShip::SpaceShip() : QObject() , QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/spaceship.png"));


    setFlag(QGraphicsPixmapItem::ItemIsFocusable,true);
    setFocus();

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

    if( bulletSound->state() == QMediaPlayer::PlayingState ){
        bulletSound->setPosition(0);
    }
    else if( bulletSound->state() == QMediaPlayer::StoppedState ){
        bulletSound->play();
    }
}


