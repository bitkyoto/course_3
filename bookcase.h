#ifndef BOOKCASE_H
#define BOOKCASE_H
#include <shelf.h>
class Bookcase
{
public:
    Bookcase(double width, QPoint p1, QPoint p2, QPoint p3, QPoint p4);
    Bookcase();
    int get_active_shelf();
    QVector<Shelf>& get_all_shelves();
    void addBook(Book& b);
private:
    int active_shelf = 0;
    QVector<Shelf> all_shelves;
};

#endif // BOOKCASE_H
