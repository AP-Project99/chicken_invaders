#ifndef CHICKENS_H
#define CHICKENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Score.h"

class Chickens : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * chickenTimer;
    QTimer * moveTimer;

    bool goingLeft = true;

    int imageTimer = 0;

    int lives=1;

    Score *score;

public:

    explicit Chickens(int number,Score *scr);

    void setImage();

    void decrementChicken();

    void setChickenPos(int number);

signals:

public slots:
    void incrementChickenTimer();

    void moveChicken();


};

#endif // CHICKENS_H
