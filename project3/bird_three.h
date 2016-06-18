#ifndef BIRD_THREE
#define BIRD_THREE
#include"bird.h"
class Bird_three : public Bird
{
    Q_OBJECT;
public:
    Bird_three(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~Bird_three(){}
    void key();
    Bird_three*bird_friend;
};

#endif // BIRD_THREE

