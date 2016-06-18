#ifndef BIRD_TWO
#define BIRD_TWO

#include"bird.h"
class Bird_two : public Bird
{
    Q_OBJECT;
public:
    Bird_two(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~Bird_two(){}
    void key();
    Bird_two*bird_friend;
};
#endif // BIRD_TWO

