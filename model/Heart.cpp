#include "Heart.h"
#include <QFont>
#include <QGraphicsScene>

Heart::Heart(QGraphicsScene *scene) : heart(3)
{
    //set text in board heart
    setPlainText(QString::number(heart));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));

    //set picture heart
    QGraphicsPixmapItem *scoreBoard=new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/heart.png"));
    scoreBoard->setPos(0,630);
    scene->addItem(scoreBoard);
}
