class Level
{
private:
    int n_players;
    int n_physical_objects;
    int n_living_objects;
    int n_cameras;
    Camera *camera;
    GraphicElement background;
    ALLEGRO_SAMPLE *bg_music;
public:
    LivingObject *player;
    PhysicalObject *physical_object;
    LivingObject *living_object;
    b2Vec2 gravity;
    b2World *world;
    //createWorld()
};
