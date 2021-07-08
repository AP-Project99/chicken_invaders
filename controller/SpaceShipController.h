#ifndef SPACESHIPCONTROLLER_H
#define SPACESHIPCONTROLLER_H

#include <QObject>
#include "model/Spaceship.h"
#include "ViewController.h"

class SpaceShip;
class SpaceShipController : public QObject
{
    Q_OBJECT

    friend class View;

private:
    SpaceShip * spaceShip=nullptr;

    static SpaceShipController * spaceShipController;

    SpaceShipController();

public:
    static SpaceShipController * getInstance ();

    void addSpaceShip();

    void fire();

    void moveSpaceShipLeft();

    void moveSpaceShipRight();

    void moveSpaceShipUp();

    void moveSpaceShipDown();
};

#endif // SPACESHIPCONTROLLER_H
