#ifndef CHICKENCONTROLLER_H
#define CHICKENCONTROLLER_H

#include <QObject>
#include <QList>
#include <cstdlib>

#include "ViewController.h"
#include "model/Chickens.h"
#include "model/Hen.h"
#include "model/Score.h"

class ChickenController : public QObject
{
    Q_OBJECT

private:
    static ChickenController * chickenController;

    explicit ChickenController();

    QVector <Hen *> allHens;

    QList< Birds *> allBirds;




    Score * score;

    int season;
    int level;

    QGraphicsTextItem *txt;


public:
    static ChickenController * getInstance();


    void decrementChicken(Birds *);


    void hitEgg(Egg *);


    void timerAddChicken(int ,int);

    void addEggTimer();

public slots:
    void addEgg();

    void addChicken();

};

#endif // CHICKENCONTROLLER_H
