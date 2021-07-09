#ifndef HEART_H
#define HEART_H

#include <QObject>
#include <QGraphicsTextItem>

class Heart : public QGraphicsTextItem
{
    Q_OBJECT
private:

    explicit Heart();

    int spaceShipHeart;

    static Heart * heart;

public:
    QGraphicsTextItem *txt ;

    static Heart * getInstance();


    void decrease();

signals:

};

#endif // HEART_H
