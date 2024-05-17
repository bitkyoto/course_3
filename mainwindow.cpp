#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include <qlayout.h>
#include <EventHandler.h>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(1024,900);
    this->setMouseTracking(true);
    ev = new EventHandler(this);
    this->layout()->addWidget(ev);
    ev->show();
    connect(ev->gen,&QPushButton::pressed,this,&MainWindow::regen);
    sc_inter = new SceneInterface(this,&scene);
    this->layout()->addWidget(sc_inter);
    ev->scene = &this->scene;
    ev->regenerate();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sc_inter;
}

void MainWindow::regen()
{
    ev->regenerate();
    repaint();
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    user.move_book(e,scene);
    repaint();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    user.add_book_to_bookcase(e,scene);
    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    sc_inter->paintBookShelf(&painter);
    sc_inter->paintStacks(&painter);
}
