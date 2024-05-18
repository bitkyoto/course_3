#include "user.h"

User::User() {}
void User::add_book_to_bookcase(QMouseEvent* e, Scene& scene, EventHandler *ev)
{
    ev->add_book_to_bookcase_handler(e,scene);
}

void User::move_book(QMouseEvent *e, Scene& scene, EventHandler *ev)
{
    ev->move_book_handler(e,scene);
}

void User::read_book(QMouseEvent *e, Scene& scene, EventHandler *ev)
{
    ev->read_book_handler(e,scene);
}


