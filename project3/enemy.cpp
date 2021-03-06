#include "enemy.h"
#include"block.h"
#include<typeinfo>
#include<iostream>
#include"mainwindow.h"
#include"score.h"
Enemy::Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);


    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;

    fixturedef.shape = &bodyshape;
    fixturedef.density =ENEMY_DENSITY ;
    fixturedef.friction = ENEMY_FRICTION;
    fixturedef.restitution = ENEMY_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
    QObject::connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    QObject::connect(timer, SIGNAL(timeout()), this,SLOT(remove()));
    scene->addItem(&g_pixmap);
    temp=0;
}
void Enemy::collide()
{
  //std::cout<<"piggy feels hurt!!!\n";
  temp++;
}
void Enemy::remove()
{
   if(temp==-1)
   {
      destroyed(this);
      delete this;
   }
}
