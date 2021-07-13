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

    setPos(22,618);

    //set picture heart
    QGraphicsPixmapItem *scoreBoard=new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/health-meet.png"));
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


    if(spaceShipHeart == 0){

        setPlainText(QString("Game Over !"));
        setDefaultTextColor(Qt::gray);
        setFont(QFont("SF Port McKenzie Extended",40));
        setPos(550,300);

        ViewController::exit();
    }
}


