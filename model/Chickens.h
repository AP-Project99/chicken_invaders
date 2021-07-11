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
    int limitDown;

    int imageTimer = 0;


public:

    explicit Chickens(int number,int level, int season, int lives);

    void setImage();

    void setChickenPos11(int number);

    void setChickenPos12(int number);

    void setChickenPos21(int number);

    static int total;

    static int getTotal() ;

    static void setTotal(int newTotal);

    int lives;

    QString type;


signals:

public slots:
    void incrementChickenTimer();

    void moveChicken();

    void moveDown();


};

#endif // CHICKENS_H
