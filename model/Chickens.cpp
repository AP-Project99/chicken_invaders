#include "Chickens.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QThread>

Chickens::Chickens(int number, Score *scr)
    : QObject() , QGraphicsPixmapItem()
{
    score=scr;

    setPixmap(QPixmap(":/images/oneChicken1.png"));
    setChickenPos(number);

    //for animated image
    chickenTimer = new QTimer;

    connect(chickenTimer , SIGNAL(timeout()), this , SLOT(incrementChickenTimer()));
    chickenTimer->start(120);

    //for velocity image
    moveTimer = new QTimer;

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveChicken()));
    moveTimer->start(50);
}

void Chickens::incrementChickenTimer()
{
    imageTimer++;
    setImage();
}

void Chickens::setImage()
{
    if (imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/oneChicken1.png"));
    if(imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/oneChicken2.png"));
    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/oneChicken3.png"));
    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/oneChicken4.png"));

}


void Chickens::moveChicken()
{

    if( x() > 0  && goingLeft)
        setPos(x() - 10, y() );

    else if(  x() + boundingRect().width() < 1350 ){
         setPos(x() + 10, y() );
         goingLeft = false;
    } else
         goingLeft = true;

}


void Chickens::decrementChicken()
{
    --lives;
    if(lives == 0){

        score->increase();

        scene()->removeItem(this);
        delete this;
    }
}

//void Chickens::hitSpaceShip()
//{
//    QList<QGraphicsItem *> collindingList = collidingItems();
//    for(int i=0; i < collindingList.size(); ++i){
//        if(typeid (*(collindingList[i])) == typeid (SpaceShip)){

//            heart->decrease();
//            spaceship->removeSpaceShip();
//            QTimer *t=new QTimer();
//            t->setSingleShot(true);
//            t->setInterval(3000);
//            connect(t, &QTimer::timeout, this, [=](){spaceship->addSpaceShip();});
//            t->start();

//        }
//    }
//}

void Chickens::setChickenPos(int number)
{
    switch (number) {
    case 1:setPos(300,100);break;
    case 2:setPos(380,100);break;
    case 3:setPos(460,100);break;
    case 4:setPos(540,100);break;
    case 5:setPos(620,100);break;
    case 6:setPos(300,160);break;
    case 7:setPos(380,160);break;
    case 8:setPos(460,160);break;
    case 9:setPos(540,160);break;
    case 10:setPos(620,160);break;
    case 11:setPos(300,220);break;
    case 12:setPos(380,220);break;
    case 13:setPos(460,220);break;
    case 14:setPos(540,220);break;
    case 15:setPos(620,220);break;
    case 16:setPos(300,280);break;
    case 17:setPos(380,280);break;
    case 18:setPos(460,280);break;
    case 19:setPos(540,280);break;
    case 20:setPos(620,280);break;
    }
}


