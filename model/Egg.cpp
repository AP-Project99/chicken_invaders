#include "Egg.h"
#include "controller/ViewController.h"

#include <QDebug>

Egg::Egg(Hen * hen) : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/egg.png"));
    setPos(hen->x() + hen->boundingRect().width()/2 , hen->y() + hen->boundingRect().height());

    //sound for add egg
    eggSound = new QMediaPlayer;
    eggSound->setMedia(QUrl("qrc:/music/egg.mp3"));

    if(eggSound->state() == QMediaPlayer::PlayingState)
        eggSound->setPosition(0);

    else if(eggSound->state() == QMediaPlayer::StoppedState)
        eggSound->play();

    eggTimer = new QTimer;
    connect(eggTimer, SIGNAL(timeout()), this, SLOT(moveDown()) );
    eggTimer->start(40);

}

Egg::~Egg(){
    delete eggSound;
    delete eggTimer;
}


void Egg::moveDown(){

    if(y() >= 620){
        reachEnd();
    }
    else
        setPos( x() , y() + 5 );

}

void Egg::reachEnd(){
    setPixmap(QPixmap(":/images/nimroo.png"));

    reachedEnd = true;

    delNimroTimer = new QTimer;
    delNimroTimer->setSingleShot(true);
    delNimroTimer->start(1000);

    connect(delNimroTimer, SIGNAL(timeout()), this, SLOT(removeNimroo()) );
}

void Egg::removeNimroo(){
    delete delNimroTimer;

    ViewController::scene->removeItem(this);
    delete this;
}
