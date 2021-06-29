#include "Chickens.h"
#include <QDebug>

Chickens::Chickens() : QObject() , QGraphicsPixmapItem()
{

    setPos(300 , 100);
    setPixmap(QPixmap(":/images/ch1.png"));

    chickenTimer = new QTimer;

    connect(chickenTimer , SIGNAL(timeout()), this , SLOT(incrementChickenTimer()));
    chickenTimer->start(120);


    moveTimer = new QTimer;

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveChicken()));
    moveTimer->start(75);

}

void Chickens::incrementChickenTimer()
{
    imageTimer++;
    setImage();
}

void Chickens::setImage()
{
    if (imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/ch1.png"));
    if(imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/chick2.png"));
    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/chick3.png"));
    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/chick4.png"));

}

void Chickens::moveChicken()
{
    if( x() > 0  && goingLeft)
        setPos(x() - 15, y() );

    else if(  x() + boundingRect().width() < 1350 ){
         setPos(x() + 15, y() );
         goingLeft = false;
    } else
         goingLeft = true;

}
