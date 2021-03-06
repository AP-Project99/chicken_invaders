QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/ChickenController.cpp \
    controller/SpaceShipController.cpp \
    controller/ViewController.cpp \
    controller/controller.cpp \
    main.cpp \
    model/Birds.cpp \
    model/Bullet.cpp \
    model/Chickens.cpp \
    model/Egg.cpp \
    model/Gift.cpp \
    model/Heart.cpp \
    model/Hen.cpp \
    model/Meat.cpp \
    model/Score.cpp \
    model/Spaceship.cpp \
    model/SuperHen.cpp \
    model/menu/Play.cpp \
    model/menu/Quit.cpp \
    model/menu/Resume.cpp \
    model/model.cpp \
    view/View.cpp

HEADERS += \
    controller/ChickenController.h \
    controller/SpaceShipController.h \
    controller/ViewController.h \
    controller/controller.h \
    model/Birds.h \
    model/Bullet.h \
    model/Chickens.h \
    model/Egg.h \
    model/Gift.h \
    model/Heart.h \
    model/Hen.h \
    model/Meat.h \
    model/Score.h \
    model/Spaceship.h \
    model/SuperHen.h \
    model/menu/Play.h \
    model/menu/Quit.h \
    model/menu/Resume.h \
    model/model.h \
    view/View.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
