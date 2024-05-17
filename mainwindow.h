#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <stack.h>
#include <QMainWindow>
#include <qpainter.h>
#include <qpair.h>
#include <bookcase.h>
#include <QPushButton>
#include <scene.h>
#include <EventHandler.h>
#include <QPainter>
#include <sceneinterface.h>
#include <QLayout>
#include <user.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    Scene scene;
    SceneInterface* sc_inter;
    EventHandler* ev;
    User user;
public slots:
    void regen();
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
