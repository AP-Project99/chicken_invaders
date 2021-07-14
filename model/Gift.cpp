#include "Gift.h"
#include "controller/ViewController.h"

Gift::Gift()
{
    setPixmap(QPixmap(":/images/gift.png"));
    setPos(rand() % 1350 , 0);


    goDownTimer = new QTimer;
    connect(goDownTimer , SIGNAL(timeout()) , this, SLOT(moveDown()));
    goDownTimer->start(50);

}

void Gift::moveDown()
{
    if(y() >= 650)
        delete this;

    else
        setPos(x(), y() + 5);

}
