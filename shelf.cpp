#include "shelf.h"

Shelf::Shelf(int space, QPoint pos): space_available(space), base_pos(pos){}

void Shelf::push_back(const Book &b)
{
    this->books.push_back(b);
}

QVector<Book> &Shelf::get_books()
{
    return this->books;
}

QPoint Shelf::get_base_pos()
{
    return this->base_pos;
}

int& Shelf::get_space_available()
{
    return this->space_available;
}

void Shelf::set_space_available(int sp)
{
    this->space_available = sp;
}
