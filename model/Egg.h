#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include "model/Hen.h"

class Hen;
class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    QTimer * eggTimer;

    QTimer * delNimroTimer;

    QMediaPlayer *eggSound;

    int eggSeconds = 0;


public:
    explicit Egg(Hen * hen);

    ~Egg();

    bool reachedEnd = false;

    void reachEnd();



public slots:
    void moveDown();

    void removeNimroo();


signals:


};

#endif // EGG_H
