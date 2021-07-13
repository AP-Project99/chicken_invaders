#ifndef SUPERCHICKEN_H
#define SUPERCHICKEN_H

#include <QObject>

#include "Birds.h"
#include "Egg.h"
#include <QVector>

class Egg;
class SuperChicken : public Birds
{

private:


public:
    explicit SuperChicken(int number, int season, int level);

    ~SuperChicken();

    static int superChickenNumbers;

     QList <Egg *> eggs;


    void setImage() override;

signals:

};

#endif // SUPERCHICKEN_H
