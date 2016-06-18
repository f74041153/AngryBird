#ifndef BIRD_FOUR
#define BIRD_FOUR

#include"bird.h"
class Bird_four : public Bird
{
    Q_OBJECT;
public:
    Bird_four(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~Bird_four(){}
    void key();

};

#endif // BIRD_FOUR

