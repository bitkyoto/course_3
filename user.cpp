#include "user.h"

User::User() {}
bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.getId()==rhs.getId();
}
void User::add_book_to_bookcase(QMouseEvent* e, Scene& scene)
{
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();
    int stack_id = -1;
    for(auto& b: scene.s1.get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            scene.book_to_move = b;
            stack_id = 1;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << " in stack" << stack_id << " " << scene.current_book_id<< std::endl;
        }

    }
    for(auto& b: scene.s2.get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            scene.book_to_move = b;
            stack_id = 2;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }

    for(auto& b: scene.s3.get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            scene.book_to_move = b;
            stack_id = 3;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }
    for(auto& b: scene.s4.get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            scene.book_to_move = b;
            stack_id = 4;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }
    if (scene.book_to_move.getId() == scene.current_book_id+1){
        scene.bc.addBook(scene.book_to_move);
        scene.current_book_id++;
        if (stack_id == 1) scene.s1.get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 2) scene.s2.get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 3) scene.s3.get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 4) scene.s4.get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        std::cout << "In order successfully selected tome  " << scene.book_to_move.getId() << std::endl;
        scene.book_to_move = Book();
        scene.selected_book.first = nullptr;
    }
}



void User::move_book(QMouseEvent* e, Scene &scene)
{
    QRect stack1 = QRect(QPoint(100,600),QPoint(150,580));
    QRect stack2 = QRect(QPoint(200,600),QPoint(250,580));
    QRect stack3 = QRect(QPoint(300,600),QPoint(350,580));
    QRect stack4 = QRect(QPoint(400,600),QPoint(450, 580));
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();

    if(e->button()==Qt::RightButton){
        read_book(e,scene);
    }

    for(auto& b: scene.s1.get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            std::cout << "Selected tom: " << b.getId() << " in " << 1 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 1);
        }
    }
    for(auto& b: scene.s2.get_books()){
        if(b.getPos().contains(mouseX,mouseY)){

            std::cout << "Selected tom: " << b.getId() << " in " << 2 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 2);
        }
    }

    for(auto& b: scene.s3.get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            std::cout << "Selected tom: " << b.getId() << " in " << 3 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 3);
        }
    }
    for(auto& b: scene.s4.get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            std::cout << "Selected tom: " << b.getId() << " in " << 4 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 4);
        }
    }



    if (stack1.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 1){
        if (scene.s1.get_books().empty()){
            QRect newpos = stack1;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s1.push_back(*scene.selected_book.first);
            scene.s1.get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.s1.get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s1.push_back(*scene.selected_book.first);
            scene.s1.get_books().back().setPos(newpos);
        }

        if (scene.selected_book.second == 2){
            scene.s2.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.s3.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.s4.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack2.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 2){
        if (scene.s2.get_books().empty()){
            QRect newpos = stack2;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s2.push_back(*scene.selected_book.first);
            scene.s2.get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.s2.get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s2.push_back(*scene.selected_book.first);
            scene.s2.get_books().back().setPos(newpos);
        }
        if (scene.selected_book.second == 1){
            scene.s1.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.s3.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.s4.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack3.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 3){
        if (scene.s3.get_books().empty()){
            QRect newpos = stack3;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s3.push_back(*scene.selected_book.first);
            scene.s3.get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.s3.get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s3.push_back(*scene.selected_book.first);
            scene.s3.get_books().back().setPos(newpos);
        }
        if (scene.selected_book.second == 1){
            scene.s1.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 2){
            scene.s2.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.s4.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack4.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 4){
        if (scene.s4.get_books().empty()){
            QRect newpos = stack4;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s4.push_back(*scene.selected_book.first);
            scene.s4.get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.s4.get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.s4.push_back(*scene.selected_book.first);
            scene.s4.get_books().back().setPos(newpos);
        }

        if (scene.selected_book.second == 1){
            scene.s1.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 2){
            scene.s2.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.s3.get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
}

void User::read_book(QMouseEvent *e, Scene &scene)
{
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();
    if(scene.book_to_read == nullptr){
        for(auto& sh:scene.bc.get_all_shelves()){
            for(auto&b :sh.get_books()){
                if(b.getPos().contains(mouseX,mouseY)){
                    scene.book_to_read = &b;
                    b.color = Qt::gray;
                }
            }
        }
    }else{
        scene.book_to_read->color = scene.all_books[scene.all_books.indexOf(*scene.book_to_read)].color;
        scene.book_to_read = nullptr;
    }
}


