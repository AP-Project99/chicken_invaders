#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QWidget>
#include <QMediaPlayer>
#include <QList>

#include "controller/SpaceShipController.h"
#include "Heart.h"
#include "Bullet.h"

class Bullet;
class SpaceShip : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class SpaceShipController;

private:
    explicit SpaceShip();                  /// private constructor

    static SpaceShip * spaceShip;         /// the only object of this class

    QList <Bullet *> allBullets;

    QMediaPlayer *bulletSound;

    Heart * spaceShipHeart;

public:
    static SpaceShip * getInstance();     /// creating the only instance of class

    void fire();

//    void hitChicken();
signals:


};




#endif // SPACESHIP_H
