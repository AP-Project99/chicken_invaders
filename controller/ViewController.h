#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <model/Spaceship.h>
#include <model/menu/Play.h>
#include <model/menu/Quit.h>
#include <model/Score.h>
#include <model/Heart.h>
#include <model/Chickens.h>



class ViewController : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class View;

private:
    Play * play;
    Quit * quit;
    Chickens * chick;
    SpaceShip * spaceShip = nullptr;

    QGraphicsScene * scene;
    QTimer * ctimer;

public:
    explicit ViewController();

    ~ViewController();

    void setBackground(QString);

    void startMenu();

    void fire();

    void moveSpaceShipLeft();

    void moveSpaceShipRight();

    void moveSpaceShipUp();

    void moveSpaceShipDown();

public slots:
    void startGame();


signals:

};

#endif // VIEWCONTROLLER_H
