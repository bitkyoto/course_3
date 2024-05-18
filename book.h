#ifndef BOOK_H
#define BOOK_H
#include <qcolor.h>
#include <QRect>
class Book
{
public:
    Book(int w, QColor c, int id);
    int getW();
    QColor getColor();
    int getId() const;
    void setPos(const QRect&);
    QRect getPos();
    Book();
    Book& operator=(const Book& other);
    Book(const Book&);
private:
    int l = 50;
    int h = 80;
    QRect pos;
    int w;
    int id;
public:
    QColor color;
};
bool operator==(const Book& lhs, const Book& rhs);

#endif // BOOK_H
