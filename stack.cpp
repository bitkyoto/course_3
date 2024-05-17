#include "stack.h"

Stack::Stack() {}

void Stack::push_back(const Book &b)
{
    this->books.push_back(b);
}

QVector<Book>& Stack::get_books()
{
    return this->books;
}
