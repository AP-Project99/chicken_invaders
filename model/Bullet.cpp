#include "Bullet.h"
#include "Spaceship.h"
#include "Birds.h"
#include "Egg.h"

#include <QDebug>

Bullet::Bullet() : QObject() , QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/bullet2.png"));
    setPos(SpaceShip::getInstance()->x() + 70, SpaceShip::getInstance()->y() - 35);

    bulletTimer = new QTimer;
    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(move()));
    bulletTimer->start(25);

    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/music/bullet.mp3"));

    if( bulletSound->state() == QMediaPlayer::PlayingState )
        bulletSound->setPosition(0);

    else if( bulletSound->state() == QMediaPlayer::StoppedState )
        bulletSound->play();


}

Bullet::~Bullet(){
    delete bulletSound;
    delete bulletTimer;
}


void Bullet::bulletHitChicken()
{
    /// initialize controller for chicken
    chickenController = ChickenController::getInstance();

    QList<QGraphicsItem *> collidingList = collidingItems();

    bool hitted = false;

    for ( int i = 0; i < collidingList.size() ; ++i ) {
        QMediaPlayer * hitObject = nullptr;

        if (dynamic_cast <Birds *> (collidingList[i])) {      /// if it "is a" bird

            //sound for hit bullet to chicken
            hitObject = new QMediaPlayer;
            hitObject->setMedia(QUrl("qrc:/music/bulletToChicken.mp3"));

            if(hitObject->state() == QMediaPlayer::PlayingState)
                hitObject->setPosition(0);

            else if(hitObject->state() == QMediaPlayer::StoppedState)
                hitObject->play();

            chickenController->decrementChicken( dynamic_cast <Birds *>(collidingList[i]) );

            hitted = true;
        }

        else if( typeid(*(collidingList[i])) == typeid(Egg) ){

            hitObject = new QMediaPlayer;
            chickenController->hitEgg(dynamic_cast <Egg *>(collidingList[i]));

            hitted = true;
        }

        if (hitObject){
            delete hitObject;
            hitObject = nullptr;
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

    if( y() <= 0 ){
        ViewController::scene->removeItem(this);
        delete this;
    }
}
