#ifndef SUPERHEN_H
#define SUPERHEN_H

#include <QObject>

#include "Hen.h"
#include "Egg.h"
#include <QVector>

class Egg;
class SuperHen : public Hen
{

private:


public:
    explicit SuperHen(int number, int season, int level);

    ~SuperHen();

    void setImage() override;

signals:

};

#endif // SUPERHEN_H
