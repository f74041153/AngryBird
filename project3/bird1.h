#ifndef BIRD1
#define BIRD1

#include "bird.h"
#include<QKeyEvent>

class Bird1 : public Bird
{
    Q_OBJECT;
public:
    Bird1(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    void keyPressEvent(QKeyEvent*event);
};


#endif // BIRD1

