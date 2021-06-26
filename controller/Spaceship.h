#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>

class SpaceShip : public QObject
{
    Q_OBJECT
public:
    explicit SpaceShip(QObject *parent = nullptr);

signals:

};

#endif // SPACESHIP_H
