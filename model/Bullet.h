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

    ChickenController * chickenController;


    QTimer * bulletTimer;

    QMediaPlayer *bulletSound;

public:
    explicit Bullet();

    ~Bullet();

    void bulletHitChicken();

signals:

public slots:
    void move();

};

#endif // BULLET_H
