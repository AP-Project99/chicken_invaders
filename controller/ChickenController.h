#ifndef CHICKENCONTROLLER_H
#define CHICKENCONTROLLER_H

#include <QObject>
#include <QList>
#include <cstdlib>

#include "ViewController.h"
#include "model/Chickens.h"
#include "model/Hen.h"
#include "model/Score.h"
#include "model/SuperHen.h"
#include "model/Meat.h"

class ChickenController : public QObject
{
    Q_OBJECT

private:

    static ChickenController * chickenController;

    explicit ChickenController();

    QVector <Hen *> allHens;

    Score * score;

    int season;
    int level;

    QGraphicsTextItem *txt;

    QMediaPlayer * levelSound;




public:

    ~ChickenController();

    static ChickenController * getInstance();


    void decrementChicken(Birds *);


    void eggHitted(Egg *);

    void meatHittedBySpaceShip(Meat *);


    void timerAddChicken(int ,int);

    void addEggTimer();

    void textLevel();

    void soundLevel();

public slots:
    void addEgg();

    void addChicken();

};

#endif // CHICKENCONTROLLER_H
