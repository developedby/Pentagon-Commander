#ifndef CONTACT_LISTENER
#define CONTACT LISTENER

#include <pentagon_commander.hpp>
#include <LivingObject.hpp>
#include <Level.hpp>

class ContactListener : public b2ContactListener
{
public:
    ContactListener(){}
    void BeginContact(b2Contact* contact)
    {
        if(contact->IsTouching())
        {
            b2Fixture* fix_a = contact->GetFixtureA();
            b2Fixture* fix_b = contact->GetFixtureB();
            b2Body *body_a = fix_a->GetBody();
            b2Body *body_b = fix_b->GetBody();
            PhysicalObject *phys_a = (PhysicalObject*)body_a->GetUserData();  //ADICIONAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            PhysicalObject *phys_b = (PhysicalObject*)body_b->GetUserData();
            if(phys_a->getId()==e_player || phys_b->getId()==e_player)
            {
                if(phys_a->getId() == e_enemy1 || phys_b->getId() == e_enemy1)
                {
                    gameOver();
                }
            }
        }
    }
 /*void EndContact(b2Contact* contact)
 { }
 void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
 { }
 void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
 { }*/
};

#endif // CONTACT_LISTENER
