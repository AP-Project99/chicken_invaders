#ifndef BIRDS_H
#define BIRDS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


class Birds : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

protected:

    QTimer * chickenTimer;
    QTimer * moveTimer;

    bool goingLeft = true;

    int limitLeft;
    int limitRight;
    int limitDown;

    int imageTimer = 0;



public:
    explicit Birds(int number, int season, int level);

    static int totalAnimals;

    int lives;

    QString type;

    void moveBirds();

    virtual void setImage() = 0;


    void setChickenPos11(int number);

    void setChickenPos12(int number);

    void setChickenPos21(int number);

    void setChickenPos22(int number);

    void setChickenPos31(int number);

    void setChickenPos32(int number);


public slots:
    void incrementChickenTimer();

    void moveDown();


signals:

};

#endif // BIRDS_H
