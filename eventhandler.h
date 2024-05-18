#ifndef EventHandlerInterface_H
#define EventHandlerInterface_H
#include <iostream>
#include <QWidget>
#include <scene.h>
#include <QMouseEvent>
#include <qpushbutton.h>
#include <random>
class EventHandler: public QWidget
{
public:
    EventHandler(QWidget* parent);
    QPushButton* gen;
    Scene* scene;
    void regenerate();
    void add_book_to_bookcase_handler(QMouseEvent *e, Scene &scene);
    void move_book_handler(QMouseEvent* e, Scene& scene);
    void read_book_handler(QMouseEvent* e, Scene& scene);
};

#endif // EventHandlerInterface_H
