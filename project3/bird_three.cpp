#include "bird_three.h"
#include<iostream>

Bird_three::Bird_three(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(world)
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
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);
    g_pixmap.setFocus();
}
void Bird_three::key()
{
   bird_friend->g_body->ApplyLinearImpulse(b2Vec2(5000,0),bird_friend->g_body->GetPosition(),1);
}
