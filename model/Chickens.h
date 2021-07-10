#ifndef CHICKENS_H
#define CHICKENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Heart.h"

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


public:

    explicit Chickens(int number,int level, int lives);

    void setImage();


    void setChickenPos(int number);

    void setChickenPos2(int number);

    static int total;

    static int getTotal() ;

    static void setTotal(int newTotal);

    int lives;


signals:

public slots:
    void incrementChickenTimer();

    void moveChicken();


};

#endif // CHICKENS_H
