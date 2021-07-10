#include "Score.h"
#include <QFont>
#include <QGraphicsScene>
#include <controller/ViewController.h>


Score::Score()
{
    playerScore = 0;

    //set text in score board
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));
    setPos(10,-8);

    //set picture score board
    scoreBoard = new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/score.png"));
    scoreBoard->setPos(0,0);
    ViewController::scene->addItem(scoreBoard);

}

Score * Score::score = nullptr;

Score *Score::getInstance()
{
    if(score == nullptr)
        score = new Score;
    return score;
}

void Score::increase()
{
    playerScore += 5;
    setPlainText(QString::number(playerScore));
}
