#ifndef CHICKENS_H
#define CHICKENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Score.h"
#include "Heart.h"
#include "controller/SpaceShipController.h"

class SpaceShipController;
class Chickens : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * chickenTimer;
    QTimer * moveTimer;

    bool goingLeft = true;

    int limitLeft;
    int limitRight;

    int imageTimer = 0;

    int lives=1;

    Score *score;


public:

    explicit Chickens(int number,int level,Score *scr);

    void setImage();

    void decrementChicken();

    void setChickenPos(int number);

    void setChickenPos2(int number);

    static int total;

    int getTotal() const;
    void setTotal(int newTotal);

signals:

public slots:
    void incrementChickenTimer();

    void moveChicken();


};

#endif // CHICKENS_H
