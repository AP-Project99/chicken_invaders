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
    explicit Score(int score,QGraphicsScene *scene);

    int getPlayerScore() const;
    void setPlayerScore(int newPlayerScore);

signals:

};

#endif // SCORE_H
