#include "Quit.h"

Quit::Quit() :QObject(), QGraphicsPixmapItem()

{
    setPixmap(QPixmap(":/images/quit.png"));
    setPos(510 , 500);

}

void Quit::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit quitClicked();
}
