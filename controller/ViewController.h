#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <model/menu/Play.h>
#include <model/menu/Quit.h>
#include <model/Score.h>
#include <model/Heart.h>
#include <model/Chickens.h>
#include "SpaceShipController.h"
#include "ChickenController.h"
#include "model/Gift.h"

class SpaceShipController;
class ChickenController;
class ViewController : public QObject
{
    Q_OBJECT

    friend class View;
    friend class SpaceShipController;
    friend class Heart;

private:
    Play * play;
    Quit * quit;

    SpaceShipController * spaceShipController;
    ChickenController * chickenController;

    QTimer * ctimer;

    Score * score;

    Heart * heart;

    QMediaPlayer *startGameSound;


public:

    explicit ViewController();

    static QGraphicsScene * scene;

    ~ViewController();

    void setBackground(QString);

    void startMenu();

    void addChicken(int );

    void addHeart();

    void addScoreBoard();

    void addGift();

    static void exit();



public slots:
    void startGame();

    void deleteStartGameSound();

signals:

};

#endif // VIEWCONTROLLER_H
