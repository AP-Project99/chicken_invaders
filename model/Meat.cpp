#include "Meat.h"
#include "controller/ViewController.h"

int Meat::meatNumber = 0;

QGraphicsTextItem * Meat::meatNumberText = nullptr;

Meat::Meat(Birds *hen) : QObject() , QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/meat.png"));
    setPos(hen->x() + hen->boundingRect().width()/2 , hen->y() + hen->boundingRect().height());

    moveDownTimer = new QTimer;
    connect(moveDownTimer, SIGNAL(timeout()), this, SLOT(moveDown()));
    moveDownTimer->start(25);


}

Meat::~Meat(){
    delete moveDownTimer;
    scene()->removeItem(this);
}

void Meat::addMeatNumberTextItem()
{

    if(meatNumberText == nullptr){
        meatNumberText = new QGraphicsTextItem;

        meatNumberText->setPlainText(QString::number(meatNumber));
        meatNumberText->setDefaultTextColor(Qt::white);
        meatNumberText->setFont(QFont("segoe script",15));
        meatNumberText->setPos(65,618);

        ViewController::scene->addItem(meatNumberText);
    }

}

void Meat::increase()
{
    meatNumber++;

    if(meatNumber == 30){
        Score::getInstance()->increase(50);
        meatNumber = 0;
    }

    meatNumberText->setPlainText(QString::number(meatNumber));
}

void Meat::moveDown()
{
    if(y() >= 650)
        delete this;

    else
        setPos(x(), y() + 10);


}
