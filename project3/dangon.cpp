#include "dangon.h"
#include"enemy.h"
Dangon::Dangon(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);//inherit from gameitem QGrphicsPixmapItem
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.bullet = true;//prevent from tunneling through other moving bodies
    bodydef.position.Set(x,y);
    bodydef.userData = this;//store application specific body data

    g_body = world->CreateBody(&bodydef);//inherit from gameitem

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(0.5,1.0);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 8.0;
    fixturedef.friction = 0.5;
    fixturedef.restitution = 0;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
