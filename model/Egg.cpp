#include "Egg.h"
#include "controller/ViewController.h"

Egg::Egg(Hen * hen) : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/egg.png"));
    setPos(hen->x() + hen->boundingRect().width()/2 , hen->y() + hen->boundingRect().height());

    //sound for add egg
    QMediaPlayer *eggPlayer = new QMediaPlayer;
    eggPlayer->setMedia(QUrl("qrc:/music/egg.mp3"));

    if(eggPlayer->state() == QMediaPlayer::PlayingState)
        eggPlayer->setPosition(0);
    else if(eggPlayer->state() == QMediaPlayer::StoppedState)
        eggPlayer->play();

    eggTimer = new QTimer;
    connect(eggTimer, SIGNAL(timeout()), this, SLOT(moveDown()) );
    eggTimer->start(40);

    ViewController::scene->addItem(this);
}


void Egg::moveDown(){

    if(y() == 620){

        //sound for nimroo egg
//        QMediaPlayer *nimrooPlayer = new QMediaPlayer;
//        nimrooPlayer->setMedia(QUrl("qrc:/music/finishEgg.mp3"));

//        if(nimrooPlayer->state() == QMediaPlayer::PlayingState)
//            nimrooPlayer->setPosition(0);
//        else if(nimrooPlayer->state() == QMediaPlayer::StoppedState)
//            nimrooPlayer->play();

        reachEnd();
    }
    else
        setPos( x() , y() + 5 );

}

void Egg::reachEnd(){
    setPixmap(QPixmap(":/images/nimroo.png"));

    QTimer * delNimro = new QTimer;
    delNimro->setSingleShot(true);
    delNimro->start(1000);

    connect(delNimro, SIGNAL(timeout()), this, SLOT(removeNimroo()) );
}

void Egg::removeNimroo(){
    ViewController::scene->removeItem(this);
    delete this;

}
