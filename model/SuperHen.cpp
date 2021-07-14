#include "SuperHen.h"



SuperHen::SuperHen(int number, int season, int level) :  Hen(number, season, level)
{
    type = "super hen";
    lives = 4;
}

SuperHen::~SuperHen()
{

}

void SuperHen::setImage(){

    if( imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/superChicken1.png"));

    if( imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/superChicken2.png"));

    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/superChicken3.png"));

    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/superChicken4.png"));
}


