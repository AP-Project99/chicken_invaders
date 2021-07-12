#include "View.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

View * View::view = nullptr;    /// initializing static member

View::View() : QGraphicsView()
{
    /// set the scene to view
    viewController = new ViewController;
    setScene(ViewController::scene);


    this->setFixedSize(1350,650);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setMouseTracking(true);

}

View::~View()
{
    delete viewController;
    delete view;
}

View *View::getInstance()
{
    if(view == nullptr)
        view = new View;

    return view;
}

void View::showMenu()
{
    viewController->startMenu();
}

void View::mouseMoveEvent(QMouseEvent *event)
{

    if(viewController->spaceShipController->spaceShip){
        viewController->spaceShipController->spaceShip->setPos(event->pos());
        viewController->spaceShipController->hitChicken();
    }
    else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void View::mousePressEvent(QMouseEvent *event)
{

    if(viewController->spaceShipController->spaceShip){
        if(event->button() == Qt::LeftButton)
            viewController->spaceShipController->fire();
    }
    else
        QGraphicsView::mousePressEvent(event);

}

void View::keyPressEvent(QKeyEvent *event)
{

    if(viewController->spaceShipController->spaceShip != nullptr){
        if(event->key() == Qt::Key_Left )
            viewController->spaceShipController->moveSpaceShipLeft();

        if(event->key() == Qt::Key_Right )
            viewController->spaceShipController->moveSpaceShipRight();

        if(event->key() == Qt::Key_Up )
            viewController->spaceShipController->moveSpaceShipUp();

        if(event->key() == Qt::Key_Down )
            viewController->spaceShipController->moveSpaceShipDown();

        if(event->key() == Qt::Key_Space)
            viewController->spaceShipController->fire();
    }
    else {
        QGraphicsView::keyPressEvent(event);
    }
}
