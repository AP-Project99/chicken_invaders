#ifndef HEART_H
#define HEART_H

#include <QObject>
#include <QGraphicsTextItem>

class Heart : public QGraphicsTextItem
{
    Q_OBJECT
private:
    int heart;
public:
    explicit Heart(QGraphicsScene *scene);

signals:

};

#endif // HEART_H
