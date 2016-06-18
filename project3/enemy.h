#ifndef ENEMY
#define ENEMY

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include<QObject>
#include"block.h"

#define ENEMY_DENSITY 10.0f
#define ENEMY_FRICTION 5.0f
#define ENEMY_RESTITUTION 0.5f
class Enemy : public GameItem
{
    Q_OBJECT
public:
    Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    int temp;

public slots:
    void collide();
    void remove();


};


#endif // ENEMY

