#include "Heart.h"
#include <QFont>
#include <QGraphicsScene>
#include <controller/ViewController.h>

Heart * Heart::heart = nullptr;     /// initializing static member

Heart::Heart()
{
    spaceShipHeart=3;
    //set text in board heart
    setPlainText(QString::number(spaceShipHeart));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));
    setPos(20,615);

    //set picture heart
    QGraphicsPixmapItem *scoreBoard=new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/heart.png"));
    scoreBoard->setPos(0,622);
    ViewController::scene->addItem(scoreBoard);
}

Heart *Heart::getInstance()
{
    if(heart == nullptr)
        heart = new Heart;
    return heart;
}

void Heart::decrease()
{
    --spaceShipHeart;
    setPlainText(QString::number(spaceShipHeart));


    if(spaceShipHeart == 0)
        exit(1);
}

