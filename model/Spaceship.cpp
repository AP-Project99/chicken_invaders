#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>

#include "Spaceship.h"
#include "Bullet.h"

SpaceShip * SpaceShip::spaceShip = nullptr;

SpaceShip::SpaceShip() : QObject() , QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/spaceship.png"));
    setPos(600 , 550);


    this->setFlag(QGraphicsPixmapItem::ItemIsFocusable,true);
    this->setFocus();

}

SpaceShip * SpaceShip::getInstance()
{
    if(spaceShip == nullptr)
        spaceShip = new SpaceShip();

    return spaceShip;
}

//void SpaceShip::keyPressEvent(QKeyEvent *event)
//{

//    if(event->key() == Qt::Key_Left )       /// move
//        if( x() >= -20 )                   /// doesn't go out of view
//            setPos(x() - 20 , y());

//    if(event->key() == Qt::Key_Right )
//        if( x() + boundingRect().width() <= 1370)
//            setPos(x() + 20 , y());

//    if(event->key() == Qt::Key_Up )
//        if(y() >= 0)
//            setPos(x() , y() - 20);

//    if(event->key() == Qt::Key_Down )
//        if( y()  < 580)
//            setPos(x() , y() + 20);

//    if(event->key() == Qt::Key_Space){
//        fire();

//        bulletSound=new QMediaPlayer();
//        bulletSound->setMedia(QUrl("qrc:/music/bullet.mp3"));

//        if(bulletSound->state()==QMediaPlayer::PlayingState){
//            bulletSound->setPosition(0);
//        }
//        else if(bulletSound->state()==QMediaPlayer::StoppedState){
//            bulletSound->play();
//        }
//    }

//}



void SpaceShip::fire(){
    Bullet * bullet = new Bullet();
    allBullets.push_back(bullet);
    scene()->addItem(bullet);

    bulletSound=new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/music/bullet.mp3"));

    if(bulletSound->state()==QMediaPlayer::PlayingState){
        bulletSound->setPosition(0);
    }
    else if(bulletSound->state()==QMediaPlayer::StoppedState){
        bulletSound->play();
    }
}


