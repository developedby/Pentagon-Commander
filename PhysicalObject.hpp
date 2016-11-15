class PhysicalObject : public GraphicElement
{
private:
    int id;
public:
    void setId(int _id);
    b2BodyDef body_def;
    b2Body *body;
    b2PolygonShape shape;
    b2FixtureDef fixture_def;
    friend class Level;
    //PhysicalObject();
    //~PhysicalObject();
};

void PhysicalObject::setId(int _id)
{
    id = _id;
}
