#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QWidget>
#include <QMediaPlayer>


//#include "view/View.h"
#include "Bullet.h"


class SpaceShip : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    explicit SpaceShip();                   /// private constructor

    static SpaceShip * spaceShip;         /// the only object of this class

    QList <Bullet *> allBullets;

    QMediaPlayer *bulletSound;

public:
    static SpaceShip * getInstance();     /// creating the only instance of class

    void fire();


signals:


};




#endif // SPACESHIP_H
