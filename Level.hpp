#ifndef LEVEL
#define LEVEL
#endif // LEVEL
using namespace std;

//useless comment

enum shape_type{POLYGON=0,BOX,CIRCLE};
enum body_type{DYNAMIC=0,STATIC,KINEMATIC};
const int player_default_hp = 1;
const int n_commands = 0;

#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#include <PentagonCommander.hpp>
#endif //PENTAGONCOMMANDER_HPP

#ifndef LIVINGOBJECT
#define LIVINGOBJECT
#include <LivingObject.hpp>
#endif // LIVINGOBJECT

class Level
{
private:
    string name;
    int n_players;
    int n_physical_objects;
    int n_living_objects;
    int n_cameras;
    ALLEGRO_SAMPLE *bg_music;
    void loadPhysicalObject(ifstream *file,PhysicalObject *object,int n);
    void createWorld();
    void setName(string _name);
    void setNPlayers(int _n_players);
    void setNPhysicalObjects(int _n_physical_objects);
    void setNLivingObjects(int _n_living_objects);
    void setNCameras(int _n_cameras);
    bool available_command[n_commands];
    Level(){};
public:
    virtual ~Level();
    LivingObject *player;
    PhysicalObject *physical_object;
    LivingObject *living_object;
    b2AABB objective_area;
    b2Vec2 gravity;
    b2World *world;
    string background_filename;
    int getNPlayers();
    int getNPhysicalObjects();
    int getNLivingObjects();
    int getNCameras();
    string getName();
    static Level* loadLevel(const char* filename);
};

Level::~Level()
{
    delete world;
    delete[] physical_object;
    delete[] living_object;
    delete[] player;
}


void Level::createWorld()
{
    world = new b2World(gravity);
}

void Level::setNPlayers(int _n_players)
{
    n_players = _n_players;
}

void Level::setNPhysicalObjects(int _n_physical_objects)
{
    n_physical_objects = _n_physical_objects;
}

void Level::setNLivingObjects(int _n_living_objects)
{
    n_living_objects = _n_living_objects;
}

void Level::setNCameras(int _n_cameras)
{
    n_cameras = _n_cameras;
}

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

void Level::setName(string _name)
{
    name = _name;
}

string Level::getName()
{
    return name;
}

Level* Level::loadLevel(const char* filename)
{
    ifstream file;
    Level *level;
    string string_register;
    float float_register;
    int int_register,int_register2,i;

    level = new Level();
    file.open(filename);

    file >> string_register;
    level->setName(string_register);

    file >> float_register;
    level->gravity.x = float_register;

    file >> float_register;
    level->gravity.y = float_register;

    level->createWorld();

    //add flags or not

    //add music

    file >> string_register;
    level->background_filename = string_register;

    file >> float_register;
    level->objective_area.upperBound.x = float_register;
    file >> float_register;
    level->objective_area.upperBound.y = float_register;
    file >> float_register;
    level->objective_area.lowerBound.x = float_register;
    file >> float_register;
    level->objective_area.lowerBound.y = float_register;

    file >> int_register;
    level->setNPlayers(int_register);
    if(int_register)
        level->player = new LivingObject[level->getNPlayers()];

    for(i=0;i<int_register;i++)
    {
        level->player[i].setMaxHp(player_default_hp);
        level->player[i].setAlive(true);
        level->loadPhysicalObject(&file,level->player,i);
    }

    file >> int_register;
    level->setNLivingObjects(int_register);
    if(int_register)
        level->living_object = new LivingObject[level->getNLivingObjects()];

    for(i=0;i<int_register;i++)
    {
        file >> int_register2;
        level->living_object[i].setMaxHp(int_register2);
        file >> int_register2;
        level->living_object[i].setAlive(int_register2);
        level->loadPhysicalObject(&file,level->living_object,i);
    }

    file >> int_register;
    level->setNPhysicalObjects(int_register);
    if(int_register)
        level->physical_object = new PhysicalObject[level->getNPhysicalObjects()];

    for(i=0;i<int_register;i++)
    {
        level->loadPhysicalObject(&file,level->physical_object,i);
    }

    file >> int_register;
    level->setNCameras(int_register);

    for(i=0; i<n_commands; i++)
    {
        file >> int_register;
        level->available_command[i] = int_register;
    }

    file.close();
    return level;
}

void Level::loadPhysicalObject(ifstream *file, PhysicalObject *object, int n)
{
    int shapetype, i, int_register;
    float float_register, float_register2;
    unsigned short ushort_register;
    string string_register;

    // Loads body
    (*file) >> int_register;
    object->setId(int_register);

    (*file) >> int_register;
    switch(int_register)
    {
        case DYNAMIC:
            object->body_def.type = b2_dynamicBody;
            break;
        case STATIC:
            object->body_def.type = b2_staticBody;
            break;
        case KINEMATIC:
            object->body_def.type = b2_kinematicBody;
            break;
    }

    (*file) >> float_register;
    (*file) >> float_register2;
    object->body_def.position.Set(float_register, float_register2);

    (*file) >> float_register;
    object->body_def.angle = float_register;

    (*file) >> float_register;
    object->body_def.linearDamping = float_register;

    (*file) >> float_register;
    object->body_def.angularDamping = float_register;

    (*file) >> float_register;
    object->body_def.gravityScale = float_register;

    (*file) >> int_register;
    object->body_def.allowSleep = int_register;

    (*file) >> int_register;
    object->body_def.awake = int_register;

    (*file) >> int_register;
    object->body_def.fixedRotation = int_register;

    (*file) >> int_register;
    object->body_def.bullet = int_register;

    (*file) >> int_register;
    object->body_def.active = int_register;

    object->body = world->CreateBody(&(object->body_def));

    // Loads shape
    (*file) >> shapetype;

    switch(shapetype)
    {
        case POLYGON:
        {
            int n_polygon_vertices;
            b2Vec2 *polygon_vertice;
            (*file) >> n_polygon_vertices;
            polygon_vertice = new b2Vec2[n_polygon_vertices];
            for(i=0; i<n_polygon_vertices; i++)
            {
                (*file) >> float_register;
                polygon_vertice[i].x = float_register;
                (*file) >> float_register;
                polygon_vertice[i].y = float_register;
            }
            object->polygon_shape.Set(polygon_vertice, n_polygon_vertices);
            object->fixture_def.shape = &object->polygon_shape;
            delete[] polygon_vertice;
        }
        break;
        case BOX:
        {
            float half_width, half_height;
            (*file) >> half_width;
            (*file) >> half_height;
            object->polygon_shape.SetAsBox(half_width, half_height);
            object->fixture_def.shape = &object->polygon_shape;
        }
        break;
        case CIRCLE:
        {
            float radius;
            (*file) >> radius;
            object->circle_shape.m_radius = radius;
            object->fixture_def.shape = &object->circle_shape;
        }
        break;
    }

    //Loads fixture
    (*file) >> float_register;
    object->fixture_def.density = float_register;

    (*file) >> float_register;
    object->fixture_def.friction = float_register;

    (*file) >> float_register;
    object->fixture_def.restitution = float_register;

    (*file) >> ushort_register;
    object->fixture_def.filter.categoryBits = ushort_register;

    (*file) >> ushort_register;
    object->fixture_def.filter.maskBits = ushort_register;

    object->body->CreateFixture(&(object->fixture_def));

    (*file) >> string_register;
    const char *sprite_filename = string_register.c_str();
    (*file) >> int_register; //Number of Sprites
    (*file) >> float_register; //Sprite width
    (*file) >> float_register2; //Sprite height
    object->loadSprite(sprite_filename, int_register, float_register, float_register2);

    (*file) >> int_register;
    object->setToBePrinted(int_register);
}
