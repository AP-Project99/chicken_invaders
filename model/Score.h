#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>

class Score: public QGraphicsTextItem
{
    Q_OBJECT
private:
    explicit Score();

    static Score * score;

    int playerScore;

    QGraphicsPixmapItem * scoreBoard;

public:

    ~Score();

    static Score * getInstance();

    void increase(int scr);

signals:

};

#endif // SCORE_H
