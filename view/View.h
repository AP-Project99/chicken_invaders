#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QObject>

#include "controller/ViewController.h"
#include "controller/SpaceShipController.h"

class View : public QGraphicsView
{    

public:
    explicit View();

    static View * view;

    ViewController * viewController = nullptr;


    ~View();

    static View * getInstance();

    void showMenu();

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void keyPressEvent(QKeyEvent * event) override;





};

#endif // VIEW_H
