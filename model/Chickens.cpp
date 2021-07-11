#include "Chickens.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

int Chickens::total;

Chickens::Chickens(int number,int level, int season, int lives) : QObject() , QGraphicsPixmapItem()
{

    if(level == 1 && season == 1 && lives == 1){   // season 1 - level 1
        setChickenPos11(number);
        type = "chicken";
    }

    if(level == 2 && season == 1 && lives == 1){   // season 1 - level 2
        setChickenPos12(number);
        type = "chicken";
    }

    if(level == 1 && season == 2 && lives == 2){   // season 2 - level 1 for hen
        setChickenPos21(number);
        type = "hen";
    }

    if(level == 1 && season == 2 && lives == 1){   // season 2 - level 1 for chicken
        setChickenPos21(number);
        type = "chicken";
    }

    this->lives = lives;

    //for animated image
    chickenTimer = new QTimer;

    connect(chickenTimer , SIGNAL(timeout()), this , SLOT(incrementChickenTimer()));
    chickenTimer->start(120);

    //for velocity image
    moveTimer = new QTimer;

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveDown()));
    moveTimer->start(50);
}

void Chickens::incrementChickenTimer()
{
    imageTimer++;
    setImage();
}

void Chickens::setImage()
{
    if( type == "chicken" ){

        if( imageTimer % 4 == 0)
            setPixmap(QPixmap(":/images/oneChicken1.png"));
        if(imageTimer % 4 == 1)
            setPixmap(QPixmap(":/images/oneChicken2.png"));
        if( imageTimer % 4 == 2)
            setPixmap(QPixmap(":/images/oneChicken3.png"));
        if( imageTimer % 4 == 3)
            setPixmap(QPixmap(":/images/oneChicken4.png"));
    }
    if ( type == "hen" ){

        if( imageTimer % 4 == 0)
            setPixmap(QPixmap(":/images/hen1.png"));
        if(imageTimer % 4 == 1)
            setPixmap(QPixmap(":/images/hen2.png"));
        if( imageTimer % 4 == 2)
            setPixmap(QPixmap(":/images/hen3.png"));
        if( imageTimer % 4 == 3)
            setPixmap(QPixmap(":/images/hen4.png"));
    }
}

void Chickens::moveDown(){
    if( y() == limitDown )
        moveChicken();
    else
        setPos(x() , y() +10 );
}


void Chickens::moveChicken()
{
    /// if chickens going left and pos is greater than left limitation -> go left
    if( x() > limitLeft  && goingLeft){
        setPos(x() - 10, y() );

   /// if chickens going right and pos + width of chicken (the right pos of chicken) is lower than right limitation -> go right
    } else if(  x() + boundingRect().width() < limitRight ){
         setPos(x() + 10, y() );
         goingLeft = false;

    } else
         goingLeft = true;

}

int Chickens::getTotal()                // total getter
{
    return total;
}

void Chickens::setTotal(int newTotal)   // total setter
{
    total = newTotal;
}


void Chickens::setChickenPos11(int number)
{
    int x;
    int y;

    if(number<5)
        y=-240;
    if(number>=5&&number<10)
        y=-180;
    if(number>=10&&number<15)
        y=-120;
    if(number>=15&&number<20)
        y=-60;

    number%=5;
    x=450+(number)*80;
    setPos(x,y);
    limitLeft=x-450;
    limitRight=1350-(4-number)*80;
    limitDown=y+340;
}

void Chickens::setChickenPos12(int number)
{
    int x;
    int y;

    if(number<9)
        y=-240;
    if(number>=9&&number<18)
        y=-180;
    if(number>=18&&number<27)
        y=-120;
    if(number>=27&&number<36)
        y=-60;

    number%=9;
    x=300+(number)*80;
    setPos(x,y);
    limitLeft=x-300;
    limitRight=1350-(8-number)*80;
    limitDown=y+340;
}

void Chickens::setChickenPos21(int number)
{
    int x;
    int y;

    if(number<8)
        y=-180;
    if(number>=8&&number<16)
        y=-120;
    if(number>=16&&number<24)
        y=-60;

    number%=8;
    x=350+(number)*80;
    setPos(x,y);
    limitLeft=x-350;
    limitRight=1350-(7-number)*80;
    limitDown=y+280;
}


