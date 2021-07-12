#include "ViewController.h"
#include "view/View.h"
#include <QMediaPlayer>
#include <QList>

QGraphicsScene * ViewController::scene = nullptr;

ViewController::ViewController() : QObject()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1350,650);

    /// create spaceShip controller
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

    /// create chicken controller
    chickenController = ChickenController::getInstance();

    ////Creating and adding items to the scene
    spaceShipController->addSpaceShip();


    chickenController->timerAddChicken(1, 1);   // season 1 - level 1

    chickenController->addEggTimer();

    addScoreBoard();

    addHeart();

}

void ViewController::exit()
{
    QTimer * exitTimer = new QTimer();
    exitTimer->setSingleShot(true);
    connect( exitTimer, SIGNAL(timeout()), View::getInstance(), SLOT(close()));
    exitTimer->start(1900);

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



void ViewController::addHeart()
{
    heart = Heart::getInstance();
    scene->addItem(heart);
}

void ViewController::addScoreBoard()
{
    score = Score::getInstance();
    scene->addItem(score);
}







