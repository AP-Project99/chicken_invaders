#ifndef CHICKENS_H
#define CHICKENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "Birds.h"
#include "Heart.h"

class Chickens : public Birds
{


private:


public:

    explicit Chickens(int number, int season, int level);

    void setImage() override;


public slots:


signals:



};

#endif // CHICKENS_H
