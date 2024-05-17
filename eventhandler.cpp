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
    scene->s1.get_books().clear();
    scene->s2.get_books().clear();
    scene->s3.get_books().clear();
    scene->s4.get_books().clear();
    scene->all_books.clear();
    QVector<QColor> color_table = {QColor::fromRgb(21,52,72), QColor::fromRgb(60,91,111), QColor::fromRgb(148,137,121),QColor::fromRgb(223,208,154)};
    for (int i = 1; i < 31; i++){
        int wid = width_dist(gen);
        int st = stack_dist(gen);
        scene->sum_width += wid;
        Book new_book = Book(wid,color_table[color_dist(gen)],i);
        std::cout << wid << " " << st << " " << color_table[st].name(QColor::HexRgb).toStdString()<<std::endl;
        if (st==0) scene->s1.push_back(new_book);
        if (st==1) scene->s2.push_back(new_book);
        if (st==2) scene->s3.push_back(new_book);
        scene->all_books.push_back(new_book);
    }
    std::cout << (int)(scene->sum_width*1.2/4) << std::endl;
    scene->bc = Bookcase((int)(scene->sum_width*1.2/4),QPoint(500,600-80*4), QPoint(500,600-80*3), QPoint(500,600-80*2), QPoint(500,600-80));
}

