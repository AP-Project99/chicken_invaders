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
    friend class SpaceShip;

private:
    SpaceShip * spaceShip = nullptr;

    static SpaceShipController * spaceShipController;

    SpaceShipController();

public:
    static SpaceShipController * getInstance ();

    void fire();

    void moveSpaceShipLeft();

    void moveSpaceShipRight();

    void moveSpaceShipUp();

    void moveSpaceShipDown();

    void removeSpaceShip();

    void hitChicken();

public slots:

    void addSpaceShip();


};

#endif // SPACESHIPCONTROLLER_H
