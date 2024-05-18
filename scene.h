#ifndef SCENE_H
#define SCENE_H
#include <stack.h>
#include <bookcase.h>
#include <QPainter>
class Scene
{
    // friend class MainWindow;
    // friend class EventHandler;
    // friend class SceneInterface;
    // friend class User;
private:
    Stack s1;
    Stack s2;
    Stack s3;
    Stack s4;
    Bookcase bc;
    QVector<Book> all_books;


public:
    Scene();
    QPair<Book*,int> selected_book = QPair<Book*,int>(nullptr,-1);
    Book* book_to_read = nullptr;
    double sum_width = 0;
    int current_book_id = 0;
    Book book_to_move;
    Stack& get_s1();
    Stack& get_s2();
    Stack& get_s3();
    Stack& get_s4();
    Bookcase& get_bc();
    QVector<Book>& get_all_books();

};

#endif // SCENE_H
