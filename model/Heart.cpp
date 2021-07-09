#include "Heart.h"
#include <QFont>
#include <QGraphicsScene>

Heart::Heart(QGraphicsScene *scene)
{
    heartPlayer=3;
    //set text in board heart
    setPlainText(QString::number(heartPlayer));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));
    setPos(20,620);

    //set picture heart
    QGraphicsPixmapItem *scoreBoard=new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/heart.png"));
    scoreBoard->setPos(0,622);
    scene->addItem(scoreBoard);
}

void Heart::decrease()
{
    --heartPlayer;
    setPlainText(QString::number(heartPlayer));

    if(heartPlayer==0)
        exit(1);
}

