#include "book.h"
#include <iostream>

Book::Book(int width, QColor c, int _id): w(width), color(c), id(_id){}

int Book::getW()
{
    return this->w;
}

QColor Book::getColor()
{
    return this->color;
}

int Book::getId() const
{
    return this->id;
}

void Book::setPos(const QRect& r)
{
    this->pos = r;
}

QRect Book::getPos()
{
    return this->pos;
}

Book::Book()
{
    this->w = 0;
    this->id = -1;
    this->color= Qt::white;
    this->pos = QRect(0,0,0,0);
}

Book &Book::operator=(const Book &other)
{
    this->w = other.w;
    this->id = other.id;
    this->color = other.color;
    this->pos = other.pos;
    return *this;
}


Book::Book(const Book & other)
{
    this->w = other.w;
    this->id = other.id;
    this->color = other.color;
    this->pos = other.pos;
}
