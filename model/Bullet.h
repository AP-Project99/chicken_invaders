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

    QMediaPlayer * hitObject = nullptr;

public:
    explicit Bullet();

    ~Bullet();

    void bulletHitChicken();

    void soundBullet();

    void soundBulletToChicken();


public slots:
    void move();

    void deleteThisClass();

signals:

};

#endif // BULLET_H
