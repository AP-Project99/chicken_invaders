#include "Hen.h"

int Hen::henNumbers = 0;


Hen::Hen(int number, int season, int level) :  Birds(number, season, level)
{
    type = "hen";
    lives = 2;
    henNumbers++;
}

Hen::~Hen()
{
    henNumbers--;
}

void Hen::setImage(){

    if( imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/hen1.png"));
    if( imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/hen2.png"));
    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/hen3.png"));
    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/hen4.png"));
}


