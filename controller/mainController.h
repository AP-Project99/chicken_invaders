#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:

};

#endif // MAINCONTROLLER_H
