#include "bookcase.h"
#include <iostream>
Bookcase::Bookcase(double width, QPoint p1, QPoint p2, QPoint p3, QPoint p4) {
    this->all_shelves.push_back(Shelf(width,p1));
    this->all_shelves.push_back(Shelf(width,p2));
    this->all_shelves.push_back(Shelf(width,p3));
    this->all_shelves.push_back(Shelf(width,p4));
    this->active_shelf = 0;
}

Bookcase::Bookcase(){}

int Bookcase::get_active_shelf()
{
    return this->active_shelf;
}

QVector<Shelf> &Bookcase::get_all_shelves()
{
    return this->all_shelves;
}
void Bookcase::addBook(Book &b)
{
    if(this->all_shelves[active_shelf].get_space_available()-b.getW()>=0){
        this->all_shelves[active_shelf].push_back(b);
        this->all_shelves[active_shelf].get_space_available() -= b.getW();
        std::cout << "Successfully added book on shelf  " << active_shelf << " left " << this->all_shelves[active_shelf].get_space_available() << std::endl;
    }else {
        this->active_shelf++;
        this->all_shelves[active_shelf].push_back(b);
        this->all_shelves[active_shelf].get_space_available() -= b.getW();
        std::cout << "Successfully added book on shelf  " << active_shelf << " left " << this->all_shelves[active_shelf].get_space_available() << std::endl;;
    }
}
