#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


#define BIRD_DENSITY 12.0f
#define BIRD_FRICTION 8.0f
#define BIRD_RESTITUTION 0.1f

class Bird : public GameItem
{
    Q_OBJECT;
public:
    Bird(b2World *world);
    virtual~Bird(){};
    virtual void key(){};
};

#endif // BIRD_H
