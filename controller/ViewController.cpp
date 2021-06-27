#include "ViewController.h"
#include "view/View.h"
#include <QMediaPlayer>


ViewController::ViewController() : QObject()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1350,650);
}

ViewController::~ViewController()
{
    delete ctimer;
    delete scene;
}

void ViewController::setBackground(QString address){
    scene->setBackgroundBrush(QBrush(QImage(address)));
}

void ViewController::startGame()
{
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/gamebackground.jpg")));
    scene->addItem(SpaceShip::getInstance());

    //set score board
    Score *cScore =new Score(scene);
    scene->addItem(cScore);
    cScore->setPos(10,-5);

    //set heart on background
    Heart *cHeart=new Heart(scene);
    scene->addItem(cHeart);
    cHeart->setPos(20,628);
}

void ViewController::close()
{

}

void ViewController::startMenu()
{
    setBackground(":/images/bck.jpg");

    play = new Play();
    quit = new Quit();

    scene->addItem(play);
    scene->addItem(quit);

    connect(play , SIGNAL(clicked()), this, SLOT(startGame()));
    connect(quit , SIGNAL(quitClicked()), View::getInstance(), SLOT(close()));
}

