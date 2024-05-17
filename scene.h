#ifndef SCENE_H
#define SCENE_H
#include <stack.h>
#include <bookcase.h>
#include <QPainter>
class Scene
{
    friend class MainWindow;
    friend class EventHandler;
    friend class SceneInterface;
    friend class User;
private:
    Scene();
    Stack s1;
    Stack s2;
    Stack s3;
    Stack s4;
    Bookcase bc;
    QPair<Book*,int> selected_book = QPair<Book*,int>(nullptr,-1);
    double sum_width = 0;
    QVector<Book> all_books;
    Book book_to_move;
    int current_book_id = 0;
    Book* book_to_read = nullptr;
};

#endif // SCENE_H
