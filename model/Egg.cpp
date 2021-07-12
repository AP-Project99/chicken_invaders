#include "Egg.h"
#include "controller/ViewController.h"

Egg::Egg(Hen * hen) : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/egg.png"));
    setPos(hen->x() + hen->boundingRect().width()/2 , hen->y() + hen->boundingRect().height());

    eggTimer = new QTimer;
    connect(eggTimer, SIGNAL(timeout()), this, SLOT(moveDown()) );
    eggTimer->start(40);

    ViewController::scene->addItem(this);
}


void Egg::moveDown(){

    if(y() == 620)
        reachEnd();
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
