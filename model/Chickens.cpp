#include "Chickens.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QList>


Chickens::Chickens(int number, int season, int level) : Birds(number, season, level)
{

    type = "chicken";
    lives = 1;

}

void Chickens::setImage()
{
    if( imageTimer % 4 == 0)
        setPixmap(QPixmap(":/images/oneChicken1.png"));
    if(imageTimer % 4 == 1)
        setPixmap(QPixmap(":/images/oneChicken2.png"));
    if( imageTimer % 4 == 2)
        setPixmap(QPixmap(":/images/oneChicken3.png"));
    if( imageTimer % 4 == 3)
        setPixmap(QPixmap(":/images/oneChicken4.png"));

}






