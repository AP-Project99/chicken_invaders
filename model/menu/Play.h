#ifndef PLAY_H
#define PLAY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QObject>

class Play : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


public:
    Play();

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

signals:
    void clicked();

};

#endif // PLAY_H
