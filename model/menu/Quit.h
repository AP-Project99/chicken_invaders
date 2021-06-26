#ifndef QUIT_H
#define QUIT_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>

class Quit :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Quit();

    void mousePressEvent(QGraphicsSceneMouseEvent *) override;

signals:
    void quitClicked();

};

#endif // QUIT_H
