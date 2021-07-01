#include "ViewController.h"
#include "view/View.h"
#include <QMediaPlayer>
#include <QList>

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
    /// deleting objects
    delete play;
    delete quit;
    scene->clear();

    /// new window and items
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

    // add chicken
    QList<Chickens *> chick;
    for (int i=1;i<=20 ;++i ) {
        chick.push_back(new Chickens(i));
        scene->addItem(chick[i-1]);
    }
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

