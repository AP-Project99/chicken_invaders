#ifndef CHICKENCONTROLLER_H
#define CHICKENCONTROLLER_H

#include <QObject>
#include <QList>

#include "ViewController.h"
#include "model/Chickens.h"
#include "model/Score.h"

class ChickenController : QObject
{
    Q_OBJECT

private:
    static ChickenController * chickenController;

    explicit ChickenController();

    QList <Chickens *> allChickens;

    Score * score;

    int season;
    int level;


public:
    static ChickenController * getInstance();



    void addChicken(int,int);

    void decrementChicken(Chickens *);

    void removeChickens();


};

#endif // CHICKENCONTROLLER_H
