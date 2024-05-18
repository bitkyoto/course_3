#include "EventHandler.h"
EventHandler::EventHandler(QWidget* parent): QWidget(parent){
    gen = new QPushButton(QString::fromStdString("Generate new scene"),parent);
    gen->setGeometry(QRect(QPoint(800,350),QSize(150,100)));
}

void EventHandler::regenerate()
{
    scene->current_book_id = 0;
    scene->sum_width = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> width_dist(15, 25);
    std::uniform_int_distribution<> stack_dist(0,2);
    std::uniform_int_distribution<> color_dist(0,3);
    scene->get_s1().get_books().clear();
    scene->get_s2().get_books().clear();
    scene->get_s3().get_books().clear();
    scene->get_s4().get_books().clear();
    scene->get_all_books().clear();
    QVector<QColor> color_table = {QColor::fromRgb(21,52,72), QColor::fromRgb(60,91,111), QColor::fromRgb(148,137,121),QColor::fromRgb(223,208,154)};
    for (int i = 1; i < 31; i++){
        int wid = width_dist(gen);
        int st = stack_dist(gen);
        scene->sum_width += wid;
        Book new_book = Book(wid,color_table[color_dist(gen)],i);
        std::cout << wid << " " << st << " " << color_table[st].name(QColor::HexRgb).toStdString()<<std::endl;
        if (st==0) scene->get_s1().push_back(new_book);
        if (st==1) scene->get_s2().push_back(new_book);
        if (st==2) scene->get_s3().push_back(new_book);
        scene->get_all_books().push_back(new_book);
    }
    std::cout << (int)(scene->sum_width*1.2/4) << std::endl;
    scene->get_bc() = Bookcase((int)(scene->sum_width*1.2/4),QPoint(500,600-80*4), QPoint(500,600-80*3), QPoint(500,600-80*2), QPoint(500,600-80));
}

void EventHandler::add_book_to_bookcase_handler(QMouseEvent* e, Scene& scene)
{
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();
    int stack_id = -1;
    for(auto& b: scene.get_s1().get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            scene.book_to_move = b;
            stack_id = 1;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << " in stack" << stack_id << " " << scene.current_book_id<< std::endl;
        }

    }
    for(auto& b: scene.get_s2().get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            scene.book_to_move = b;
            stack_id = 2;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }

    for(auto& b: scene.get_s3().get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            scene.book_to_move = b;
            stack_id = 3;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }
    for(auto& b: scene.get_s4().get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            scene.book_to_move = b;
            stack_id = 4;
            std::cout << "add_book_to_bookcase " << b.getId() << " " << stack_id << std::endl;
        }
    }
    if (scene.book_to_move.getId() == scene.current_book_id+1){
        scene.get_bc().addBook(scene.book_to_move);
        scene.current_book_id++;
        if (stack_id == 1) scene.get_s1().get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 2) scene.get_s2().get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 3) scene.get_s3().get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        if (stack_id == 4) scene.get_s4().get_books().removeIf([scene](Book other){return other.getId() == scene.book_to_move.getId();});
        std::cout << "In order successfully selected tome  " << scene.book_to_move.getId() << std::endl;
        scene.book_to_move = Book();
        scene.selected_book.first = nullptr;
    }
}



void EventHandler::move_book_handler(QMouseEvent* e, Scene &scene)
{
    QRect stack1 = QRect(QPoint(100,600+100),QPoint(150, 580+100));
    QRect stack2 = QRect(QPoint(200,600+100),QPoint(250, 580+100));
    QRect stack3 = QRect(QPoint(300,600+100),QPoint(350, 580+100));
    QRect stack4 = QRect(QPoint(400,600+100),QPoint(450, 580+100));
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();

    if(e->button()==Qt::RightButton){
        read_book_handler(e,scene);
    }

    for(auto& b: scene.get_s1().get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            std::cout << "Selected tom: " << b.getId() << " in " << 1 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 1);
        }
    }
    for(auto& b: scene.get_s2().get_books()){
        if(b.getPos().contains(mouseX,mouseY)){

            std::cout << "Selected tom: " << b.getId() << " in " << 2 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 2);
        }
    }

    for(auto& b: scene.get_s3().get_books()){
        if(b.getPos().contains(mouseX,mouseY)==true){
            std::cout << "Selected tom: " << b.getId() << " in " << 3 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 3);
        }
    }
    for(auto& b: scene.get_s4().get_books()){
        if(b.getPos().contains(mouseX,mouseY)){
            std::cout << "Selected tom: " << b.getId() << " in " << 4 << " stack" << std::endl;
            scene.selected_book = QPair<Book*,int>(&b, 4);
        }
    }



    if (stack1.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 1){
        if (scene.get_s1().get_books().empty()){
            QRect newpos = stack1;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s1().push_back(*scene.selected_book.first);
            scene.get_s1().get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.get_s1().get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s1().push_back(*scene.selected_book.first);
            scene.get_s1().get_books().back().setPos(newpos);
        }

        if (scene.selected_book.second == 2){
            scene.get_s2().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.get_s3().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.get_s4().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack2.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 2){
        if (scene.get_s2().get_books().empty()){
            QRect newpos = stack2;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s2().push_back(*scene.selected_book.first);
            scene.get_s2().get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.get_s2().get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s2().push_back(*scene.selected_book.first);
            scene.get_s2().get_books().back().setPos(newpos);
        }
        if (scene.selected_book.second == 1){
            scene.get_s1().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.get_s3().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.get_s4().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack3.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 3){
        if (scene.get_s3().get_books().empty()){
            QRect newpos = stack3;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s3().push_back(*scene.selected_book.first);
            scene.get_s3().get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.get_s3().get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s3().push_back(*scene.selected_book.first);
            scene.get_s3().get_books().back().setPos(newpos);
        }
        if (scene.selected_book.second == 1){
            scene.get_s1().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 2){
            scene.get_s2().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 4){
            scene.get_s4().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
    if (stack4.contains(mouseX,mouseY) && scene.selected_book.first != nullptr && scene.selected_book.second != 4){
        if (scene.get_s4().get_books().empty()){
            QRect newpos = stack4;
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s4().push_back(*scene.selected_book.first);
            scene.get_s4().get_books().back().setPos(newpos);
        }else{
            QRect newpos = scene.get_s4().get_books().back().getPos();
            newpos.translate(0,-scene.selected_book.first->getW());
            scene.get_s4().push_back(*scene.selected_book.first);
            scene.get_s4().get_books().back().setPos(newpos);
        }

        if (scene.selected_book.second == 1){
            scene.get_s1().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 2){
            scene.get_s2().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        if (scene.selected_book.second == 3){
            scene.get_s3().get_books().removeIf([scene](Book b){return b.getId() == scene.selected_book.first->getId();});
        }
        scene.selected_book = QPair<Book*,int>(nullptr,-1);
    }
}

void EventHandler::read_book_handler(QMouseEvent *e, Scene &scene)
{
    int mouseX = e->pos().x();
    int mouseY = e->pos().y();
    if(scene.book_to_read == nullptr){
        for(auto& sh:scene.get_bc().get_all_shelves()){
            for(auto&b :sh.get_books()){
                if(b.getPos().contains(mouseX,mouseY)){
                    scene.book_to_read = &b;
                    b.color = Qt::gray;
                }
            }
        }
    }else{
        scene.book_to_read->color = scene.get_all_books()[scene.get_all_books().indexOf(*scene.book_to_read)].color;
        scene.book_to_read = nullptr;
    }
}


