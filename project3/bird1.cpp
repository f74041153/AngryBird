#include "bird1.h"
#include <gameitem.h>
Bird1::Bird1(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
{
    g_pixmap.setPixmap(pixmap);//inherit from gameitem QGrphicsPixmapItem
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
   // bodydef.bullet = true;//prevent from tunneling through other moving bodies
    bodydef.position.Set(x,y);
    bodydef.userData = this;//store application specific body data
    g_body = world->CreateBody(&bodydef);//inherit from gameitem
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);//damping阻尼
    g_body->CreateFixture(&fixturedef);

    // Bound timer()//timer parameter//mainwindow private data
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));//showout moving
    connect(timer, SIGNAL(timeout()), this,SLOT(collide()));
    scene->addItem(&g_pixmap);
    g_pixmap.setFocus();
}
void Bird1::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_K)
    {
      g_body->SetLinearVelocity(b2Vec2(10,10));
    }

}



