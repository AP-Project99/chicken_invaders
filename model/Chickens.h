#ifndef CHICKENS_H
#define CHICKENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Chickens : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * chickenTimer;
    QTimer * moveTimer;

    bool goingLeft = true;

    int imageTimer = 0;

public:

    explicit Chickens();

    void setImage();


signals:

public slots:
    void incrementChickenTimer();

    void moveChicken();


};

#endif // CHICKENS_H
