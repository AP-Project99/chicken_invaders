#ifndef HEART_H
#define HEART_H

#include <QObject>
#include <QGraphicsTextItem>

class Heart : public QGraphicsTextItem
{
    Q_OBJECT
private:

    static int heartPlayer;

public:
    QGraphicsTextItem *txt ;

    explicit Heart(QGraphicsScene *scene);

    static void decrease();

signals:

};

#endif // HEART_H
