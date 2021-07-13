#include "Birds.h"

int Birds::totalAnimals = 0;

Birds::Birds(int number, int season, int level) : QObject()
{
    if(season == 1){
        if(level == 1 )
            setChickenPos11(number);

        if(level == 2 )
            setChickenPos12(number);
    }

    else if(season == 2){
        if(level == 1)
            setChickenPos21(number);

        if( level == 2)
            setChickenPos22(number);
    }

    //for animated image
    chickenTimer = new QTimer;
    connect(chickenTimer , SIGNAL(timeout()), this , SLOT(incrementChickenTimer()));
    chickenTimer->start(120);


    //for velocity image
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveDown()));
    moveTimer->start(50);
}

void Birds::incrementChickenTimer()
{
    imageTimer++;
    setImage();
}

void Birds::moveDown(){
    if( y() == limitDown )
        moveBirds();
    else
        setPos(x() , y() + 10 );
}



void Birds::moveBirds()
{
    /// if bird going left and pos is greater than left limitation -> go left
    if( x() > limitLeft  && goingLeft){
        setPos(x() - 10, y() );

   /// if bird going right and pos + width of bird (the right pos of bird) is lower than right limitation -> go right
    } else if(  x() + boundingRect().width() < limitRight ){
         setPos(x() + 10, y() );
         goingLeft = false;

    } else
         goingLeft = true;

}

void Birds::setChickenPos11(int number)
{
    int x;
    int y = 0;

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

void Birds::setChickenPos12(int number)
{
    int x;
    int y = 0;

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

void Birds::setChickenPos21(int number)
{
    int x;
    int y = 0;

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

void Birds::setChickenPos22(int number)
{
    int x;
    int y = 0;

    if(number<10)
        y=-180;
    if(number>=10&&number<20)
        y=-120;
    if(number>=20&&number<30)
        y=-60;

    number%=10;
    x=300+(number)*80;
    setPos(x,y);
    limitLeft=x-300;
    limitRight=1350-(9-number)*80;
    limitDown=y+280;
}

