#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>


#include "controller/ViewController.h"

class View : public QGraphicsView
{    

public:
    explicit View();

    static View * view;

    ViewController * viewController ;

    ~View();

    static View * getInstance();

    void showMenu();

//    void mousePressEvent(QGraphicsSceneMouseEvent * event);


//    void keyPressEvent(QKeyEvent * event);





};

#endif // VIEW_H
