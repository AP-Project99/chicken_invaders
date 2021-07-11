#include "ChickenController.h"

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


void ChickenController::addChicken(int level){


    if(level == 1){
        Chickens::setTotal(20);

        for (int i = 0; i < 20 ; ++i ) {
            allChickens.push_back(new Chickens(i, 1, 1));
            ViewController::scene->addItem(allChickens[i]);
        }
    }
    else if (level == 2) {
        Chickens::setTotal(36);
        allChickens.clear();                       /// clear the allChicken list

        for (int i = 0; i < 36 ; ++i ) {
            allChickens.push_back(new Chickens(i, 2, 1));
            ViewController::scene->addItem(allChickens[i]);
        }
    }
}

void ChickenController::decrementChicken(Chickens * chick)
{

    chick->lives--;
    if(chick->lives == 0){
        score->increase();

        ViewController::scene->removeItem(chick);
        delete chick;
        chick = nullptr;

        Chickens::total--;
    }

    if(Chickens::total == 0){
        addChicken(2);
    }
}

