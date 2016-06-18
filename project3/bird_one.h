#ifndef BIRD_ONE
#define BIRD_ONE

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include<QKeyEvent>
#include"bird.h"
class Bird_one : public Bird
{
    Q_OBJECT;
public:
    Bird_one(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~Bird_one(){};
     void key();


};
#endif // BIRD_ONE

