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


class SpaceShipController;
class ViewController : public QObject
{
    Q_OBJECT

    friend class View;
    friend class SpaceShipController;

private:
    Play * play;
    Quit * quit;

    Chickens * chick;
    QList<Chickens *> chickens;

    SpaceShipController * spaceShipController;

    static QGraphicsScene * scene;
    QTimer * ctimer;

    Score * score;
    Heart *heart;

public:

    explicit ViewController();

    ~ViewController();

    void setBackground(QString);

    void startMenu();

    void addChicken();

    void addHeart();

    void addScoreBoard();


public slots:
    void startGame();


signals:

};

#endif // VIEWCONTROLLER_H
