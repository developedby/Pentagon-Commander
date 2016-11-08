class PhysicalObject : public GraphicElement
{
private:
    int id;
public:
    b2BodyDef body_def;
    b2Body *body;
    b2PolygonShape shape;
    b2FixtureDef fixture_def;
    void setId(int _id);
    //PhysicalObject();
    //~PhysicalObject();
};

void PhysicalObject::setId(int _id)
{
    id = _id;
}
