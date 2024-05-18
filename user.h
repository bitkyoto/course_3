#ifndef USER_H
#define USER_H
#include <book.h>
#include <Qpair>
#include <scene.h>
#include "QMouseEvent"
#include <iostream>
#include <eventhandler.h>
class User
{
public:
    User();
    void add_book_to_bookcase(QMouseEvent *e, Scene& scene, EventHandler* ev);
    void move_book(QMouseEvent* e, Scene &scene, EventHandler* ev);
    void read_book(QMouseEvent* e, Scene &scene, EventHandler* ev);
};

#endif // USER_H
