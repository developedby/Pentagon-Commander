#ifndef LIVINGOBJECT
#define LIVINGOBJECT

#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#include <PentagonCommander.hpp>
#endif //PENTAGONCOMMANDER_HPP

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
    int getMaxHp();
    LivingObject(){};
    LivingObject(int _max_hp, bool _alive);
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

int LivingObject::getMaxHp()
{
    return max_hp;
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