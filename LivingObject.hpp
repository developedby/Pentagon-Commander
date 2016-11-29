#ifndef LIVINGOBJECT
#define LIVINGOBJECT

#include <pentagon_commander.hpp>
#include <PhysicalObject.hpp>

class LivingObject : public PhysicalObject
{
private:
    int max_hp;
    int hp;
    bool alive;
public:
    void addHp(int dhp);
    void setAlive(bool _alive);
    bool getAlive();
    void setMaxHp(int _max_hp);
    void setMaxHp(int _max_hp, int _hp);
    int getMaxHp();
    LivingObject(){};
    LivingObject(int _max_hp, bool _alive);
    int getHp();
    virtual ~LivingObject(){};
    void operator= (bool state)
    {
        alive = state;
    }
};

LivingObject::LivingObject(int _max_hp, bool _alive)
{
    max_hp = _max_hp;
    hp = max_hp;
    alive = _alive;
}

void LivingObject::setMaxHp(int _max_hp)
{
    max_hp = _max_hp;
}

void LivingObject::setMaxHp(int _max_hp, int _hp)
{
    max_hp = _max_hp;
    hp = _hp;
}


int LivingObject::getMaxHp()
{
    return max_hp;
}

int LivingObject::getHp()
{
    return hp;
}

void LivingObject::addHp(int dhp)
{
    hp += dhp;
    if(hp <= 0)
        alive = 0;
}

void LivingObject::setAlive(bool _alive)
{
    alive = _alive;
}

bool LivingObject::getAlive()
{
    return alive;
}
#endif // LIVINGOBJECT
