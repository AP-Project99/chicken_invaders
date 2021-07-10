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


public:
    static ChickenController * getInstance();



    void addChicken(int);

    void decrementChicken(Chickens *);

    void removeChickens();


};

#endif // CHICKENCONTROLLER_H
