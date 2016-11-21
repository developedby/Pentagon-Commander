#ifndef PHYSICALOBJECT
#define PHYSICALOBJECT
#endif //PHYSICALOBJECT

#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#include <PentagonCommander.hpp>
#endif //PENTAGONCOMMANDER_HPP

class Level;

class PhysicalObject : public GraphicElement
{
private:
    int id;
public:
    void setId(int _id);
    b2BodyDef body_def;
    b2Body *body;
    b2CircleShape circle_shape;
    b2PolygonShape polygon_shape;
    b2FixtureDef fixture_def;

    //PhysicalObject();
    //~PhysicalObject();
};

void PhysicalObject::setId(int _id)
{
    id = _id;
}
