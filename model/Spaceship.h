#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

#include "controller/SpaceShipController.h"
#include "Heart.h"

class SpaceShip : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class SpaceShipController;

private:
    explicit SpaceShip();                  /// private constructor

    static SpaceShip * spaceShip;         /// the only object of this class

    Heart * spaceShipHeart;

public:
    static SpaceShip * getInstance();     /// creating the only instance of class

    void fire();


signals:


};




#endif // SPACESHIP_H
