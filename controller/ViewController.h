#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <model/Spaceship.h>
#include <model/menu/Play.h>
#include <model/menu/Quit.h>


class ViewController : public QObject
{
    Q_OBJECT

    friend class View;

private:
    Play * play;
    Quit * quit;

    QGraphicsScene * scene;
    QTimer * ctimer;


public:
    explicit ViewController();

    ~ViewController();

    void setBackground(QString);

    void startMenu();

public slots:
    void startGame();

    void close();


signals:

};

#endif // VIEWCONTROLLER_H
