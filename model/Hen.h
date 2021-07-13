#ifndef HEN_H
#define HEN_H

#include <QObject>

#include "Birds.h"
#include "Egg.h"
#include <QVector>

class Egg;
class Hen : public Birds
{

private:


public:
    explicit Hen(int number, int season, int level);

    ~Hen();

    static int henNumbers;


    void setImage() override;

signals:

};

#endif // HEN_H
