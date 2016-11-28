#ifndef BEHAVIORS
#define BEHAVIORS

#include <pentagon_commander.hpp>
#include <Level.hpp>
#include <LivingObject.hpp>
#include <PhysicalObject.hpp>

class Behavior
{
protected:
    PhysicalObject* object;
public:
    virtual void behave() = 0;
};

class Walk : virtual public Behavior
{
protected:
    b2Vec2 walk_velocity;PhysicalObject* object;
public:
    Walk(b2Vec2 _walk_velocity, PhysicalObject* _object)
    {
        walk_velocity = _walk_velocity;
        object = _object;
    }
    virtual void behave()
    {
        walk();
    }
    virtual void walk()
    {
        object->body->SetLinearVelocity(walk_velocity);
    }
};

class WalkAround : virtual public Walk
{
protected:
    b2Vec2 walk_velocity1;
    b2Vec2 walk_velocity2;
    unsigned int turn_counter;
    unsigned int turn_counter_frames;
    unsigned int turn_lowerbound;
    unsigned int turn_upperbound;
    bool turn_current_state;
public:
    WalkAround(b2Vec2 _walk_velocity1, b2Vec2 _walk_velocity2, PhysicalObject* _object, int lb, int ub) : Walk(_walk_velocity1, _object)
    {
        turn_current_state = true;
        turn_lowerbound = lb;
        turn_upperbound = ub;
        walk_velocity1 = _walk_velocity1;
        walk_velocity2 = _walk_velocity2;
        turn_counter = 0;
        turn_counter_frames = rand()%(turn_upperbound - turn_lowerbound) + turn_lowerbound;
        walk();
    }
    virtual void behave()
    {
        turn_counter++;
        if(turn_counter == turn_counter_frames)
        {
            turn_current_state = !turn_current_state;
            turn_counter = 0;
            turn_counter_frames = rand()%(turn_upperbound - turn_lowerbound) + turn_lowerbound;
        }
        walk();
    }
    virtual void walk()
    {
        if(turn_current_state)
            object->body->SetLinearVelocity(walk_velocity1);
        else
            object->body->SetLinearVelocity(walk_velocity2);
    }
};

class WalkAndStop : virtual public Walk
{
protected:
    unsigned int stop_counter;
    unsigned int stop_counter_frames;
    unsigned int stop_lowerbound;
    unsigned int stop_upperbound;
    bool stop_current_state;
public:
    WalkAndStop(b2Vec2 _walk_velocity, PhysicalObject* _object, int lb, int ub) : Walk(_walk_velocity, _object)
    {
        stop_current_state = true;
        stop_lowerbound = lb;
        stop_upperbound = ub;
        stop_counter = 0;
        stop_counter_frames = rand()%(stop_upperbound - stop_lowerbound) + stop_lowerbound;
        walk();
    }
    virtual void behave()
    {
        stop_counter++;
        if(stop_counter == stop_counter_frames)
        {
            stop_current_state = !stop_current_state;
            stop_counter = 0;
            stop_counter_frames = rand()%(stop_upperbound - stop_lowerbound) + stop_lowerbound;
        }
        walk();
    }
    virtual void walk()
    {
        if(stop_current_state)
            object->body->SetLinearVelocity(walk_velocity);
        else
            object->body->SetLinearVelocity(b2Vec2(0,0));
    }
};

class WalkRandomly : virtual public WalkAround, virtual public WalkAndStop
{
protected:
    unsigned int random_counter;
    unsigned int random_counter_frames;
    unsigned int random_lowerbound;
    unsigned int random_upperbound;
    bool random_current_state;
public:
    WalkRandomly(b2Vec2 _walk_velocity1, b2Vec2 _walk_velocity2, PhysicalObject* _object, int lb, int ub) :
        Walk(_walk_velocity1, _object),
        WalkAround(_walk_velocity1,_walk_velocity2, _object, lb, ub),
        WalkAndStop(_walk_velocity1, _object, lb, ub)
    {
        random_current_state = true;
        random_lowerbound = lb;
        random_upperbound = ub;
        random_counter = 0;
        random_counter_frames = rand()%(random_upperbound - random_lowerbound) + random_lowerbound;
        stop_current_state = false;
        WalkAround::walk();
    }
    virtual void behave()
    {
        random_counter++;
        if(random_counter == random_counter_frames)
        {
            random_counter_frames = rand()%(random_upperbound - random_lowerbound) + random_lowerbound;
            random_current_state = !random_current_state;
            random_counter = 0;
        }
        walk();
    }
    void walk()
    {
        if(random_current_state)
        {
            turn_counter++;
            if(turn_counter == turn_counter_frames)
            {
                turn_current_state = !turn_current_state;
                turn_counter = 0;
                turn_counter_frames = rand()%(turn_upperbound - turn_lowerbound) + turn_lowerbound;
            }
            WalkAround::walk();
        }
        else
        {
            WalkAndStop::walk();
        }
    }
};

class Animation : public Behavior
{
protected:
    int n_sprites;
    int next_sprite;
public:
    Animation(int _n_sprites, PhysicalObject* _object)
    {
        object = _object;
        n_sprites = _n_sprites;
        next_sprite = -1;
    }
    virtual void behave()
    {
        animate();
    }
    virtual void animate()
    {
        if(next_sprite>=0 && next_sprite<n_sprites)
            object->setCurrentSprite(next_sprite);
    }
};

class CyclicalAnimation : public Animation ///MAKE CYCLICAL ANIMATION ONLY USE CERTAIN SPRITES
{
protected:
    int current_sprite;
    unsigned int animation_counter;
    unsigned int *sprite_frames;
public:
    CyclicalAnimation(unsigned int *_sprite_frames, int _n_sprites, PhysicalObject* _object, int _current_sprite) : Animation(_n_sprites, _object)
    {
        animation_counter = 0;
        current_sprite = _current_sprite;
        sprite_frames = _sprite_frames;
    }
    virtual void behave()
    {
        animate();
    }
    virtual void animate()
    {
        animation_counter++;
        if(animation_counter == sprite_frames[current_sprite])
        {
            if(current_sprite == n_sprites-1)
            {
                next_sprite = 0;
                Animation::animate();
                current_sprite = 0;
            }
            else
            {
                next_sprite = current_sprite+1;
                Animation::animate();
                current_sprite++;
            }
            animation_counter = 0;
        }
    }
};

class Damage : public Behavior
{
protected:
    int damage;
    LivingObject* l_object;
public:
    Damage(int _damage, PhysicalObject* _object)
    {
        object = _object;
        l_object = static_cast <LivingObject*> (object);
    }
    virtual void behave()
    {
        l_object->addHp(-damage);
        if(l_object->getHp() <= 0)
        {
            l_object->setAlive(false);
        }
    }
};

#endif //BEHAVIORS
