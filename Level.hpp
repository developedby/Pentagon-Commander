class Camera;
class Level
{
private:
    int n_players;
    int n_physical_objects;
    int n_living_objects;
    int n_cameras;
    ALLEGRO_SAMPLE *bg_music;
public:
    LivingObject *player;
    PhysicalObject *physical_object;
    LivingObject *living_object;
    b2Vec2 gravity;
    b2World *world;
    GraphicElement background;
    void createWorld();
    int getNPlayers();
    int getNPhysicalObjects();
    int getNLivingObjects();
    int getNCameras();
    void recordLevel();
    void setCameras(Camera **_camera);
    Camera **camera;
};

int Level::getNPlayers()
{
    return n_players;
}

int Level::getNPhysicalObjects()
{
    return n_physical_objects;
}

int Level::getNLivingObjects()
{
    return n_living_objects;
}

int Level::getNCameras()
{
    return n_cameras;
}

void Level::createWorld()
{
    world = new b2World(gravity);
}

void Level::setCameras(Camera **_camera)
{
    camera = _camera;
}
