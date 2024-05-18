#include "sceneinterface.h"

SceneInterface::SceneInterface(QWidget *parent, Scene *s):QWidget(parent) {
    scene = s;
}

void SceneInterface::paintStacks(QPainter *painter)
{
    QRect stack1 = QRect(QPoint(100,600+100),QPoint(150, 580+100));
    QRect stack2 = QRect(QPoint(200,600+100),QPoint(250, 580+100));
    QRect stack3 = QRect(QPoint(300,600+100),QPoint(350, 580+100));
    QRect stack4 = QRect(QPoint(400,600+100),QPoint(450, 580+100));
    painter->drawRect(QRect(QPoint(50,20),QPoint(700,750)));
    painter->drawRect(stack1);
    painter->drawText(stack1,QString::fromStdString("Стопка 1"),QTextOption(Qt::AlignCenter));
    painter->drawRect(stack2);
    painter->drawText(stack2,QString::fromStdString("Стопка 2"),QTextOption(Qt::AlignCenter));
    painter->drawRect(stack3);
    painter->drawText(stack3, QString::fromStdString("Стопка 3"),QTextOption(Qt::AlignCenter));
    painter->drawRect(stack4);
    painter->drawText(stack4, QString::fromStdString("Доп стопка"),QTextOption(Qt::AlignCenter));

    QPoint stack1_x2y2 = QPoint(150,580+100);
    QPoint stack2_x2y2 = QPoint(250,580+100);
    QPoint stack3_x2y2 = QPoint(350,580+100);
    QPoint stack4_x2y2 = QPoint(450,580+100);
    int s1_current = stack1_x2y2.y() - 1;
    int s2_current = stack2_x2y2.y() - 1;
    int s3_current = stack3_x2y2.y() - 1;
    int s4_current = stack4_x2y2.y() - 1;
    for (auto& b: scene->get_s1().get_books()){
        QRect r(100,s1_current-b.getW(),50,b.getW());
        b.setPos(r);
        painter->drawRect(r);
        painter->fillRect(r,QBrush(b.getColor()));
        painter->drawText(r,QString::fromStdString("Том " + std::to_string(b.getId())),QTextOption(Qt::AlignCenter));
        s1_current = s1_current - b.getW();
    }
    for (auto& b: scene->get_s2().get_books()){
        QRect r(200,s2_current-b.getW(),50,b.getW());
        b.setPos(r);
        painter->drawRect(r);
        painter->fillRect(r,QBrush(b.getColor()));
        painter->drawText(r,QString::fromStdString("Том " + std::to_string(b.getId())),QTextOption(Qt::AlignCenter));
        s2_current = s2_current - b.getW();
    }
    for (auto& b: scene->get_s3().get_books()){
        QRect r(300,s3_current-b.getW(),50,b.getW());
        b.setPos(r);
        painter->drawRect(r);
        painter->fillRect(r,QBrush(b.getColor()));
        painter->drawText(r,QString::fromStdString("Том " + std::to_string(b.getId())),QTextOption(Qt::AlignCenter));
        s3_current = s3_current - b.getW();
    }
    for (auto& b: scene->get_s4().get_books()){
        QRect r(400,s4_current-b.getW(),50,b.getW());
        b.setPos(r);
        painter->drawRect(r);
        painter->fillRect(r,QBrush(b.getColor()));
        painter->drawText(r,QString::fromStdString("Том " + std::to_string(b.getId())),QTextOption(Qt::AlignCenter));
        s4_current = s4_current - b.getW();
    }
}

void SceneInterface::paintBookShelf(QPainter *painter)
{
    QPen bookcase_pen;
    QRect bookcase_rect = QRect(QPoint(500,601), QPoint(500+scene->sum_width*1.2/4,600-1-320));
    painter->drawRect(bookcase_rect);
    for(int i = 1; i<4;i++){
        painter->drawLine(500,600+1-80*i,500+scene->sum_width*1.2/4, 600+1-80*i);
    }
    for(auto& sh: scene->get_bc().get_all_shelves()){
        QPoint curr = sh.get_base_pos();
        for(auto& b:sh.get_books()){
            if(b.color == Qt::gray){
                curr = QPoint(curr.x()+b.getW(),curr.y());
                continue;
            }
            QRect temp = QRect(curr,QSize(b.getW(),80));
            b.setPos(temp);
            painter->drawRect(temp);
            painter->fillRect(temp,QBrush(b.getColor()));
            painter->drawText(temp,QString::fromStdString(std::to_string(b.getId())),QTextOption(Qt::AlignCenter));
            curr = QPoint(curr.x()+b.getW(),curr.y());
        }
    }
}
