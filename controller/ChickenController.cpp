#include "ChickenController.h"
#include <iostream>
using namespace std;

ChickenController::ChickenController() : QObject()
{
   score = Score::getInstance();

}

ChickenController * ChickenController::chickenController = nullptr;

ChickenController * ChickenController::getInstance(){
    if(chickenController == nullptr)
        chickenController = new ChickenController;

    return chickenController;
}

void ChickenController::timerAddChicken(int level,int season){

    this->level=level;
    this->season=season;

    txt = new QGraphicsTextItem();
    QString str = "season " + QString::number(season) + " - level " + QString::number(level);
    txt->setPlainText(str);
    txt->setDefaultTextColor(Qt::gray);
    txt->setFont(QFont("SF Port McKenzie Extended",40));
    txt->setPos(550,300);
    ViewController::scene->addItem(txt);

    QTimer *betweenLevel=new QTimer();
    betweenLevel->setSingleShot(true);
    connect( betweenLevel, SIGNAL(timeout()), this, SLOT(addChicken()));
    betweenLevel->start(4000);

}

void ChickenController::addChicken(){
    ViewController::scene->removeItem(txt);
    delete txt;
    txt=nullptr;

    if(level == 1 && season == 1){
        Chickens::setTotal(20);

        for (int i = 0; i < 20 ; ++i ) {
            allChickens.push_back(new Chickens(i, 1, 1, 1));
            ViewController::scene->addItem(allChickens[i]);
        }
    }
    if (level == 2 && season == 1) {
        allChickens.clear();                           /// clear the allChicken list
        Chickens::setTotal(36);

        for (int i = 0; i < 36 ; ++i ) {
            allChickens.push_back(new Chickens(i, 2, 1, 1));
            ViewController::scene->addItem(allChickens[i]);
        }
    }
    if (level == 1 && season == 2) {
        allChickens.clear();                           /// clear the allChicken list
        Chickens::setTotal(24);

        for (int i = 0; i < 24 ; ++i ) {

            if( i % 2 == 0){
                allChickens.push_back(new Chickens(i, 1, 2, 1));   //for chicken lives=1
                ViewController::scene->addItem(allChickens[i]);
            }

            if( i % 2 != 0){
                allChickens.push_back(new Chickens(i, 1, 2, 2));  // for hen lives=2
                ViewController::scene->addItem(allChickens[i]);
            }
        }
    }
}

void ChickenController::decrementChicken(Chickens * chick)
{

    chick->lives--;
    if(chick->lives == 0){
        if( chick->type == "chicken")
            score->increase(5);
        if( chick->type == "hen")
            score->increase(10);

        ViewController::scene->removeItem(chick);
        delete chick;
        chick = nullptr;

        Chickens::total--;
    }

    if(Chickens::total == 0){
        level++;
        if( level == 3){
            level = 1;
            season++;
        }
        timerAddChicken(level,season);
    }
}

void ChickenController::removeChickens()
{
    allChickens.clear();
}
