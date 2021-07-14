#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


#include "Birds.h"
#include "Score.h"

class Meat : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    static QGraphicsTextItem * meatNumberText;

    QTimer * moveDownTimer;


public:
    explicit Meat(Birds *);

    ~Meat();

    static int meatNumber;

    static void addMeatNumberTextItem();


    void increase();




public slots:
    void moveDown();

signals:

};

#endif // MEAT_H
