#ifndef MY_CONTACT_LISTENER
#define MY_CONTACT_LISTENER
#include<Box2D/Box2D.h>
#include"block.h"
#include"enemy.h"
#include<iostream>
class My_contact_listener:public b2ContactListener
{
public:
   b2Body*ptr=NULL;

    virtual ~My_contact_listener()
    {
    }

    virtual void BeginContact(b2Contact* contact)
    {

    }
    void EndContact(b2Contact* contact)
    {

    }

     virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
    {
    }


    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
    {
        if(impulse->normalImpulses[0]>70)
        {
           if(contact->GetFixtureA()->GetBody()->GetFixtureList()->GetDensity()==12.0
&&contact->GetFixtureB()->GetBody()->GetFixtureList()->GetDensity()==10.0)
          {

             if(ptr!=contact->GetFixtureA()->GetBody())
             {
                  ptr=contact->GetFixtureA()->GetBody();
                  Enemy*e=(Enemy*)(contact->GetFixtureB()->GetBody()->GetUserData());
                  e->collide();

                  //std::cout<<impulse->normalImpulses[0]<<std::endl;
              }
           }
        }
    }
};


#endif // MY_CONTACT_LISTENER

