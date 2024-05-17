#ifndef USER_H
#define USER_H
#include <book.h>
#include <Qpair>
#include <scene.h>
#include "QMouseEvent"
#include <iostream>

class User
{
public:
    User();
    void add_book_to_bookcase(QMouseEvent *e, Scene &scene);
    void move_book(QMouseEvent* e, Scene& scene);
    void read_book(QMouseEvent* e, Scene& scene);
};

#endif // USER_H
