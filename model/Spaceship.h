#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QWidget>


//#include "view/View.h"
#include "Bullet.h"


class SpaceShip : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    explicit SpaceShip();     /// constructor

    static SpaceShip * spaceShip ;         /// the only object of this class
    QList <Bullet *> allBullets;

public:
    static SpaceShip * getInstance();     /// creating the only instance of class

    void keyPressEvent(QKeyEvent * event) ;

    void mousePressEvent(QMouseEvent * event);

//    void mouseMoveEvent(QMouseEvent * event) ;

signals:

};




#endif // SPACESHIP_H
