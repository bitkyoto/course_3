#ifndef EventHandlerInterface_H
#define EventHandlerInterface_H
#include <iostream>
#include <QWidget>
#include <scene.h>
#include <QMouseEvent>
#include <qpushbutton.h>
#include <random>
class EventHandler:public QWidget
{
    Q_OBJECT
public:
    EventHandler(QWidget* parent);
    QPushButton* gen;
    Scene* scene;
    void regenerate();
};

#endif // EventHandlerInterface_H
