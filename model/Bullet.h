#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

#include "controller/ChickenController.h"

class ChickenController;
class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * bulletTimer = new QTimer;

    ChickenController * chickenController;

public:
    explicit Bullet();

    void bulletHitChicken();

signals:

public slots:
    void move();

};

#endif // BULLET_H
