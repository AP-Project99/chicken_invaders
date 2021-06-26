#include <QApplication>
#include <view/view.h>
#include <QWidget>

#include "model/Spaceship.h"
#include "view/View.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    View * view = View::getInstance();
    view->show();

    view->showMenu();


    return a.exec();
}
