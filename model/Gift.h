#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Gift : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    QTimer * goDownTimer;

public:
    explicit Gift();


signals:

public slots:

    void moveDown();
};

#endif // GIFT_H
