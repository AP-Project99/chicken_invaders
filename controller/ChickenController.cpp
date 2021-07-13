#include "ChickenController.h"
#include <iostream>
#include <QDebug>

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

    this->level = level;
    this->season = season;

    txt = new QGraphicsTextItem();
    QString str = "season " + QString::number(season) + " - level " + QString::number(level);
    txt->setPlainText(str);
    txt->setDefaultTextColor(Qt::gray);
    txt->setFont(QFont("SF Port McKenzie Extended",40));
    txt->setPos(550,300);

    ViewController::scene->addItem(txt);

    // add chickens after 4 seconds
    QTimer * betweenLevel = new QTimer();
    betweenLevel->setSingleShot(true);
    connect( betweenLevel, SIGNAL(timeout()), this, SLOT(addChicken()));
    betweenLevel->start(4000);


}

void ChickenController::addEggTimer()
{
    QTimer * eggTimer = new QTimer;
    connect(eggTimer, SIGNAL(timeout()), this, SLOT(addEgg()));
    eggTimer->start(5000);
}

void ChickenController::addChicken(){
    ViewController::scene->removeItem(txt);
    delete txt;
    txt = nullptr;


    if(season == 1){
        if(level == 1){
            Birds::totalAnimals = 20;

            for (int i = 0; i < 20 ; ++i ) {
                Birds * bird = new Chickens(i, 1, 1);
                ViewController::scene->addItem(bird);
            }
        }
        if (level == 2) {
            allBirds.clear();                           /// clear the allChicken list
            Birds::totalAnimals = 36;

            for (int i = 0; i < 36 ; ++i ) {
                Birds * bird = new Chickens(i, 1, 2);
                ViewController::scene->addItem(bird);
            }
        }
    }
    if(season == 2){
        if (level == 1) {
            allBirds.clear();                           /// clear the allChicken list
            Birds::totalAnimals = 24;

            for (int i = 0; i < 24 ; ++i ) {
                if( i % 2 == 0 ){
                    Birds * bird = new Chickens(i, 2, 1);
                    ViewController::scene->addItem(bird);
                }

                if( i % 2 == 1 ){
                    Hen * hen = new Hen(i, 2, 1);
                    allHens.push_back(hen);
                    ViewController::scene->addItem(hen);
                }

            }

        }
    }


}

void ChickenController::decrementChicken(Birds * bird)
{

    bird->lives--;
    if(bird->lives == 0){
        if( bird->type == "chicken" )
            score->increase(5);

        if( bird->type == "hen" ){
            score->increase(10);

            for ( int i = 0; i < allHens.size(); i++ ){
                if( bird == allHens[i] ){
                    allHens.erase(allHens.begin() + i);
                }
            }
        }

        ViewController::scene->removeItem(bird);
        delete bird;
        bird = nullptr;

        Birds::totalAnimals--;
    }

    if(Birds::totalAnimals == 0){
        level++;
        if( level == 3 ){
            level = 1;
            season++;
        }

        timerAddChicken(level,season);
    }
}

void ChickenController::addEgg(){
    if( allHens.size() > 0  ){

        int numberOfHens = allHens.size();

        for (int i = 0; i < numberOfHens/4 ; ++i) {
            int index = rand() % numberOfHens;
            allHens[index]->eggs.push_back(new Egg(allHens[index]));
        }
    }
}

void ChickenController::hitEgg(Egg * egg){
    score->increase(5);

    ViewController::scene->removeItem(egg);
    delete egg;
    egg = nullptr;

}

