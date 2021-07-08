#include "Heart.h"
#include <QFont>
#include <QGraphicsScene>

int Heart::heartPlayer=3;

Heart::Heart(QGraphicsScene *scene)
{
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
    heartPlayer--;

    QGraphicsTextItem *txt=new QGraphicsTextItem();
    txt->setPlainText(QString::number(heartPlayer));

    if(heartPlayer==0)
        exit(1);
}

