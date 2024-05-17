#ifndef SCENEINTERFACE_H
#define SCENEINTERFACE_H
#include <scene.h>
#include <qwidget.h>
class SceneInterface: public QWidget
{
public:
    SceneInterface(QWidget* parent, Scene*);
    Scene* scene;
    void paintStacks(QPainter *painter);
    void paintBookShelf(QPainter *painter);

};

#endif // SCENEINTERFACE_H
