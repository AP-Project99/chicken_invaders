#include "view.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

View * View::view = nullptr;    /// initializing static member

View::View() : QGraphicsView()
{
    /// set the scene to view
    viewController = new ViewController;
    setScene(viewController->scene);

//    this->setFixedSize(1352,663);
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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

    if(viewController->spaceShip)
        viewController->spaceShip->setPos(event->pos());

    else {
        QGraphicsView::mouseMoveEvent(event);
    }
}
void View::mousePressEvent(QMouseEvent *event)
{

    if(viewController->spaceShip){

        if(event->button() == Qt::LeftButton)
            viewController->fire();
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

void View::keyPressEvent(QKeyEvent *event)
{

    if(viewController->spaceShip != nullptr){
        if(event->key() == Qt::Key_Left )
            viewController->moveSpaceShipLeft();

        if(event->key() == Qt::Key_Right )
            viewController->moveSpaceShipRight();

        if(event->key() == Qt::Key_Up )
            viewController->moveSpaceShipUp();

        if(event->key() == Qt::Key_Down )
            viewController->moveSpaceShipDown();

        if(event->key() == Qt::Key_Space)
            viewController->fire();
    }
    else {
        QGraphicsView::keyPressEvent(event);
    }
}
