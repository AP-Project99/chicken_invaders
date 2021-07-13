#include "SuperChicken.h"

int SuperChicken::superChickenNumbers = 0;


SuperChicken::SuperChicken(int number, int season, int level) :  Birds(number, season, level)
{
    type = "super chicken";
    lives = 4;
    superChickenNumbers++;
}

SuperChicken::~SuperChicken()
{
    superChickenNumbers--;
}

void SuperChicken::setImage(){

    if( imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/superChicken1.png"));
    if( imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/superChicken2.png"));
    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/superChicken3.png"));
    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/superChicken4.png"));
}


