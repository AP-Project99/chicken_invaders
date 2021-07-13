#ifndef SUPERCHICKEN_H
#define SUPERCHICKEN_H

#include <QObject>

#include "Hen.h"
#include "Egg.h"
#include <QVector>

class Egg;
class SuperChicken : public Hen
{

private:


public:
    explicit SuperChicken(int number, int season, int level);

    ~SuperChicken();

    void setImage() override;

signals:

};

#endif // SUPERCHICKEN_H
