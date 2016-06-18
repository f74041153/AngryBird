#ifndef BLOCK
#define BLOCK

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


class Block : public GameItem
{
public:
    Block(float x, float y,float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void collide();

};


#endif // BLOCK

