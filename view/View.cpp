#include "view.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

View * View::view = nullptr;    /// initializing static member

View::View() : QGraphicsView()
{
    /// set the scene to view
    viewController = new ViewController;
    setScene(viewController->scene);

    this->setFixedSize(1352,663);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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

//void View::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{

//}

//void View::keyPressEvent(QKeyEvent *event)
//{

//}
