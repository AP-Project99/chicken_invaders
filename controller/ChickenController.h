#ifndef CHICKENCONTROLLER_H
#define CHICKENCONTROLLER_H

#include <QObject>
#include <QList>

#include "ViewController.h"
#include "model/Chickens.h"
#include "model/Score.h"

class ChickenController : public QObject
{
    Q_OBJECT

private:
    static ChickenController * chickenController;

    explicit ChickenController();

    QList <Chickens *> allChickens;

    Score * score;

    int season;
    int level;

    QGraphicsTextItem *txt;


public:
    static ChickenController * getInstance();

    void decrementChicken(Chickens *);

    void removeChickens();

    void timerAddChicken(int ,int);

public slots:

    void addChicken();

};

#endif // CHICKENCONTROLLER_H
