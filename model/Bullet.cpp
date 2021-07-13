#include "Bullet.h"
#include "Spaceship.h"
#include "Birds.h"
#include "Egg.h"

#include <QDebug>

Bullet::Bullet() : QObject() , QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/bullet2.png"));
    setPos(SpaceShip::getInstance()->x() + 70, SpaceShip::getInstance()->y() - 35);

    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(move()));
    bulletTimer->start(25);

    /// initialize controller for chicken
    chickenController = ChickenController::getInstance();
}


void Bullet::bulletHitChicken()
{
    QList<QGraphicsItem *> collidingList = collidingItems();

    bool hitted = false;

    for ( int i = 0; i < collidingList.size() ; ++i ) {
        if (dynamic_cast <Birds *> (collidingList[i])) {      /// if it "is a" bird

            //sound for hit bullet to chicken
            QMediaPlayer *hitPlayer = new QMediaPlayer;
            hitPlayer->setMedia(QUrl("qrc:/music/bulletToChicken.mp3"));

            if(hitPlayer->state() == QMediaPlayer::PlayingState)
                hitPlayer->setPosition(0);
            else if(hitPlayer->state() == QMediaPlayer::StoppedState)
                hitPlayer->play();


            chickenController->decrementChicken( dynamic_cast <Birds *>(collidingList[i]) );

            hitted = true;
        }

        if(typeid(*(collidingList[i])) == typeid(Egg)){
            chickenController->hitEgg(dynamic_cast <Egg *>(collidingList[i]));
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
