#include "ViewController.h"
#include "view/View.h"
#include <QMediaPlayer>
#include <QList>

QGraphicsScene * ViewController::scene = nullptr;

ViewController::ViewController() : QObject()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1350,650);

    /// space ship controller
    spaceShipController = SpaceShipController::getInstance();
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
    /// deleting objects and scene
    delete play;
    delete quit;
    scene->clear();

    /// new image for background
    scene->setBackgroundBrush(QBrush(QImage(":/images/gamebackground.jpg")));

    ////Creating and adding items to the scene
    spaceShipController->addSpaceShip();

    addScoreBoard();

    addHeart();

    addChicken();
}

void ViewController::startMenu()
{
    setBackground(":/images/bck.jpg");

    play = new Play();
    quit = new Quit();

    scene->addItem(play);
    scene->addItem(quit);

    connect(play , SIGNAL(clicked()), this, SLOT(startGame()));   // if clicked at save the world the startgame func will execute.
    connect(quit , SIGNAL(quitClicked()), View::getInstance(), SLOT(close()));     // if clicked at quit the view will get closed.
}

/// Items crated and added to scene
void ViewController::addChicken(){
    score->setPlayerScore(score->getPlayerScore()-5);

    for (int i = 1; i <= 20 ; ++i ) {
        chickens.push_back(new Chickens(i,score));
        scene->addItem(chickens[i-1]);
    }
}

void ViewController::addHeart()
{
    heart = new Heart(scene);
    scene->addItem(heart);
    heart->setPos(20,620);
}

void ViewController::addScoreBoard()
{
    score = new Score(0,scene);
    scene->addItem(score);
}






