#ifndef SPACESHIPCONTROLLER_H
#define SPACESHIPCONTROLLER_H

#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include "model/Gift.h"
#include "model/Spaceship.h"
#include "model/Bullet.h"
#include "ViewController.h"

class SpaceShip;
class Bullet;
class SpaceShipController : public QObject
{
    Q_OBJECT

    friend class View;
    friend class SpaceShip;

private:
    SpaceShip * spaceShip = nullptr;

    static SpaceShipController * spaceShipController;

    SpaceShipController();

    QTimer * reviveSpaceShipTimer;

    QMediaPlayer * hitSpaceShipSound;

public:
    static SpaceShipController * getInstance ();

    void fire();

    void moveSpaceShipLeft();

    void moveSpaceShipRight();

    void moveSpaceShipUp();

    void moveSpaceShipDown();

    void removeSpaceShip();

    void reviveSpaceShip();

    void hitChicken();

    void soundSpaceShipToChicken();

    void soundSpaceShipToEgg();

    void soundSpaceShipToMeat();


public slots:

    void addSpaceShip();

    void addGift();

    void deleteSound();
};

#endif // SPACESHIPCONTROLLER_H
