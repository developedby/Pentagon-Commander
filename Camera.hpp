#ifndef CAMERA
#define CAMERA

#include <pentagon_commander.hpp>
#include <Level.hpp>

class Camera
{
private:
    b2Vec2 level_corner_position;
    b2Vec2 level_velocity;
    float px_x;
    float px_y;
    float px_width;
    float px_height;
    float m_width;
    float m_height;
    LivingObject *focused_player;
    Level *level;
    ALLEGRO_BITMAP *screen;
    GraphicElement background;
    GraphicElement *independent_elements;
    int n_independent_elements;
    void setLevel(Level *_level);
    void setWidthAndHeight(float _px_width, float _px_height);
    void setLvPos(b2Vec2 player_pos);
    void createScreen(float _px_x, float _px_y, float _px_width, float _px_height);
    void setNIndependentElements(int _n_independent_elements);
    void setIndependentElements(GraphicElement *_independent_elements);
    void setBackground();
    bool objectInterceptsCamera(PhysicalObject &object);
    void followPlayer();
public:
    float getPxWidth();
    float getPxHeight();
    void record();
    void play(ALLEGRO_DISPLAY *display);
    friend class Cameraman;
};

float Camera::getPxWidth()
{
    return px_width;
}

float Camera::getPxHeight()
{
    return px_height;
}

void Camera::setLevel(Level *_level)
{
    level = _level;
}

void Camera::setBackground()
{
    background.loadSprite(level->background_filename.c_str(), 1, px_width, px_height);
    background.setCorner(0, 0);
    background.setFlipFlag(0);
    background.setToBePrinted(true);

}

void Camera::followPlayer()
{
    b2Vec2 player_distance = focused_player->body->GetPosition() - (level_corner_position + b2Vec2(m_width/2, -m_height/2));
    if(player_distance.Length()>pixelsToMeters(1))
    {
        level_velocity = (player_max_speed)*player_distance;
    }
    else
        level_velocity = b2Vec2(0,0);
    level_corner_position = level_corner_position + level_velocity;
}

void Camera::setNIndependentElements(int _n_independent_elements)
{
    n_independent_elements = _n_independent_elements;
}

void Camera::setIndependentElements(GraphicElement *_independent_elements)
{
    independent_elements = _independent_elements;
}

void Camera::setLvPos(b2Vec2 player_pos)
{
    level_corner_position = player_pos;
}

void Camera::setWidthAndHeight(float _px_width, float _px_height)
{
    px_width = _px_width;
    px_height = _px_height;
    m_width = pixelsToMeters(px_width);
    m_height = pixelsToMeters(px_height);
}

void Camera::createScreen(float _px_x, float _px_y, float _px_width, float _px_height)
{
    px_x = _px_x;
    px_y = _px_y;
    px_width = _px_width;
    px_height = _px_height;
    m_width = pixelsToMeters(px_width);
    m_height = pixelsToMeters(px_height);
    screen = al_create_bitmap(px_width, px_height);
}

void Camera::play(ALLEGRO_DISPLAY *display)
{
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(screen, px_x, px_y, 0);
}

void Camera::record()
{
    int i;
    b2Vec2 body_pos, rect_dist;
    followPlayer();
    cout << "camera" << level_corner_position.x << ' ' << level_corner_position.y << endl;
    background.setDrawingTarget(screen);
    background.printOnScreen();
    for(i=0; i<level->getNPhysicalObjects(); i++)
    {
        if(objectInterceptsCamera(level->physical_object[i]))
        {
            body_pos = level->physical_object[i].body->GetPosition();
            rect_dist.x = metersToPixels(body_pos.x - level_corner_position.x);
            rect_dist.y = metersToPixels(level_corner_position.y - body_pos.y);
            level->physical_object[i].setCenter(rect_dist.x, rect_dist.y);
            level->physical_object[i].getCornerFromCenter();
            level->physical_object[i].setDrawingTarget(screen);
            level->physical_object[i].printOnScreen();
        }
    }
    for(i=0; i<level->getNLivingObjects(); i++)
    {

        if(objectInterceptsCamera(level->living_object[i]))
        {
            body_pos = level->living_object[i].body->GetPosition();
            rect_dist.x = metersToPixels(body_pos.x - level_corner_position.x);
            rect_dist.y = metersToPixels(level_corner_position.y - body_pos.y);
            level->living_object[i].setCenter(rect_dist.x, rect_dist.y);
            level->living_object[i].getCornerFromCenter();
            level->living_object[i].setDrawingTarget(screen);
            level->living_object[i].printOnScreen();
        }
    }
    for(i=0; i<level->getNPlayers(); i++)
    {

        if(objectInterceptsCamera(level->player[i]))
        {
            body_pos = level->player[i].body->GetPosition();
            rect_dist.x = metersToPixels(body_pos.x - level_corner_position.x);
            rect_dist.y = metersToPixels(level_corner_position.y - body_pos.y);
            level->player[i].setCenter(rect_dist.x, rect_dist.y);
            level->player[i].getCornerFromCenter();
            level->player[i].setDrawingTarget(screen);
            level->player[i].printOnScreen();
        }
    }
    for(i=0; i<n_independent_elements; i++)
    {
        independent_elements[i].setDrawingTarget(screen);
        independent_elements[i].printOnScreen();
    }
}


// Returns true if any point of the object is inside the camera's view. Otherwise, return false
bool Camera::objectInterceptsCamera(PhysicalObject &object)
{
    b2Transform obj_t = object.body->GetTransform();
    // Assuming each body is using only 1 fixture (as done in loadLevel)
    b2AABB obj_aabb;
    b2Fixture *obj_fixture = object.body->GetFixtureList();
    const b2Shape *obj_shape = obj_fixture->GetShape();
    const int childCount = obj_shape->GetChildCount();
    // Calculate the fixture's AABB
    for (int child = 0; child<childCount; ++child)
    {
        b2AABB shapeAABB;
        obj_shape->ComputeAABB(&shapeAABB, obj_t, child);
        obj_aabb.Combine(shapeAABB);
    }

    // If the AABBs intercept
    if(obj_aabb.upperBound.x > level_corner_position.x)
        if(obj_aabb.upperBound.y > level_corner_position.y - m_height) //Y grows up
            if(obj_aabb.lowerBound.x < level_corner_position.x + m_width) //X grows right
                if(obj_aabb.lowerBound.y < level_corner_position.y)
                    return true;
    return false;
}
#endif //CAMERA
