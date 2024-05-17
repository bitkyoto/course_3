#ifndef STACK_H
#define STACK_H
#include <book.h>
class Stack
{
public:
    Stack();
    QVector<Book>& get_books();
    void push_back(const Book &);
private:
    QVector<Book> books;
};

#endif // STACK_H
