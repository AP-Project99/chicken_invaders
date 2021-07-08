#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>

class Score: public QGraphicsTextItem
{
    Q_OBJECT
private:
    int playerScore;
public:
    explicit Score(QGraphicsScene *scene);

    void increase();

signals:

};

#endif // SCORE_H
