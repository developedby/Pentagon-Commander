#ifndef PHYSICALOBJECT
#define PHYSICALOBJECT

#include <pentagon_commander.hpp>
#include <GraphicElement.hpp>

class Level;

class PhysicalObject : public GraphicElement
{
private:
    unsigned int id;
public:
    void setId(int _id);
    b2BodyDef body_def;
    b2Body *body;
    b2CircleShape circle_shape;
    b2PolygonShape polygon_shape;
    b2FixtureDef fixture_def;
    virtual ~PhysicalObject(){};
};

void PhysicalObject::setId(int _id)
{
    id = _id;
}
#endif //PHYSICALOBJECT
