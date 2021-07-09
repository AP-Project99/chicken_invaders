#ifndef HEART_H
#define HEART_H

#include <QObject>
#include <QGraphicsTextItem>

class Heart : public QGraphicsTextItem
{
    Q_OBJECT
private:

    int heartPlayer;

public:

    explicit Heart(QGraphicsScene *scene);

    void decrease();

signals:

};

#endif // HEART_H
