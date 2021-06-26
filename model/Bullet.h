#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * bulletTimer = new QTimer;

public:
    explicit Bullet(QGraphicsScene * scene);

signals:
public slots:
    void move();

};

#endif // BULLET_H
