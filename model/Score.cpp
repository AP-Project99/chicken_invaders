#include "Score.h"
#include <QFont>
#include <QGraphicsScene>

Score::Score(QGraphicsScene *scene)
{
    playerScore=0;

    //set text in score board
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));
    setPos(10,-8);

    //set picture score board
    QGraphicsPixmapItem *scoreBoard=new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/score.png"));
    scoreBoard->setPos(0,0);
    scene->addItem(scoreBoard);
}

void Score::increase()
{
    playerScore+=5;
    setPlainText(QString::number(playerScore));
}
