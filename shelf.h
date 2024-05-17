#ifndef SHELF_H
#define SHELF_H
#include <book.h>
class Shelf
{
public:
    Shelf(int space, QPoint);
    void push_back(const Book& b);
    QVector<Book>& get_books();
    QPoint get_base_pos();
    int &get_space_available();
    void set_space_available(int);
private:
    QVector<Book> books;
    QPoint base_pos;
    int space_available;
};

#endif // SHELF_H
