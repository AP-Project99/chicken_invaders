#include "Chickens.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QThread>

int Chickens::total=20;

Chickens::Chickens(int number,int level, Score *scr)
    : QObject() , QGraphicsPixmapItem()
{
    score=scr;
    setTotal(20);

    setPixmap(QPixmap(":/images/oneChicken1.png"));
    if(level==1)
        setChickenPos(number);
    if(level==2)
        setChickenPos2(number);

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

    if( x() > limitLeft  && goingLeft){
        setPos(x() - 10, y() );

    } else if(  x() + boundingRect().width() < limitRight ){
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

        total--;
        scene()->removeItem(this);
        delete this;
    }
}

int Chickens::getTotal() const
{
    return total;
}

void Chickens::setTotal(int newTotal)
{
    total =newTotal;
}

void Chickens::setChickenPos(int number)
{
    int x;
    int y;

    if(number<5)
        y=100;
    if(number>=5&&number<10)
        y=160;
    if(number>=10&&number<15)
        y=220;
    if(number>=15&&number<20)
        y=280;

    number%=5;
    x=1350+(number)*80;
    setPos(x,y);
    limitLeft=x-1350;
    limitRight=1350-(4-number)*80;
}

void Chickens::setChickenPos2(int number)
{
    int x;
    int y;

    if(number<9)
        y=100;
    if(number>=9&&number<18)
        y=160;
    if(number>=18&&number<27)
        y=220;
    if(number>=27&&number<36)
        y=280;

    number%=9;
    x=1350+(number)*80;
    setPos(x,y);
    limitLeft=x-1350;
    limitRight=1350-(8-number)*80;
}


